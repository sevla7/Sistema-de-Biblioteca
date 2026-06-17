#ifndef ALUNO_H
#define ALUNO_H

#include "Usuario.h"

class Aluno : public Usuario {
private:
    string RA;
    string dep;

public:
    Aluno(
        int id,
        string nome,
        StatusUsuario status,
        string RA
    );

    Aluno();

    string getRA() const;
    void setRA(string RA);

    string getDepartamento() const;
    void setDepartamento(string dep);

    void exibirInformacoes() const override;
};

Aluno cadastraAluno(int idAluno);

#endif