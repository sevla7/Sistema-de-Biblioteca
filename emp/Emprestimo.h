#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H

#include <iostream>

using std::string;

class Usuario;
class Livro;

class Emprestimo {
    private:
      int dataDeRetirada;
      int DataPrevistaDevolucao;
      int DataDevolucao;
      int status;
      Usuario *usuario; // Relacionamento 1:* com Usuario
      Livro* livro;

    public:
        Emprestimo(const int dataDeRetirada,
           const int DataPrevistaDevolucao,
           const int DataDevolucao,
           const int status,
           Usuario *usuario,
           Livro* livro);
        Emprestimo();

        int getDataDeRetirada() const;
        int getDataPrevistaDevolucao() const;
        int getDataDevolucao() const;
        int getStatus() const;
        Usuario getUsuario() const;
        Livro* getLivro() const;

        void setDataDeRetirada(const int dataDeRetirada);
        void setDataPrevistaDevolucao(const int DataPrevistaDevolucao);
        void setDataDevolucao(const int DataDevolucao);
        void setStatus(const int status);
        void setUsuario(const Usuario& usuario);

        void exibirInformacoes();

};

#endif