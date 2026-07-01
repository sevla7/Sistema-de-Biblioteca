#ifndef REPOSITORIOLIVROS_H
#define REPOSITORIOLIVROS_H

#include "Repositorio.h"
#include "..\Livro\Livro.h"

class RepositorioLivros : public Repositorio<Livro*> {
public:
    RepositorioLivros();
    ~RepositorioLivros();
    
    Livro* buscarPorCodigo(int codigo);
    Livro* buscarPorTitulo(const std::string& titulo);
    void removerPorCodigo(int codigo);
    bool existeLivro(int codigo);
};

#endif
