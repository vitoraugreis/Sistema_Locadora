#include "Cliente.hpp"
#include <iostream>

int main(){
    Cliente g = Cliente("123", "456");
    std::cout << g.get_nome() << std::endl << g.get_cpf() << std::endl;
    return 0;
}