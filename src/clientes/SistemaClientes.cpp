#include "SistemaClientes.hpp"

SistemaClientes::SistemaClientes(){
    this->clientes.clear();
}

bool SistemaClientes::cadastrar_cliente(){
    std::string cpf;
    std::cout << "Insira o cpf do cliente: "; std::cin >> cpf;
    this->validar_cpf(cpf);

    std::string nome;
    std::cout << "Insira o nome do cliente: "; std::cin >> nome;

    struct tm data_nascimento;
    std::cout << "Insira a data de nascimento do cliente (dd/mm/aaaa): ";
    std::cin >> std::get_time(&data_nascimento, FORMATO_DATA);
    data_nascimento.tm_hour = 0; data_nascimento.tm_min = 0; data_nascimento.tm_sec = 0;
    this->validar_data_nascimento(&data_nascimento);

    Cliente* cliente = new Cliente(cpf, nome, data_nascimento);
    this->clientes.push_back(cliente);
    return true;
}

bool SistemaClientes::deletar_cliente(std::string cpf){
    for(auto it = this->clientes.begin(); it != this->clientes.end(); it++){
        if((*it)->get_cpf() == cpf){
            delete *it;
            this->clientes.erase(it);
            std::cout << "Cliente deletado com sucesso." << std::endl;
            return true;
        }
    }

    throw clientes_excp::cliente_inexistente();
}

bool SistemaClientes::atualizar_cadastro(std::string cpf){
    Cliente* cliente = this->pesquisar_cliente(cpf);
    if(cliente == nullptr){
        throw clientes_excp::cliente_inexistente();
    }

    char confirmacao_alterar_nome;
    std::cout << "Deseja alterar o nome do cliente? ('s' ou 'n'): "; std::cin >> confirmacao_alterar_nome;
    if(confirmacao_alterar_nome == 's'){
        std::string novo_nome;
        std::cout << "Insira o nome do cliente: "; std::cin >> novo_nome;
        cliente->set_nome(novo_nome);
        std::cout << "Nome atualizado com sucesso!" << std::endl;
    }

    char confirmacao_alterar_data_nascimento;
    std::cout << "Deseja alterar o nome do cliente? ('s' ou 'n'): "; std::cin >> confirmacao_alterar_data_nascimento;
    if(confirmacao_alterar_data_nascimento == 's'){
        struct tm nova_data_nascimento;
        std::cout << "Insira a data de nascimento do cliente (dd/mm/aaaa): ";
        std::cin >> std::get_time(&nova_data_nascimento, FORMATO_DATA);
        nova_data_nascimento.tm_hour = 0; nova_data_nascimento.tm_min = 0; nova_data_nascimento.tm_sec = 0;
        this->validar_data_nascimento(&nova_data_nascimento);
        cliente->set_data_nascimento(&nova_data_nascimento);
        std::cout << "Data de nascimento atualizada com sucesso!" << std::endl;
    }

    return true;
}

Cliente* SistemaClientes::pesquisar_cliente(std::string cpf){
    for (Cliente* cliente : this->clientes){
        if (cliente->get_cpf() == cpf){
                return cliente;
        }
    }
    return nullptr;
}

void SistemaClientes::listar_clientes(){
    std::string separacao = "";
    for(int i = 0; i<60; i++){ separacao += "="; }

    if(this->clientes.empty()){
        std::cout << "Nao ha clientes cadastrados." << std::endl;
        return;
    }

    for(Cliente* cliente : this->clientes){
        char buffer[11]; 
        strftime(buffer, 11, "%d/%m/%Y", cliente->get_data_nascimento());

        std::cout << "Nome: " << cliente->get_nome() << std::endl;
        std::cout << "Cpf: " << cliente->get_cpf() << std::endl;
        std::cout << "Data de nascimento: " << buffer << std::endl;

        std::cout << separacao << std::endl;
    }
}

bool SistemaClientes::validar_cpf(std::string cpf){
    if(cpf.length() != 11){
        throw clientes_excp::cpf_tamanho_invalido();
    }
    for (char c : cpf){
        if (c < '0' or c > '9'){
            throw clientes_excp::cpf_caractere_invalido();
        }
    }
    if (this->pesquisar_cliente(cpf) != nullptr){
        throw clientes_excp::cpf_existente();
    }

    return true;
}

bool SistemaClientes::validar_data_nascimento(struct tm* data_nascimento){
    time_t horario_atual_bruta = time(NULL);
    time_t data_nascimento_bruta = mktime(data_nascimento);

    if(horario_atual_bruta - data_nascimento_bruta < 0){
        throw clientes_excp::data_nascimento_no_futuro();
    }

    return true;
}