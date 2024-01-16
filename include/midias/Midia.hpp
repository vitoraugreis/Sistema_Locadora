#ifndef MIDIA_H
#define MIDIA_H

#include <string>

class Midia{
private:
    static int total_midias;
    int codigo;
    std::string titulo;
    std::string genero;
    int idade_indicada;
    int quantidade_disponivel;
public:
    Midia(std::string titulo, std::string genero, int idade_indicada, int quantidade_disponivel);
    virtual bool atualizar_cadastro() = 0;
    int get_total_midias();
    int get_codigo();
    std::string get_titulo();
    std::string get_genero();
    int get_idade_indicada();
    int get_quantidade_disponivel();
};

#endif