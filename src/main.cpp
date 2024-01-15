#include "SistemaClientes.hpp"
#include <iostream>

int main(){
    SistemaClientes sistema;
    try{
        sistema.cadastrar_cliente();
        std::cout << sistema.pesquisar_cliente("12345678999")->calcular_idade() << std::endl;
        sistema.listar_clientes();
        sistema.deletar_cliente("12345678999");
        sistema.listar_clientes();
        sistema.deletar_cliente("09316113695");
    } catch(clientes_excp::cpf_tamanho_invalido &e){
        std::cerr << e.what() << std::endl;
    } catch(clientes_excp::cpf_caractere_invalido &e){
        std::cerr << e.what() << std::endl;
    } catch(clientes_excp::cpf_existente &e){
        std::cerr << e.what() << std::endl;
    } catch(clientes_excp::data_nascimento_no_futuro &e){
        std::cerr << e.what() << std::endl;
    } catch(clientes_excp::cliente_inexistente &e){
        std::cerr << e.what() << std::endl;
    } 
    return 0;
}