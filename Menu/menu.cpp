#include <iostream>
#include <string>
#include "menu.h"
using namespace std;
using std::string;
using std::cout;
using std::endl;

void exibirMenu(){

  cout << "\nMENU\n" << endl;
  cout << "1. Cadastrar" << endl;
  cout << "2. Editar livro" << endl;
  cout << "3. Remover livro" << endl;
  cout << "4. Criar reserva" << endl;
  cout << "5. Criar emprestimo" << endl;
  cout << "6. Devolver emprestimo" << endl;
  cout << "7. Consultar" << endl;
  cout << "8. Sair" << endl;
  cout << "9. Deletar Reserva" << endl;
  cout << "\nSELECIONE A OPCAO DESEJADA.\n" << endl;

}

void exibirSubMenuConsultar() {
    cout << "\nCONSULTAS\n";
    cout << "1 - Listar Livros\n";
    cout << "2 - Listar Autores\n";
    cout << "3 - Listar Usuarios\n";
    cout << "4 - Listar todas as Reservas\n";
    cout << "5 - Listar Reservas de um Usuario\n";
    cout << "6 - Emprestimos de um Usuario\n";
    cout << "7 - Todos os Emprestimos Atuais\n";
    cout << "Opcao: ";
}