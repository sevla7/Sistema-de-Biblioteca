#include "ItemReserva.h"
#include "..\Livro\Livro.h" 

ItemReserva::ItemReserva(int nroDoItem, int dataDeRetirada, ExemplarLivro* exemplar)
    : nroDoItem(nroDoItem), dataDeRetirada(dataDeRetirada), exemplar(exemplar) {}

ItemReserva::ItemReserva() : nroDoItem(0), dataDeRetirada(0), exemplar(nullptr) {}

int ItemReserva::getNroDoItem() const {
    return nroDoItem;
}

int ItemReserva::getDataDeRetirada() const {
    return dataDeRetirada;
}

ExemplarLivro* ItemReserva::getExemplar() const { 
    return exemplar;
}

void ItemReserva::setNroDoItem(const int nroDoItem) {
    this->nroDoItem = nroDoItem;
}

void ItemReserva::setDataDeRetirada(const int dataDeRetirada) {
    this->dataDeRetirada = dataDeRetirada;
}

void ItemReserva::setExemplar(ExemplarLivro* exemplar) {
    this->exemplar = exemplar;
}

void ItemReserva::exibirInformacoes() {
    cout << "====INFORMAÇÕES DO ITEM RESERVA====" << endl;
    cout << "Nº do Item: " << nroDoItem << endl;
    cout << "Data de Retirada: " << dataDeRetirada << endl;
    cout << "Livro: ";
    if (this->exemplar != nullptr) {
        cout << this->exemplar->getLivro()->getTitulo(); 
        cout << " (Exemplar: " << this->exemplar->getNroExemplar() << ")"; 
    }
    cout << "\n" << endl;
}