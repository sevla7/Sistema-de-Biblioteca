#ifndef GERENCIADORCADASTRO_H
#define GERENCIADORCADASTRO_H

#include "..\editora\Editora.h"
#include "..\Usuario\Usuario.h"
#include "..\Livro\Livro.h"
#include "..\Autor\Autor.h"
#include <vector>
#include <string>

class GerenciadorCadastro {
private:
    static std::vector<Editora*> editoras;
    static std::vector<Autor*> autores;
    static std::vector<Usuario*> usuarios;

public:
    static const std::vector<Editora*>& getEditoras(); 
    static const std::vector<Autor*>& getAutores();
    static const std::vector<Usuario*>& getUsuarios();
    static Editora* verificaEditora(int idBuscado); 
    static Autor* verificaAutor(int idBuscado); 
    static Usuario* verificaUsuario(int idBuscado);      

    // Added methods to manage the static vectors
    static void adicionarEditora(Editora* editora);
    static void adicionarAutor(Autor* autor);
    static void adicionarUsuario(Usuario* usuario);
};

#endif
