#include "Aluno.h"

Aluno::Aluno(
    int id,
    string nome,
    StatusUsuario status,
    string RA)
    : Usuario(id, nome, status),
      RA(RA)
{}

Aluno::Aluno()
    : Usuario(),
      RA("000000")
{}

string Aluno::getRA() const {
    return RA;
}

void Aluno::setRA(string RA) {
    this->RA = RA;
}

string Aluno::getDepartamento() const {
    return dep;
}

void Aluno::setDepartamento(string dep) {
    this->dep = dep;
}

void Aluno::exibirInformacoes() const {

    cout << "ALUNO: " << endl;
    Usuario::exibirInformacoes();

    cout << "RA: "
         << RA
         << endl;

    cout << "Departamento: "
         << dep
         << endl;
}

Aluno cadastraAluno(int idAluno, string nome) {

    Aluno a;
    string RA;
    string dep;

    a.setID(idAluno); // Use the provided idAluno
    a.setNome(nome);

    cout << "Digite o RA: ";
    getline(cin, RA);
    a.setRA(RA);

    cout << "Digite o departamento: ";
    getline(cin, dep);
    a.setDepartamento(dep);

    a.setStatus(StatusUsuario::HABILITADO);

    return a;
}