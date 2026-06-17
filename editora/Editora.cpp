#include "Editora.h"
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::cin;

Editora::Editora(int id, string nome, Endereco& endereco) {
    this->id = id;
    this->nome = nome;
    this->endereco = endereco;
}

Editora::Editora() : id(0), nome("") {}

void Editora::exibirInformacoes() {
    cout << "====INFORMAÇÕES DA EDITORA====" << endl;
    cout << "ID: " << id << endl;
    cout << "Nome: " << nome << endl;
    cout << "Endereço: " << endereco.getRua() << ", " << endereco.getNumero() << endl;
    cout << "" << endl;
};

int Editora::getId() {
    return id;
}

void Editora::setId(int id) {
    this->id = id;
}

string Editora::getNome() {
    return nome;
}

void Editora::setNome(string nome) {
    this->nome = nome;
}

Endereco Editora::getEndereco() {
    return endereco;
}

void Editora::setEndereco(Endereco& endereco) {
    this->endereco = endereco;
}

Editora::~Editora() {}

Editora cadastraEditora(int idEditora) {
    Editora e;
    // int id; // Removed redundant local variable
    string nome;
    string rua, bairro, cidade, estado, cep;
    int numero;

    e.setId(idEditora); // Use the provided idEditora

    cout << "Digite o nome da editora: ";
    cin.ignore(); // Consume the newline character left by cin >> idEditora;
    getline(cin, nome);
    e.setNome(nome);

    cout << "--- Dados do Endereço ---" << endl;
    cout << "Rua: ";
    getline(cin, rua);

    cout << "Número: ";
    cin >> numero;
    cin.ignore(); // Consume the newline character

    cout << "Bairro: ";
    getline(cin, bairro);

    cout << "Cidade: ";
    getline(cin, cidade);

    cout << "Estado: ";
    getline(cin, estado);

    cout << "CEP: ";
    getline(cin, cep);

    Endereco end(rua, numero, bairro, cidade, estado, cep);
    e.setEndereco(end);

    return e;
}