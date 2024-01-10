#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <list>

#define FORMATO_DATA "%d/%m/%Y"

class Cliente{
private:
    std::string cpf;
    std::string nome;
    struct tm data_nascimento;
    // midias alugadas
    // historico
public:
    Cliente(std::string cpf, std::string nome, struct tm data_nascimento);
    std::string get_cpf();
    std::string get_nome();
    struct tm* get_data_nascimento();
};

#endif