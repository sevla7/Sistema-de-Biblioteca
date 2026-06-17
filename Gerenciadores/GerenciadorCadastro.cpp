#include "GerenciadorCadastro.h"
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;

// Define static member variables outside the class.
std::vector<Editora*> GerenciadorCadastro::editoras;
std::vector<Autor*> GerenciadorCadastro::autores;
std::vector<Usuario*> GerenciadorCadastro::usuarios;

Editora* GerenciadorCadastro::verificaEditora(int idBuscado) {
    for (size_t i = 0; i < GerenciadorCadastro::editoras.size(); i++) {
        if (GerenciadorCadastro::editoras[i]->getId() == idBuscado) {
            return GerenciadorCadastro::editoras[i];
        }
    }
    return nullptr;
}


const std::vector<Editora*>& GerenciadorCadastro::getEditoras() {
    return editoras;
}

const std::vector<Autor*>& GerenciadorCadastro::getAutores() {
    return autores;
}

const std::vector<Usuario*>& GerenciadorCadastro::getUsuarios() {
    return usuarios;
}


Autor* GerenciadorCadastro::verificaAutor(int idBuscado) {
    for (size_t i = 0; i < GerenciadorCadastro::autores.size(); i++) { 
        if (GerenciadorCadastro::autores[i]->getCodigo() == idBuscado) {
            return GerenciadorCadastro::autores[i];
        }
    }
    return nullptr;
}

Usuario* GerenciadorCadastro::verificaUsuario(int idBuscado) {
    for (size_t i = 0; i < GerenciadorCadastro::usuarios.size(); i++) { 
        if (GerenciadorCadastro::usuarios[i]->getID() == idBuscado) {
            return GerenciadorCadastro::usuarios[i];
        }
    }
    return nullptr;
}

void GerenciadorCadastro::adicionarEditora(Editora* editora) {
    GerenciadorCadastro::editoras.push_back(editora);
}

void GerenciadorCadastro::adicionarAutor(Autor* autor) {
    GerenciadorCadastro::autores.push_back(autor);
}

void GerenciadorCadastro::adicionarUsuario(Usuario* usuario) {
    GerenciadorCadastro::usuarios.push_back(usuario);
}
