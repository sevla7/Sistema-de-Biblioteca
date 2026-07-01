#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H

#include <iostream>

using std::string;

class Usuario;
class Livro;
class ExemplarLivro;

class Emprestimo {
    private:
      static int nextId;
      int id;
      int dataDeRetirada;
      int DataPrevistaDevolucao;
      int DataDevolucao;
      int status;
      Usuario *usuario; // Relacionamento 1:* com Usuario
      Livro* livro;
      ExemplarLivro* exemplar;

    public:
        Emprestimo(const int dataDeRetirada,
           const int DataPrevistaDevolucao,
           const int DataDevolucao,
           const int status,
           Usuario *usuario,
           Livro* livro,
           ExemplarLivro* exemplar = nullptr,
           int id = 0);
        Emprestimo();

        int getDataDeRetirada() const;
        int getDataPrevistaDevolucao() const;
        int getDataDevolucao() const;
        int getStatus() const;
        Usuario* getUsuario() const;
        Livro* getLivro() const;
        ExemplarLivro* getExemplar() const;
        int getId() const;

        void setDataDeRetirada(const int dataDeRetirada);
        void setDataPrevistaDevolucao(const int DataPrevistaDevolucao);
        void setDataDevolucao(const int DataDevolucao);
        void setStatus(const int status);
        void setUsuario(Usuario* usuario);
        void setExemplar(ExemplarLivro* exemplar);
        void setId(int id);

        void exibirInformacoes();

};

#endif