#include "Professor.h"

Professor::Professor(
    int id,
    string nome,
    StatusUsuario status,
    string departamento,
    int quantidadeTurmas)
    : Usuario(id, nome, status),
      departamento(departamento),
      quantidadeTurmas(quantidadeTurmas)
{}

Professor::Professor()
    : Usuario(),
      departamento(""),
      quantidadeTurmas(0)
{}

string Professor::getDepartamento() const {
    return departamento;
}

int Professor::getQuantidadeTurmas() const {
    return quantidadeTurmas;
}

void Professor::setDepartamento(string departamento) {
    this->departamento = departamento;
}

void Professor::setQuantidadeTurmas(int quantidadeTurmas) {
    this->quantidadeTurmas = quantidadeTurmas;
}

void Professor::exibirInformacoes() const {

    cout << "PROFESSOR: " << endl;
    Usuario::exibirInformacoes();

    cout << "Departamento: "
         << departamento
         << endl;

    cout << "Quantidade de turmas: "
         << quantidadeTurmas
         << endl;
}

Professor cadastraProfessor(int idProf) {

    Professor p;

    // int id; // Removed redundant local variable
    string nome;
    string departamento;
    int qtdTurmas;

    p.setID(idProf); // Use the provided idProf

    cout << "Digite o nome: ";
    cin.ignore();
    getline(cin, nome);
    p.setNome(nome);

    cout << "Digite o departamento: ";
    getline(cin, departamento);
    p.setDepartamento(departamento);

    cout << "Digite a quantidade de turmas: ";
    cin >> qtdTurmas;
    p.setQuantidadeTurmas(qtdTurmas);

    p.setStatus(StatusUsuario::HABILITADO);

    return p;
}