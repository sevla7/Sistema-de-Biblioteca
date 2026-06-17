#include "..\emp\Emprestimo.h"
#include "..\Usuario\Usuario.h"
#include "..\Livro\Livro.h"
using std::cout;
using std::endl;

Emprestimo::Emprestimo(
    const int dataDeRetirada,
    const int DataPrevistaDevolucao,
    const int DataDevolucao,
    const int status,
    Usuario* usuario,
    Livro* livro) {

    this->dataDeRetirada = dataDeRetirada;
    this->DataPrevistaDevolucao = DataPrevistaDevolucao;
    this->DataDevolucao = DataDevolucao;
    this->status = status;
    this->usuario = usuario;
    this->livro = livro;
}

Emprestimo::Emprestimo() {
    this->dataDeRetirada = 0;
    this->DataPrevistaDevolucao = 0;
    this->DataDevolucao = 0;
    this->status = 0;
    this->usuario = nullptr;
}

int Emprestimo::getDataDeRetirada() const {
    return this->dataDeRetirada;
}

int Emprestimo::getDataPrevistaDevolucao() const {
    return this->DataPrevistaDevolucao;
}

int Emprestimo::getDataDevolucao() const {
    return this->DataDevolucao;
}

int Emprestimo::getStatus() const {
    return this->status;
}

Usuario Emprestimo::getUsuario() const {
    return *(this->usuario);
}

Livro* Emprestimo::getLivro() const {
    return livro;
}

void Emprestimo::setDataDeRetirada(const int dataDeRetirada) {
    this->dataDeRetirada = dataDeRetirada;
}

void Emprestimo::setDataPrevistaDevolucao(const int DataPrevistaDevolucao) {
    this->DataPrevistaDevolucao = DataPrevistaDevolucao;
}

void Emprestimo::setDataDevolucao(const int DataDevolucao) {
    this->DataDevolucao = DataDevolucao;
}

void Emprestimo::setStatus(const int status) {
    this->status = status;
}

void Emprestimo::setUsuario(const Usuario& usuario) {
    *(this->usuario) = usuario;
}

void Emprestimo::exibirInformacoes() {
    cout << "====INFORMAÇÕES DO EMPRÉSTIMO====" << endl;
    cout << "Data de Retirada: " << this->dataDeRetirada << endl;
    cout << "Data Prevista de Devolucao: " << this->DataPrevistaDevolucao << endl;
    cout << "Data de Devolucao: " << this->DataDevolucao << endl;
    cout << "Status: " << this->status << endl;
    cout << "Usuario: " << this->usuario->getNome() << endl;
    cout << "Livro: "
     << livro->getTitulo()
     << endl;
}