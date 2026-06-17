#ifndef USUARIO_H
#define USUARIO_H

#include "..\StatusUsuario\StatusUsuario.h"
#include <iostream>
#include <vector>
using namespace std;

class Usuario {
    private:
        int id;
        string nome;
        StatusUsuario status;

    public:
       Usuario(int i, string n, const StatusUsuario& status);
       Usuario();
       virtual ~Usuario();

       virtual void exibirInformacoes() const;

       // Getters e Setters
       int getID() const;
       string getNome() const;
       StatusUsuario getStatus() const;

       void setID(const int id);
       void setNome(const string nome);
       void setStatus(const StatusUsuario& status);

};

Usuario cadastraUsuario(int idUsuario);

#endif