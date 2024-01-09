#include "Cliente.hpp"

Cliente::Cliente(std::string cpf, std::string nome){
    this->cpf = cpf;
    this->nome = nome;
}

std::string Cliente::get_cpf(){
    return this->cpf;
}

std::string Cliente::get_nome(){
    return this->nome;
}

int calcular_idade(){
    #define FORMATO_DATA "%d/%m/%Y"
    time_t agora = time(NULL);
    struct tm* atual = localtime(&agora);
    struct tm niver;
    int idade;

    std::cin >> std::get_time(&niver, FORMATO_DATA);

    idade = atual->tm_year - niver.tm_year;

    if(atual->tm_mon < niver.tm_mon){
        idade--;
    } else if (atual->tm_mon == niver.tm_mon and atual->tm_mday < niver.tm_mday){
        idade--;
    }

    return idade;
}