#include "StatusEmprestimo.h"

string statusEmprestimoToString(StatusEmprestimo status) {

switch (status) {

case StatusEmprestimo::DISPONIVEL: return "Disponível";
case StatusEmprestimo::EMPRESTADO: return "Emprestado";

default: return "Status desconhecido";

  }
}  