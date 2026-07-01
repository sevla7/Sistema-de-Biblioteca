#include "StatusEmprestimo.h"

string statusEmprestimoToString(StatusEmprestimo status) {

switch (status) {

case StatusEmprestimo::DISPONIVEL: return "Disponivel";
case StatusEmprestimo::EMPRESTADO: return "Emprestado";

default: return "Status desconhecido";

  }
}  