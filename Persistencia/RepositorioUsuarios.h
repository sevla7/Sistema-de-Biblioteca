#ifndef REPOSITORIOUSUARIOS_H
#define REPOSITORIOUSUARIOS_H

#include "Repositorio.h"
#include "..\Usuario\Usuario.h"

class RepositorioUsuarios : public Repositorio<Usuario*> {
public:
    RepositorioUsuarios();
    ~RepositorioUsuarios();
    
    Usuario* buscarPorID(int id);
    bool existeUsuario(int id);
};

#endif
