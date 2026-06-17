#ifndef STATUSEMPRESTIMO_H
#define STATUSEMPRESTIMO_H

#include <string>
using std::string;

enum class StatusEmprestimo {
    DISPONIVEL,
    EMPRESTADO
};

string statusEmprestimoToString (StatusEmprestimo status);
#endif