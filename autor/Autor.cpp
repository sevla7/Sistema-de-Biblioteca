#include "Autor.h"
#include "..\Livro\Livro.h"
#include <iostream>

using namespace std;

Autor::Autor(const string& n, int c) : nome(n), codigo(c) {}
Autor::Autor() : nome(""), codigo(0) {}

void Autor::adicionarLivro(Livro* livro) {
    this->livros.push_back(livro); // Adiciona ao "vetor"
}

void Autor::exibirInformacoes() {
    cout << "====INFORMAÇÕES DO AUTOR====" << endl;
    cout << "Autor: " << nome << " (Cod: " << codigo << ")" << endl;
    cout << "Livros escritos: " << livros.size();
    cout << endl;
    for (const Livro* l : livros) {
        std::cout << "- " << l->getTitulo() << std::endl;
    }
}

string Autor::getNome() const {
    return nome;
}

int Autor::getCodigo() const {
    return codigo;
}

void Autor::setNome(const string& n) {
    this->nome = n;
}

void Autor::setCodigo(const int c) {
    this->codigo = c;
}

Autor cadastraAutor(int cod) {
    Autor a;
    string nome;
    // int codigo; // Removed redundant local variable
    a.setCodigo(cod); // Use the provided 'cod' parameter

    cout << "Digite o nome do autor: ";
    cin.ignore();
    getline(cin, nome);
    a.setNome(nome);

    return a;
}
