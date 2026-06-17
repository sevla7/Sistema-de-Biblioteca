#ifndef ACERVO_H
#define ACERVO_H

#include "..\Livro\Livro.h"
#include "..\ExemplarLivro\ExemplarLivro.h"
#include <vector>
#include <algorithm> // Necessário para o std::remove

class Acervo {
    private:
        static std::vector<Livro*> livros;
        static std::vector<ExemplarLivro*> listaExemplares;

    public:
        static void acrecentarLivro(Livro* livro);
        static void removerLivro(Livro* livro);
        static void listarTodos();
        static void LivrosDisponiveis();
        static void LivrosIndisponiveis();

        static Livro* buscarLivro(int codigo);
        static void removerLivroPorCodigo(int codigo);

        static void criarExemplaresParaLivro(Livro* livro, int quantidade); // Renamed and added parameters
        static ExemplarLivro* buscarExemplar(int nroExemplar);
        static const std::vector<ExemplarLivro*>& getListaExemplares(); // Getter for private listaExemplares
        static const std::vector<Livro*>& getListaLivros(); // New getter for private livros
};

#endif
