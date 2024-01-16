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

    bool validar_cpf(std::string cpf);
    bool validar_data_nascimento(struct tm* data_nascimento);

public:
    SistemaClientes();
    bool cadastrar_cliente();
    bool atualizar_cadastro(std::string cpf);
    bool deletar_cliente(std::string cpf);
    Cliente* pesquisar_cliente(std::string cpf);
    void listar_clientes();
};

#endif