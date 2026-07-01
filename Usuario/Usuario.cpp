#include "Usuario.h"
#include <iostream>
#include <vector>
using namespace std;

Usuario::Usuario(int i, string n, const StatusUsuario& s )
    : id (i), nome (n), status (s) {}
Usuario::Usuario() : id (0), nome(""), status(StatusUsuario::NAO_DEFINIDO) {}

Usuario::~Usuario() {}

void Usuario::exibirInformacoes() const {
    cout << "====INFORMACOES DO USUARIO====" << endl;
    cout << "ID: " << id << endl;
    cout << "Nome: " << nome << endl;
    cout << "Status: " << statusToString(status) << endl;
}

int Usuario::getID() const {
    return id;
}

string Usuario::getNome() const {
    return nome;
}

StatusUsuario Usuario::getStatus() const {
    return status;
}

void Usuario::setID(const int id) {
    this->id = id;
}

void Usuario::setNome(const string nome) {
    this->nome = nome;
}

void Usuario::setStatus(const StatusUsuario& status) {
    this->status = status;
}
