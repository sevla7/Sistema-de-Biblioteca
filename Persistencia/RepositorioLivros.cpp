#include "RepositorioLivros.h"

RepositorioLivros::RepositorioLivros() {}

RepositorioLivros::~RepositorioLivros() {
    for (Livro* livro : dados) {
        delete livro;
    }
    dados.clear();
}

Livro* RepositorioLivros::buscarPorCodigo(int codigo) {
    for (Livro* livro : dados) {
        if (livro->getCodigo() == codigo) {
            return livro;
        }
    }
    return nullptr;
}

Livro* RepositorioLivros::buscarPorTitulo(const std::string& titulo) {
    for (Livro* livro : dados) {
        if (livro->getTitulo() == titulo) {
            return livro;
        }
    }
    return nullptr;
}

void RepositorioLivros::removerPorCodigo(int codigo) {
    for (auto it = dados.begin(); it != dados.end(); ++it) {
        if ((*it)->getCodigo() == codigo) {
            delete *it;
            dados.erase(it);
            return;
        }
    }
}

bool RepositorioLivros::existeLivro(int codigo) {
    return buscarPorCodigo(codigo) != nullptr;
}
