#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <list>

class Cliente{
private:
    std::string cpf;
    std::string nome;
    struct tm data_nascimento;
    int idade;
    // midias alugadas
    // historico
public:
    Cliente(std::string cpf, std::string nome);
    std::string get_cpf();
    std::string get_nome();
    int get_idade();
};

#endif