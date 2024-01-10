#include "Cliente.hpp"

Cliente::Cliente(std::string cpf, std::string nome, struct tm data_nascimento){
    this->cpf = cpf;
    this->nome = nome;
    this->data_nascimento = data_nascimento;
}

std::string Cliente::get_cpf(){
    return this->cpf;
}

std::string Cliente::get_nome(){
    return this->nome;
}

struct tm* Cliente::get_data_nascimento(){
    return &this->data_nascimento;
}

int calcular_idade(){
    time_t agora = time(NULL);
    struct tm* atual = localtime(&agora);
    struct tm niver;
    int idade;

    std::cin >> std::get_time(&niver, FORMATO_DATA);

    idade = atual->tm_year - niver.tm_year;

    if(atual->tm_mon < niver.tm_mon){
        idade--;
    } else if (atual->tm_mon == niver.tm_mon and atual->tm_mday < niver.tm_mday){
        idade--;
    }

    return idade;
}