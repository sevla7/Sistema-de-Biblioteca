#include "LogoSistema.h"
#include <iostream>
#include <windows.h>

using namespace std;

void LogoSistema::exibirLogo() {
    cout << "\n";
    cout << "\n";
    cout << "                                                           \n";
    cout << "            SISTEMA DE GERENCIAMENTO DE BIBLIOTECA     \n";
    cout << "                                                           \n";
    cout << "            Versao 2.0 - Arquitetura em 3 Camadas         \n";
    cout << "                                                           \n";
    cout << "  Desenvolvido em C++ com Orientacao a Objetos e Padroes  \n";
    cout << "                                                           \n";
    cout << "\n";
    cout << "\n";
}

void LogoSistema::exibirMensagemBemVindo() {
    cout << "\n";
    cout << "                   BEM-VINDO A BIBLIOTECA!                \n";
    cout << "                                                           \n";
    cout << "  Sistema com suporte a:                                   \n";
    cout << "   Cadastro de Livros, Autores e Editoras                \n";
    cout << "   Gerenciamento de Usuarios (Alunos e Professores)      \n";
    cout << "   Emprestimos e Reservas de Livros                      \n";
    cout << "   Consultas Avancadas e Relatorios                      \n";
    cout << "   Validacao de Regras de Negocio                        \n";
    cout << "                                                           \n";
    cout << "\n\n";
}

void LogoSistema::exibirCarregando() {
    cout << "\n Carregando dados pre-cadastrados...\n";
    for (int i = 0; i < 3; i++) {
        cout << ".";
        Sleep(300);
    }
    cout << "  Concluido!\n\n";
}
