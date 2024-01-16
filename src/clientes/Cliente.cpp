#include "Cliente.hpp"

Cliente::Cliente(std::string cpf, std::string nome, struct tm data_nascimento){
    this->cpf = cpf;
    this->nome = nome;
    this->data_nascimento = data_nascimento;
}

int Cliente::calcular_idade(){
    time_t horario_atual_bruto;
    struct tm* horario_atual;
    int idade;

    time(&horario_atual_bruto);
    horario_atual = localtime(&horario_atual_bruto);

    idade = horario_atual->tm_year - this->data_nascimento.tm_year;

    if(horario_atual->tm_mon < this->data_nascimento.tm_mon){
        idade--;
    } else if (horario_atual->tm_mon == this->data_nascimento.tm_mon and horario_atual->tm_mday < this->data_nascimento.tm_mday){
        idade--;
    }

    return idade;
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

Cliente::~Cliente(){
    std::cout << this->cpf << " deletado (Destrutor)" << std::endl;
}