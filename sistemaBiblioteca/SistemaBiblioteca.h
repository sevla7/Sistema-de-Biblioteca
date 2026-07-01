#ifndef SISTEMABIBLIOTECA_H
#define SISTEMABIBLIOTECA_H

#include <vector>
#include <string>
#include "..\Reserva\Reserva.h"

class SistemaBiblioteca {
private:
    std::vector<Reserva*> reservas;

public:
    SistemaBiblioteca();
    ~SistemaBiblioteca();
    
    void iniciar(); // Inicia o loop principal do sistema
    
    void exibirMenuPrincipal();
    void processarOpcaoMenu(int opcao);
    
    // Submenu de Cadastro
    void exibirMenuCadastro();
    void processarCadastro(int opcao);
    
    // Submenu de Consulta
    void exibirMenuConsulta();
    void processarConsulta(int opcao);
    
    // Consultas especificas
    void consultarLivrosPorAutor();
    void consultarLivrosPorEditora();
    void consultarEmprestimosPorLivro();
    void consultarReservasPorLivro();
    void consultarTodosPorUsuario();
    
    // Metodos auxiliares
    void liberarMemoria();
};

#endif
