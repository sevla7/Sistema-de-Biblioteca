#ifndef RESERVA_H
#define RESERVA_H

#include "ItemReserva.h"
#include <vector>
#include <iostream>
using namespace std;

class Usuario;

class Reserva {
    private:
        int ID;
        int dataRealizacao;
        vector<ItemReserva*> itens;
        Usuario* usuario;

    public:
        Reserva(int ID, int dataRealizacao, Usuario* usuario);
        Reserva();
        ~Reserva();

        int getID() const;
        int getDataRealizacao() const;
        Usuario* getUsuario() const;
        const vector<ItemReserva*>& getItems() const; // New getter

        void setID(const int ID);
        void setDataRealizacao(const int dataRealizacao);
        void setUsuario(Usuario* usuario);

        void adicionarItem(ItemReserva* novoItem);
        void exibirInformacoes();
};

#endif