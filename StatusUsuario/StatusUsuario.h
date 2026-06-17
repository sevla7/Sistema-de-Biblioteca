#include <iostream>

#include <string>
using std::string;

enum class StatusUsuario {

HABILITADO,
EM_DEBITO,
NAO_DEFINIDO, // Funciona como "null"
};

string statusToString (StatusUsuario status);