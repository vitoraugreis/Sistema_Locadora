#include "SistemaClientes.hpp"

SistemaClientes::SistemaClientes(){
    this->clientes.clear();
}

bool SistemaClientes::cadastrar_cliente(){
    std::string cpf;
    std::cout << "Insira o cpf do cliente: "; std::cin >> cpf;
    verificacao_cpf(this, cpf);

    std::string nome;
    std::cout << "Insira o nome do cliente: "; std::cin >> nome;

    struct tm data_nascimento;
    std::cout << "Insira a data de nascimento do cliente (dd/mm/aaaa): ";
    std::cin >> std::get_time(&data_nascimento, FORMATO_DATA);
    data_nascimento.tm_hour = 0; data_nascimento.tm_min = 0; data_nascimento.tm_sec = 0;
    verificacao_data_nascimento(&data_nascimento);

    Cliente* cliente = new Cliente(cpf, nome, data_nascimento);
    this->clientes.push_back(cliente);
}

Cliente* SistemaClientes::pesquisar_cliente(std::string cpf){
    for (Cliente* cliente : this->clientes){
        if (cliente->get_cpf() == cpf){
                return cliente;
        }
    }
    return nullptr;
}

bool verificacao_cpf(SistemaClientes* sistema, std::string cpf){
    if(cpf.length() != 11){
        throw clientes_excp::cpf_tamanho_invalido();
    }
    for (char c : cpf){
        if (c < '0' or c > '9'){
            throw clientes_excp::cpf_caractere_invalido();
        }
    }
    if (sistema->pesquisar_cliente(cpf) != nullptr){
        throw clientes_excp::cpf_existente();
    }

    return true;
}

bool verificacao_data_nascimento(struct tm* data_nascimento){
    time_t horario_atual_bruta = time(NULL);
    time_t data_nascimento_bruta = mktime(data_nascimento);

    if(horario_atual_bruta - data_nascimento_bruta < 0){
        throw clientes_excp::data_nascimento_no_futuro();
    }

    return true;
}
