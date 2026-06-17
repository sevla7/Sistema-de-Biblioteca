#ifndef LIVRO_H
#define LIVRO_H

#include <string>
#include <vector>
#include "..\autor\Autor.h"
#include "..\editora\Editora.h"
using std::string;
using std::cout;
using std::endl;
using std::vector;

class Livro {
    private:
        int codigo;
        string titulo;
        int edicao;
        float preco;
        Editora editora; // Objeto (Relacionamento 1:1)
        int ano;
        int quantidadeExemplares;
        int nroDiasPermitidoEmprestimo;
        vector<Autor*> autores;
        int statusAgora;
        int statusFuturo;
        int nroPaginas;

    public:
        Livro(int codigo,
              const string& titulo,
              int edicao,
              float preco,
              const Editora& editora,
              int ano,
              int quantidadeExemplares,
              int nroDiasPermitidoEmprestimo,
              const vector<Autor*>& autores,
              int statusAgora,
              int statusFuturo,
              int nroPaginas);
        Livro();

        // Gets
        string getTitulo() const;
        const vector<Autor*>& getAutores() const; 
        int getAno() const;
        float getPreco() const;
        Editora getEditora() const;
        int getCodigo() const;
        int getEdicao() const;
        int getQuantidadeExemplares() const;
        int getNroDiasPermitidoEmprestimo() const;
        int getStatusAgora() const;
        int getStatusFuturo() const;
        int getNroPaginas() const;

        // Sets
        void setTitulo(const string& titulo);
        void adicionarAutor(Autor* autor); 
        void setAno(const int ano);
        void setPreco(const float preco);
        void setEditora(const Editora& editora);
        void setCodigo(const int codigo);
        void setEdicao(const int edicao);
        void setQuantidadeExemplares(const int quantidadeExemplares);
        void setNroDiasPermitidoEmprestimo(const int nroDiasPermitidoEmprestimo);
        void setStatusAgora(const int statusAgora);
        void setStatusFuturo(const int statusFuturo);
        void setNroPaginas(const int nroPaginas);

        void exibirInformacoes();

        bool estaDisponivel();

};

Livro cadastraLivro();

#endif