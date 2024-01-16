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

    bool verificacao_cpf(std::string cpf);
    bool verificacao_data_nascimento(struct tm* data_nascimento);

public:
    SistemaClientes();
    bool cadastrar_cliente();
    bool deletar_cliente(std::string cpf);
    Cliente* pesquisar_cliente(std::string cpf);
    void listar_clientes();
};

#endif