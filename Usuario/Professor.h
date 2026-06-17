#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Usuario.h"

class Professor : public Usuario {
private:
    string departamento;
    int quantidadeTurmas;

public:
    Professor(
        int id,
        string nome,
        StatusUsuario status,
        string departamento,
        int quantidadeTurmas
    );

    Professor();

    string getDepartamento() const;
    int getQuantidadeTurmas() const;

    void setDepartamento(string departamento);
    void setQuantidadeTurmas(int quantidadeTurmas);

    void exibirInformacoes() const override;
};

Professor cadastraProfessor(int idProf);

#endif