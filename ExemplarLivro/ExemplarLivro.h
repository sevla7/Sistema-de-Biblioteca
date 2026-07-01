#ifndef EXEMPLARLIVRO_H
#define EXEMPLARLIVRO_H

class Livro;
#include "..\ExemplarLivro\StatusEmprestimo.h"
#include <vector>
using std::vector;

class ExemplarLivro {
    private:
        int nroExemplar;
        StatusEmprestimo status; // Associacao com a classe StatusEmprestimo
        Livro* livro; // Associacao com a classe Livro

    public:
        ExemplarLivro(int c, Livro* l);
        ExemplarLivro();
        int getNroExemplar() const;
        StatusEmprestimo getStatus() const;
        Livro* getLivro() const;

        void setNroExemplar(const int nroExemplar);
        void setStatus(const StatusEmprestimo status);
        void setLivro(Livro* l);
        void exibirInformacoes();

};

#endif