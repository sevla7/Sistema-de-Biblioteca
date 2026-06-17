#include "Livro.h"

Livro::Livro(int codigo,
             const string& titulo,
             int edicao,
             float preco,
             const Editora& editora,
             int ano,
             int quantidadeExemplares,
             int nroDiasPermitidoEmprestimo,
             const vector<Autor*>& autores,
             int statusAgora,
             int statusFuturo,
             int nroPaginas)
    : codigo(codigo),
      titulo(titulo),
      edicao(edicao),
      preco(preco),
      editora(editora),
      ano(ano),
      quantidadeExemplares(quantidadeExemplares),
      nroDiasPermitidoEmprestimo(nroDiasPermitidoEmprestimo),
      autores(autores),
      statusAgora(statusAgora),
      statusFuturo(statusFuturo),
      nroPaginas(nroPaginas)
{}

Livro::Livro() : codigo(0),
                 titulo(""),
                 edicao(0),
                 preco(0.0f),
                 ano(0),
                 quantidadeExemplares(0),
                 nroDiasPermitidoEmprestimo(7),
                 statusAgora(0),
                 statusFuturo(0),
                 nroPaginas(0) {}


string Livro::getTitulo() const {
    return titulo;
}

const vector<Autor*>& Livro::getAutores() const {
    return autores;
}

int Livro::getAno() const {
    return ano;
}

float Livro::getPreco() const {
    return preco;
}

Editora Livro::getEditora() const {
    return editora;
}

int Livro::getCodigo() const {
    return codigo;
}

int Livro::getEdicao() const {
    return edicao;
}

int Livro::getQuantidadeExemplares() const {
    return quantidadeExemplares;
}

int Livro::getNroDiasPermitidoEmprestimo() const {
    return nroDiasPermitidoEmprestimo;
}

int Livro::getStatusAgora() const {
    return statusAgora;
}

int Livro::getStatusFuturo() const {
    return statusFuturo;
}

int Livro::getNroPaginas() const {
    return nroPaginas;
}


void Livro::setTitulo(const string& t) {
    this->titulo = t;
}

void Livro::adicionarAutor(Autor* a) {
    this->autores.push_back(a);
}

void Livro::setAno(const int ano) {
  this->ano = ano;
}

void Livro::setPreco(const float p) {
  this->preco = p;
}

void Livro::setEditora(const Editora& e) {
    this->editora = e;
}

void Livro::setCodigo(const int c) {
    this->codigo = c;
}

void Livro::setEdicao(const int e) {
    this->edicao = e;
}

void Livro::setQuantidadeExemplares(const int q) {
    this->quantidadeExemplares = q;
}

void Livro::setNroDiasPermitidoEmprestimo(const int n) {
    this->nroDiasPermitidoEmprestimo = n;
}

void Livro::setStatusAgora(const int s) {
    this->statusAgora = s;
}

void Livro::setStatusFuturo(const int s) {
    this->statusFuturo = s;
}

void Livro::setNroPaginas(const int n) {
    this->nroPaginas = n;
}


void Livro::exibirInformacoes() {
    cout << "====INFORMAÇÕES DO LIVRO====\n";
    cout << "Código: " << codigo << "\n";
    cout << "Título: " << titulo << "\n";
    cout << "Edição: " << edicao << "\n";
    cout << "Preço: " << preco << "\n";
    cout << "Editora: " << editora.getNome() << "\n";
    cout << "Ano: " << ano << "\n";
    cout << "Quantidade de Exemplares: " << quantidadeExemplares << "\n";
    cout << "Dias de Empréstimo Permitidos: " << nroDiasPermitidoEmprestimo << "\n";
    cout << "Autores: ";
    if (autores.empty()) {
        cout << "Nenhum autor cadastrado.\n";
    } else {
        for (const auto& autor : autores) {
            cout << autor->getNome() << ", ";
        }
        cout << "\n";
    }
    cout << "Status Agora: " << statusAgora << "\n";
    cout << "Status Futuro: " << statusFuturo << "\n";
    cout << "Número de Páginas: " << nroPaginas << "\n";
    cout << "==============================\n";
}

bool Livro::estaDisponivel() {
    return quantidadeExemplares > 0;
}

Livro cadastraLivro() {
    Livro l;
    // Implementação de cadastro de livro, se necessário
    return l;
}