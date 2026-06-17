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
    livros.erase(std::remove(livros.begin(), livros.end(), livro), livros.end());
}

void Acervo::listarTodos() { 
    for (const auto& livro : livros) {
        livro->exibirInformacoes();
        cout << "" << endl;
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
        // Adicionado o '!' para negar a condição
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

void Acervo::removerLivroPorCodigo(int codigo) { 
    for(auto it = livros.begin(); it != livros.end(); ++it){
        if((*it)->getCodigo() == codigo){
            delete *it;
            livros.erase(it);
            cout << "Livro removido com sucesso." << endl;
            return;
        }
    }
    cout << "Livro nao encontrado." << endl;
}

void Acervo::criarExemplaresParaLivro(Livro* livro, int quantidade) {
    if (livro == nullptr) {
        cout << "Erro: Livro inválido para criar exemplares." << endl;
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
