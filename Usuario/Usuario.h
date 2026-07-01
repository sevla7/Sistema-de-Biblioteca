#ifndef USUARIO_H
#define USUARIO_H

#include "..\StatusUsuario\StatusUsuario.h"
#include <iostream>
#include <vector>
using namespace std;

class Usuario {
    private:
        int id;
        string nome;
        StatusUsuario status;

    public:
       Usuario(int i, string n, const StatusUsuario& status);
       Usuario();
       virtual ~Usuario();

       virtual void exibirInformacoes() const;
       
       // Metodo abstrato para polimorfismo (usado em Emprestimo e Reserva)
       virtual int getDiasEmprestimoPermitido() const = 0;
       virtual bool podeRealizarEmprestimo() const = 0;

       // Getters e Setters
       int getID() const;
       string getNome() const;
       StatusUsuario getStatus() const;

       void setID(const int id);
       void setNome(const string nome);
       void setStatus(const StatusUsuario& status);

};

// Nota: Usuario e agora uma classe abstrata e nao pode ser instanciada diretamente
// Uso Aluno ou Professor

#endif