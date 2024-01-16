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
    // midias alugadas -> list de midias
    // historico -> map: (key: date) : (value: list de midias)
public:
    Cliente(std::string cpf, std::string nome, struct tm data_nascimento);
    int calcular_idade();
    std::string get_cpf();
    std::string get_nome();
    struct tm* get_data_nascimento();
    void set_nome(std::string nome);
    void set_data_nascimento(struct tm* data_nascimento);
    ~Cliente();
};

#endif