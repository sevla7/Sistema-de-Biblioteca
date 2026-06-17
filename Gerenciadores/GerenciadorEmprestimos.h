#ifndef GERENCIADOREMPRESTIMOS_H
#define GERENCIADOREMPRESTIMOS_H

#include "../emp/Emprestimo.h"
#include "../Usuario/Usuario.h"
#include "../Livro/Livro.h"
#include <vector>
#include <string>
using std::string;
using std::cout;
using std::endl;


class GerenciadorEmprestimos {
private:
    static vector<Emprestimo*> emprestimos;


public:
    // Construtores atualizados para aceitar Emprestimo**
    GerenciadorEmprestimos();
    GerenciadorEmprestimos(vector<Emprestimo*> emprestimos);

    // Getter e Setter atualizados
    vector<Emprestimo*> getEmprestimos() const;
    static void setEmprestimos(vector<Emprestimo*> emprestimos);

    static void listarTodosEmprestimosAtuais();
    static void CriarEmprestimo(Usuario* usuario, Livro* livroDesejado);
    static void listarEmprestimosPorUsuario(int idUsuario); 
};

#endif