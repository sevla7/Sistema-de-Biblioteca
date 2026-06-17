#include "ItemEmprestimo.h"
#include "..\ExemplarLivro\ExemplarLivro.h"

ItemEmprestimo::ItemEmprestimo(int dataParaDevolucao, int dataQueFoiDevolvido, ExemplarLivro *exemplar, Emprestimo *emprestimo) : dataParaDevolucao(dataParaDevolucao), dataQueFoiDevolvido(dataQueFoiDevolvido), exemplar(exemplar), emprestimo(emprestimo) {}
ItemEmprestimo::ItemEmprestimo() : dataParaDevolucao(0), dataQueFoiDevolvido(0), exemplar(nullptr), emprestimo(nullptr) {}

int ItemEmprestimo::getDataParaDevolucao() const {
    return dataParaDevolucao;
}

int ItemEmprestimo::getDataQueFoiDevolvido() const {
    return dataQueFoiDevolvido;
}

ExemplarLivro* ItemEmprestimo::getExemplar() const {
    return exemplar;
}

Emprestimo* ItemEmprestimo::getEmprestimo() const {
    return emprestimo;
}

void ItemEmprestimo::setDataParaDevolucao(const int dataParaDevolucao) {
    this->dataParaDevolucao = dataParaDevolucao;
}

void ItemEmprestimo::setDataQueFoiDevolvido(const int dataQueFoiDevolvido) {
    this->dataQueFoiDevolvido = dataQueFoiDevolvido;
}

void ItemEmprestimo::setExemplar(ExemplarLivro* exemplar) {
    this->exemplar = exemplar;
}

void ItemEmprestimo::setEmprestimo(Emprestimo* emprestimo) {
    this->emprestimo = emprestimo;
}
