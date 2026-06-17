#include "StatusUsuario.h"

string statusToString(StatusUsuario status) {

switch (status) {

case StatusUsuario::HABILITADO: return "Habilitado";
case StatusUsuario::EM_DEBITO: return "Em débito";

default: return "Status desconhecido";

  }
}  