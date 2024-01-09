#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <list>

class Cliente{
private:
    std::string cpf;
    std::string nome;
    // data de nascimento
    // midias alugadas
    // historico
public:
    Cliente(std::string cpf, std::string nome);
    std::string get_cpf();
    std::string get_nome();
};

#endif