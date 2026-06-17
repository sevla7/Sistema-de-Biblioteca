#ifndef ITEMRESERVA_H
#define ITEMRESERVA_H

#include "..\ExemplarLivro\ExemplarLivro.h" 
#include <iostream>
using namespace std;

class ItemReserva {
    private:
      int nroDoItem;
      int dataDeRetirada;
      ExemplarLivro* exemplar; 

    public:
      ItemReserva(int nroDoItem, int dataDeRetirada, ExemplarLivro* exemplar); // Updated signature
      ItemReserva();

      int getNroDoItem() const;
      int getDataDeRetirada() const;
      ExemplarLivro* getExemplar() const; // Updated getter

      void setNroDoItem(const int nroDoItem);
      void setDataDeRetirada(const int dataDeRetirada);
      void setExemplar(ExemplarLivro* exemplar); // Updated setter

      void exibirInformacoes();
};

#endif