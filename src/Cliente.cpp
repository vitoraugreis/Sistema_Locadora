#include "../include/Cliente.hpp"

Cliente::Cliente(std::string cpf, std::string nome){
    this->cpf = cpf;
    this->nome = nome;
}

std::string Cliente::get_cpf(){
    return this->cpf;
}

std::string Cliente::get_nome(){
    return this->nome;
}