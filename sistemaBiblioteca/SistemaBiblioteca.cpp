#include "SistemaBiblioteca.h"
#include "..\acervo\Acervo.h"
#include "..\Gerenciadores\GerenciadorCadastro.h"
#include "..\Gerenciadores\GerenciadorEmprestimos.h"
#include "..\Menu\menu.h"
#include "..\Negocio\RegrasNegocio.h"
#include <iostream>
#include <limits>
#include <windows.h>
#include <locale.h>

using namespace std;

SistemaBiblioteca::SistemaBiblioteca() {
    SetConsoleOutputCP(65001);
    setlocale(LC_ALL, "Portuguese_Brazil");
}

SistemaBiblioteca::~SistemaBiblioteca() {
    liberarMemoria();
}

void SistemaBiblioteca::iniciar() {
    int opcao;
    
    do {
        exibirMenuPrincipal();
        
        // Leitura segura de entrada
        if (!(cin >> opcao)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n[ERRO] Entrada invalida!" << endl;
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        try {
            processarOpcaoMenu(opcao);
        } catch (const runtime_error& e) {
            cout << "\n" << string(40, '-') << endl;
            cout << e.what() << endl;
            cout << "Retornando ao menu principal..." << endl;
            cout << string(40, '-') << "\n" << endl;
        }
        
    } while (opcao != 7);
    
    liberarMemoria();
}

void SistemaBiblioteca::exibirMenuPrincipal() {
    cout << "\n" << endl;
    cout << "   SISTEMA DE BIBLIOTECA            " << endl;
    cout << "" << endl;
    cout << " 1. Cadastrar                       " << endl;
    cout << " 2. Editar Livro                    " << endl;
    cout << " 3. Remover Livro                   " << endl;
    cout << " 4. Criar Reserva                   " << endl;
    cout << " 5. Criar Emprestimo                " << endl;
    cout << " 6. Consultar                       " << endl;
    cout << " 7. Sair                            " << endl;
    cout << "" << endl;
    cout << "Selecione uma opcao: ";
}

void SistemaBiblioteca::processarOpcaoMenu(int opcao) {
    switch(opcao) {
        case 1:
            exibirMenuCadastro();
            break;
        case 2:
            cout << "[EM DESENVOLVIMENTO]" << endl;
            break;
        case 3:
            cout << "[EM DESENVOLVIMENTO]" << endl;
            break;
        case 4:
            cout << "[EM DESENVOLVIMENTO]" << endl;
            break;
        case 5:
            cout << "[EM DESENVOLVIMENTO]" << endl;
            break;
        case 6:
            exibirMenuConsulta();
            break;
        case 7:
            cout << "\nEncerrando sistema..." << endl;
            break;
        default:
            cout << "\n[ERRO] Opcao invalida!" << endl;
    }
}

void SistemaBiblioteca::exibirMenuCadastro() {
    cout << "\n" << endl;
    cout << "   CADASTRO                         " << endl;
    cout << "" << endl;
    cout << " 1. Cadastrar Livro                 " << endl;
    cout << " 2. Cadastrar Autor                 " << endl;
    cout << " 3. Cadastrar Aluno                 " << endl;
    cout << " 4. Cadastrar Professor             " << endl;
    cout << " 5. Cadastrar Editora               " << endl;
    cout << "" << endl;
    
    int opcao;
    cout << "Selecione uma opcao: ";
    if (!(cin >> opcao)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw runtime_error("[ERRO] Entrada invalida!");
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    processarCadastro(opcao);
}

void SistemaBiblioteca::processarCadastro(int opcao) {
    cout << endl;
    // Implementacao sera migrada do main.cpp
    cout << "[FUNCIONALIDADE MIGRADA DO main.cpp]" << endl;
}

void SistemaBiblioteca::exibirMenuConsulta() {
    cout << "\n" << endl;
    cout << "   CONSULTAS                        " << endl;
    cout << "" << endl;
    cout << " 1. Listar Todos os Livros          " << endl;
    cout << " 2. Listar Autores                  " << endl;
    cout << " 3. Listar Usuarios                 " << endl;
    cout << " 4. Emprestimos de um Livro         " << endl;
    cout << " 5. Reservas de um Livro            " << endl;
    cout << " 6. Historico de um Usuario         " << endl;
    cout << " 7. Todos os Emprestimos            " << endl;
    cout << " 8. Todas as Reservas               " << endl;
    cout << "" << endl;
    
    int opcao;
    cout << "Selecione uma opcao: ";
    if (!(cin >> opcao)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw runtime_error("[ERRO] Entrada invalida!");
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    processarConsulta(opcao);
}

void SistemaBiblioteca::processarConsulta(int opcao) {
    cout << endl;
    switch(opcao) {
        case 1:
            Acervo::listarTodos();
            break;
        case 2:
            for(Autor* autor : GerenciadorCadastro::getAutores()) {
                autor->exibirInformacoes();
                cout << endl;
            }
            break;
        case 3:
            for(Usuario* usuario : GerenciadorCadastro::getUsuarios()) {
                usuario->exibirInformacoes();
                cout << endl;
            }
            break;
        case 4:
            consultarEmprestimosPorLivro();
            break;
        case 5:
            consultarReservasPorLivro();
            break;
        case 6:
            consultarTodosPorUsuario();
            break;
        case 7:
            GerenciadorEmprestimos::listarTodosEmprestimosAtuais();
            break;
        case 8:
            cout << "[FUNCIONALIDADE MIGRADA DO main.cpp]" << endl;
            break;
        default:
            cout << "[ERRO] Opcao invalida!" << endl;
    }
}

void SistemaBiblioteca::consultarEmprestimosPorLivro() {
    cout << "Digite o codigo do livro: ";
    int codigo;
    cin >> codigo;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    Livro* livro = Acervo::buscarLivro(codigo);
    if (livro == nullptr) {
        throw runtime_error("[ERRO] Livro nao encontrado!");
    }
    
    cout << "\n[EMPRESTIMOS DO LIVRO: " << livro->getTitulo() << "]" << endl;
    // Implementacao sera feita com a classe de emprestimos
    cout << "[FUNCIONALIDADE EM DESENVOLVIMENTO]" << endl;
}

void SistemaBiblioteca::consultarReservasPorLivro() {
    cout << "Digite o codigo do livro: ";
    int codigo;
    cin >> codigo;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    Livro* livro = Acervo::buscarLivro(codigo);
    if (livro == nullptr) {
        throw runtime_error("[ERRO] Livro nao encontrado!");
    }
    
    cout << "\n[RESERVAS DO LIVRO: " << livro->getTitulo() << "]" << endl;
    // Implementacao sera feita com a classe de reservas
    cout << "[FUNCIONALIDADE EM DESENVOLVIMENTO]" << endl;
}

void SistemaBiblioteca::consultarTodosPorUsuario() {
    cout << "Digite o ID do usuario: ";
    int id;
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    Usuario* usuario = GerenciadorCadastro::verificaUsuario(id);
    if (usuario == nullptr) {
        throw runtime_error("[ERRO] Usuario nao encontrado!");
    }
    
    cout << "\n[HISTORICO DE: " << usuario->getNome() << "]" << endl;
    cout << "Emprestimos: ";
    GerenciadorEmprestimos::listarEmprestimosPorUsuario(id);
}

void SistemaBiblioteca::liberarMemoria() {
    cout << "\nLimpando memoria..." << endl;
    
    for(Autor* autor : GerenciadorCadastro::getAutores()) {
        delete autor;
    }
    
    for(Usuario* usuario : GerenciadorCadastro::getUsuarios()) {
        delete usuario;
    }
    
    for(Editora* editora : GerenciadorCadastro::getEditoras()) {
        delete editora;
    }
    
    for(Livro* livro : Acervo::getListaLivros()) {
        delete livro;
    }
    
    for(ExemplarLivro* exemplar : Acervo::getListaExemplares()) {
        delete exemplar;
    }
    
    for(Reserva* reserva : reservas) {
        delete reserva;
    }
    
    cout << "Memoria liberada com sucesso!" << endl;
}
