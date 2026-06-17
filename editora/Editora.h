#ifndef EDITORA_H
#define EDITORA_H
#include "..\Endereco\Endereco.h"

class Editora {
    private:
        int id;
        string nome;
        Endereco endereco;

    public:
        Editora(int id, string nome, Endereco& endereco);
        Editora();

        int getId();
        void setId(int id);

        string getNome();
        void setNome(string nome);

        void exibirInformacoes();

        Endereco getEndereco();
        void setEndereco(Endereco& endereco);

         ~Editora();
};

Editora cadastraEditora(int idEditora);

#endif