#include "GerenciadorEmprestimos.h"
#include "..\acervo\Acervo.h"
#include "..\ExemplarLivro\StatusEmprestimo.h"

vector<Emprestimo*> GerenciadorEmprestimos::emprestimos;

void GerenciadorEmprestimos::CriarEmprestimo(
    Usuario* usuario,
    Livro* livroDesejado) {
    if(livroDesejado == nullptr){
        cout << "Livro nao encontrado." << endl;
        return;
    }

    if(usuario == nullptr){
        cout << "Usuario nao encontrado." << endl;
        return;
    }

    if(!livroDesejado->estaDisponivel()){
        cout << "Nao ha exemplares disponiveis." << endl;
        return;
    }

    livroDesejado->setQuantidadeExemplares(
        livroDesejado->getQuantidadeExemplares() - 1
    );

    ExemplarLivro* exemplarDisponivel = nullptr;
    for (ExemplarLivro* ex : Acervo::getListaExemplares()) {
        if (ex->getLivro() == livroDesejado && ex->getStatus() == StatusEmprestimo::DISPONIVEL) {
            exemplarDisponivel = ex;
            break;
        }
    }

    if (exemplarDisponivel == nullptr) {
        cout << "Nenhum exemplar disponivel para emprestimo." << endl;
        return;
    }

    exemplarDisponivel->setStatus(StatusEmprestimo::EMPRESTADO);

    Emprestimo* novoEmprestimo =
        new Emprestimo(
            10062026,
            17062026,
            0,
            1,
            usuario,
            livroDesejado,
            exemplarDisponivel
        );

    emprestimos.push_back(novoEmprestimo);

    cout << "\nEmprestimo criado com sucesso!\n";
    cout << "Livro: "   << livroDesejado->getTitulo() << endl;
    cout << "Usuario: " << usuario->getNome()         << endl;
}

bool GerenciadorEmprestimos::devolverEmprestimo(int idUsuario, int codigoLivro, int dataDevolucao) {
    for (Emprestimo* emprestimo : emprestimos) {
        if (emprestimo->getUsuario() != nullptr &&
            emprestimo->getUsuario()->getID() == idUsuario &&
            emprestimo->getLivro() != nullptr &&
            emprestimo->getLivro()->getCodigo() == codigoLivro &&
            emprestimo->getDataDevolucao() == 0) {

            emprestimo->setDataDevolucao(dataDevolucao);
            emprestimo->setStatus(0);

            ExemplarLivro* exemplar = emprestimo->getExemplar();
            if (exemplar != nullptr) {
                exemplar->setStatus(StatusEmprestimo::DISPONIVEL);
            }

            Livro* livro = emprestimo->getLivro();
            if (livro != nullptr) {
                livro->setQuantidadeExemplares(livro->getQuantidadeExemplares() + 1);
            }

            cout << "\nEmprestimo devolvido com sucesso!\n";
            return true;
        }
    }

    cout << "\nEmprestimo ativo nao encontrado para o usuario e livro informados." << endl;
    return false;
}

const vector<Emprestimo*>& GerenciadorEmprestimos::getEmprestimos() {
    return emprestimos;
}

Emprestimo* GerenciadorEmprestimos::buscarEmprestimoPorId(int idEmprestimo) {
    for (Emprestimo* e : emprestimos) {
        if (e != nullptr && e->getId() == idEmprestimo) return e;
    }
    return nullptr;
}

bool GerenciadorEmprestimos::devolverEmprestimoPorId(int idEmprestimo, int dataDevolucao) {
    Emprestimo* e = buscarEmprestimoPorId(idEmprestimo);
    if (e == nullptr) {
        cout << "\nEmprestimo com ID informado nao encontrado." << endl;
        return false;
    }

    if (e->getDataDevolucao() != 0) {
        cout << "\nEmprestimo ja foi devolvido." << endl;
        return false;
    }

    e->setDataDevolucao(dataDevolucao);
    e->setStatus(0);

    ExemplarLivro* exemplar = e->getExemplar();
    if (exemplar != nullptr) exemplar->setStatus(StatusEmprestimo::DISPONIVEL);

    Livro* livro = e->getLivro();
    if (livro != nullptr) livro->setQuantidadeExemplares(livro->getQuantidadeExemplares() + 1);

    cout << "\nEmprestimo (ID " << idEmprestimo << ") devolvido com sucesso!" << endl;
    return true;
}

void GerenciadorEmprestimos::listarTodosEmprestimosAtuais() {
    if (emprestimos.empty()) {
        cout << "Nenhum emprestimo registrado." << endl;
        return;
    }

    for (size_t i = 0; i < emprestimos.size(); i++) {
        cout << "Emprestimo " << i + 1 << ":" << endl;
        emprestimos[i]->exibirInformacoes();
        cout << endl;
    }
}

void GerenciadorEmprestimos::listarEmprestimosPorUsuario(int idUsuario) {
    bool encontrou = false;
    if (emprestimos.empty()) {
        cout << "Nenhum emprestimo registrado." << endl;
        return;
    }

    for (Emprestimo* emprestimo : emprestimos) {
        if (emprestimo->getUsuario()->getID() == idUsuario) {
            emprestimo->exibirInformacoes();
            encontrou = true;
        }
    }

    if (!encontrou) {
        cout << "Nenhum emprestimo encontrado para o usuario com ID: " << idUsuario << endl;
    }
}