#include "ExemplarLivro.h"
#include "../Livro/Livro.h"
#include  <string>
using std::cout;
using std::endl;

ExemplarLivro::ExemplarLivro(int nroExemplar, Livro* l) : nroExemplar(nroExemplar), livro(l) {}
ExemplarLivro::ExemplarLivro() : nroExemplar(0), livro(nullptr) {}

int ExemplarLivro::getNroExemplar() const {
    return nroExemplar;
}

StatusEmprestimo ExemplarLivro::getStatus() const {
    return status;
}

Livro* ExemplarLivro::getLivro() const {
    return livro;
}

void ExemplarLivro::setNroExemplar(const int nroExemplar) {
    this->nroExemplar = nroExemplar;
}

void ExemplarLivro::setStatus(const StatusEmprestimo status) {
    this->status = status;
}

void ExemplarLivro::setLivro(Livro* l) {
    this->livro = l;
}
void ExemplarLivro::exibirInformacoes() {
    std::cout << "Número do exemplar: " << nroExemplar << std::endl;
    if (livro != nullptr) {
        std::cout << "Título do livro: " << livro->getTitulo() << std::endl;
    } else {
        std::cout << "Livro não associado." << std::endl;
    }
}