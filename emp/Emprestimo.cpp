#include "..\emp\Emprestimo.h"
#include "..\Usuario\Usuario.h"
#include "..\Livro\Livro.h"
#include "..\ExemplarLivro\ExemplarLivro.h"
using std::cout;
using std::endl;

int Emprestimo::nextId = 1;

Emprestimo::Emprestimo(
    const int dataDeRetirada,
    const int DataPrevistaDevolucao,
    const int DataDevolucao,
    const int status,
    Usuario* usuario,
    Livro* livro,
    ExemplarLivro* exemplar,
    int id) {

    this->dataDeRetirada = dataDeRetirada;
    this->DataPrevistaDevolucao = DataPrevistaDevolucao;
    this->DataDevolucao = DataDevolucao;
    this->status = status;
    this->usuario = usuario;
    this->livro = livro;
    this->exemplar = exemplar;
    if (id != 0) this->id = id; else this->id = nextId++;
}

Emprestimo::Emprestimo() {
    this->dataDeRetirada = 0;
    this->DataPrevistaDevolucao = 0;
    this->DataDevolucao = 0;
    this->status = 0;
    this->usuario = nullptr;
    this->livro = nullptr;
    this->exemplar = nullptr;
    this->id = nextId++;
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

Usuario* Emprestimo::getUsuario() const {
    return this->usuario;
}

Livro* Emprestimo::getLivro() const {
    return livro;
}

ExemplarLivro* Emprestimo::getExemplar() const {
    return exemplar;
}

int Emprestimo::getId() const {
    return id;
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

void Emprestimo::setUsuario(Usuario* usuario) {
    this->usuario = usuario;
}

void Emprestimo::setExemplar(ExemplarLivro* exemplar) {
    this->exemplar = exemplar;
}

void Emprestimo::setId(int id) {
    this->id = id;
}

void Emprestimo::exibirInformacoes() {
    cout << "====INFORMACOES DO EMPRESTIMO====" << endl;
    cout << "ID do Emprestimo: " << this->id << endl;
    cout << "Data de Retirada: " << this->dataDeRetirada << endl;
    cout << "Data Prevista de Devolucao: " << this->DataPrevistaDevolucao << endl;
    cout << "Data de Devolucao: " << this->DataDevolucao << endl;
    cout << "Status: " << this->status << endl;
    cout << "Usuario: " << this->usuario->getNome() << endl;
    cout << "Livro: "
     << livro->getTitulo()
     << endl;
}