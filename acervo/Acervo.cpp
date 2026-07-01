#include "Acervo.h"
#include <iostream>
#include "..\ExemplarLivro\StatusEmprestimo.h" 

vector<Livro*> Acervo::livros;
vector<ExemplarLivro*> Acervo::listaExemplares;

void Acervo::acrecentarLivro(Livro* livro) { 
    if (livro != nullptr) {
        livros.push_back(livro);
    }
}

void Acervo::removerLivro(Livro* livro) { 
    if (livro == nullptr) {
        return;
    }

    livros.erase(std::remove(livros.begin(), livros.end(), livro), livros.end());

    for (auto it = listaExemplares.begin(); it != listaExemplares.end();) {
        if ((*it)->getLivro() == livro) {
            delete *it;
            it = listaExemplares.erase(it);
        } else {
            ++it;
        }
    }
}

void Acervo::listarTodos() {
    if (livros.empty()) {
        cout << "\nNenhum livro cadastrado no acervo." << endl;
        return;
    }
    
    cout << "\n========== LIVROS CADASTRADOS ==========" << endl;
    for (const auto& livro : livros) {
        livro->exibirInformacoes();
    }
}

void Acervo::LivrosDisponiveis() { 
    for (const auto& livro : livros) {
        if (livro->estaDisponivel()) {
            livro->exibirInformacoes();
        }
    }
}

void Acervo::LivrosIndisponiveis() { 
    for (const auto& livro : livros) {
        // Adicionado o '!' para negar a condicao
        if (!livro->estaDisponivel()) {
            livro->exibirInformacoes();
        }
    }
}

Livro* Acervo::buscarLivro(int codigo) { 
    for (Livro* livro : livros) {
        if (livro->getCodigo() == codigo) {
            return livro;
        }
    }
    return nullptr;
}

Livro* Acervo::buscarLivroPorTitulo(const std::string& titulo) {
    for (Livro* livro : livros) {
        if (livro->getTitulo() == titulo) {
            return livro;
        }
    }
    return nullptr;
}

void Acervo::removerLivroPorCodigo(int codigo) { 
    for (auto it = livros.begin(); it != livros.end(); ++it) {
        if ((*it)->getCodigo() == codigo) {
            Livro* livroRemovido = *it;
            livros.erase(it);

            for (auto exemplarIt = listaExemplares.begin(); exemplarIt != listaExemplares.end();) {
                if ((*exemplarIt)->getLivro() == livroRemovido) {
                    delete *exemplarIt;
                    exemplarIt = listaExemplares.erase(exemplarIt);
                } else {
                    ++exemplarIt;
                }
            }

            delete livroRemovido;
            cout << "Livro removido com sucesso." << endl;
            return;
        }
    }
    cout << "Livro nao encontrado." << endl;
}

void Acervo::criarExemplaresParaLivro(Livro* livro, int quantidade) {
    if (livro == nullptr) {
        cout << "Erro: Livro invalido para criar exemplares." << endl;
        return;
    }
    for (int i = 0; i < quantidade; ++i) {
        static int nextExemplarNum = 1; 
        ExemplarLivro* novoExemplar = new ExemplarLivro(nextExemplarNum++, livro);
        novoExemplar->setStatus(StatusEmprestimo::DISPONIVEL); 
        listaExemplares.push_back(novoExemplar);
        livro->setQuantidadeExemplares(livro->getQuantidadeExemplares() + 1); 
    }
    cout << quantidade << " exemplares adicionados para o livro '" << livro->getTitulo() << "'." << endl;
}

ExemplarLivro* Acervo::buscarExemplar(int nroExemplar) {
    for (ExemplarLivro* exemplar : listaExemplares) {
        if (exemplar->getNroExemplar() == nroExemplar) {
            return exemplar;
        }
    }
    return nullptr;
}

const std::vector<ExemplarLivro*>& Acervo::getListaExemplares() {
    return listaExemplares;
}

const std::vector<Livro*>& Acervo::getListaLivros() {
    return livros;
}
