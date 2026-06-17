#ifndef AUTOR_H
#define AUTOR_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;
using std::vector;

class Livro;

class Autor {
private:
    string nome;
    int codigo;
    vector<Livro*> livros; // O "Vetor" para o relacionamento 1:N
    // Se não passar livros como ponteiro, toda vez que você adiciona um livro ao vetor,
    // o C++ cria um novo livro idêntico e o coloca lá dentro. Se você tiver 1000 livros, terá 1000 cópias ocupando o dobro de memória.

public:
    // Usamos const string& para aceitar textos diretos ("J.K. Rowling")
    Autor(const string& n, const int c);
    Autor();

    void adicionarLivro(Livro* livro);
    void exibirInformacoes();

    string getNome() const;
    int getCodigo() const;

    void setNome(const string& n);
    void setCodigo(const int c);
};

Autor cadastraAutor(int cod);
#endif