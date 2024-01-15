#ifndef SISTEMA_CLIENTES_H
#define SISTEMA_CLIENTES_H

#include "Cliente.hpp"
#include "ClientesExceptions.hpp"

#include <iostream>
#include <string>
#include <list>

class SistemaClientes{
private:
    std::list<Cliente*> clientes;
public:
    SistemaClientes();
    bool cadastrar_cliente();
    Cliente* pesquisar_cliente(std::string cpf);
};

bool verificacao_cpf(SistemaClientes* sistema, std::string cpf);
bool verificacao_data_nascimento(struct tm* data_nascimento);

#endif