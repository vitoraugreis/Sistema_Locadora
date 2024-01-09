#include "Cliente.hpp"
#include <iostream>

int main(){
    Cliente g = Cliente("123", "456");
    std::cout << g.get_nome() << std::endl;

    return 0;
}