#include "Endereco.h"

Endereco::Endereco(const string& r, const int& n, const string& b, const string& c, const string& e, const string& cep) {
    this->rua = r;
    this->numero = n;
    this->bairro = b;
    this->cidade = c;
    this->estado = e;
    this->cep = cep;
}

Endereco::Endereco() {
    this->rua = "";
    this->numero = 0;
    this->bairro = "";
    this->cidade = "";
    this->estado = "";
    this->cep = "";
}

string Endereco::getRua() const {
    return rua;
}

int Endereco::getNumero() const {
    return numero;
}

string Endereco::getBairro() const {
    return bairro;
}

string Endereco::getCidade() const {
    return cidade;
}

string Endereco::getEstado() const {
    return estado;
}

string Endereco::getCep() const {
    return cep;
}


void Endereco::setRua(const string& rua) {
    this->rua = rua;
}

void Endereco::setNumero(const int& numero) {
    this->numero = numero;
}

void Endereco::setBairro(const string& bairro) {
    this->bairro = bairro;
}

void Endereco::setCidade(const string& cidade) {
    this->cidade = cidade;
}

void Endereco::setEstado(const string& estado) {
    this->estado = estado;
}

void Endereco::setCep(const string& cep) {
    this->cep = cep;
}