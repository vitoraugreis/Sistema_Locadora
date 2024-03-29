#include <exception>

namespace clientes_excp{

class cpf_tamanho_invalido : public std::exception{
public:
    virtual const char* what() const throw(){
        return "ERRO: Cpf deve conter 11 numeros.";
    }
};

class cpf_caractere_invalido : public std::exception{
public:
    virtual const char* what() const throw(){
        return "ERRO: Cpf deve conter apenas numeros.";
    }
};

class cpf_existente : public std::exception{
public:
    virtual const char* what() const throw(){
        return "ERRO: Cpf ja foi cadastrado no sistema.";
    }
};

class data_nascimento_no_futuro : public std::exception{
public:
    virtual const char* what() const throw(){
        return "ERRO: Data de nascimento invalida.";
    }
};

class cliente_inexistente : public std::exception{
public:
    virtual const char* what() const throw(){
        return "ERRO: Cliente inexistente.";
    }
};

}