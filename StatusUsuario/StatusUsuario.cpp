#include "StatusUsuario.h"

string statusToString(StatusUsuario status) {

switch (status) {

case StatusUsuario::HABILITADO: return "Habilitado";
case StatusUsuario::EM_DEBITO: return "Em debito";

default: return "Status desconhecido";

  }
}  