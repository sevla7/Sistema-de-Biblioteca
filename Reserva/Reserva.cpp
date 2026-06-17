#include "Reserva.h"
#include "..\Usuario\Usuario.h"

Reserva::Reserva(
    int ID,
    int dataRealizacao,
    Usuario* usuario)
    : ID(ID),
      dataRealizacao(dataRealizacao),
      usuario(usuario) {}

Reserva::Reserva()
    : ID(0),
      dataRealizacao(0),
      usuario(nullptr) {}

int Reserva::getID() const {
    return ID;
}

int Reserva::getDataRealizacao() const {
    return dataRealizacao;
}

Usuario* Reserva::getUsuario() const {
    return usuario;
}

const vector<ItemReserva*>& Reserva::getItems() const { // Implementation of the new getter
    return itens;
}

void Reserva::setID(const int ID) {
    this->ID = ID;
}

void Reserva::setDataRealizacao(const int dataRealizacao) {
    this->dataRealizacao = dataRealizacao;
}

void Reserva::setUsuario(Usuario* usuario) {
    this->usuario = usuario;
}

void Reserva::adicionarItem(ItemReserva* novoItem) {
    if (novoItem != nullptr) {
        itens.push_back(novoItem);
    }
}

void Reserva::exibirInformacoes() {
    cout << "====INFORMAÇÕES DA RESERVA====" << endl;
    cout << "ID: " << ID << endl;
    cout << "Data de Realização: " << dataRealizacao << endl;
    cout << "Usuario: ";

    if(usuario != nullptr){
        cout << usuario->getNome();
    }
    else{
        cout << "Nao definido";
    }

    cout << endl;
    cout << "" << endl;
    for (ItemReserva* item : itens) {
        item->exibirInformacoes();
        cout << "" << endl;
    }
    cout << "" << endl;
}

Reserva::~Reserva() {
    cout << "Destruindo Reserva " << ID << " e limpando seus itens..." << endl;
    for (ItemReserva* item : itens) {
        delete item;
    }
    itens.clear();
    cout << endl;
}