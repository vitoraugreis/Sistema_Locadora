#include "Midia.hpp"

int Midia::total_midias = 0;

Midia::Midia(std::string titulo, std::string genero, int idade_indicada, int quantidade_disponivel){
    Midia::total_midias++;
    this->codigo = Midia::total_midias;
    this->titulo = titulo;
    this->genero = genero;
    this->idade_indicada = idade_indicada;
    this->quantidade_disponivel = quantidade_disponivel;
}

int Midia::get_total_midias(){
    return Midia::total_midias;
}

int Midia::get_codigo(){
    return this->codigo;
}