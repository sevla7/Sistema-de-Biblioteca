#include "GerenciadorEmprestimos.h"

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

    Emprestimo* novoEmprestimo =
        new Emprestimo(
            10062026,
            17062026,
            0,
            1,
            usuario,
            livroDesejado
        );

    emprestimos.push_back(novoEmprestimo);

    cout << "\nEmprestimo criado com sucesso!\n";
    cout << "Livro: "   << livroDesejado->getTitulo() << endl;
    cout << "Usuario: " << usuario->getNome()         << endl;
}

void GerenciadorEmprestimos::listarTodosEmprestimosAtuais() {
    if (emprestimos.empty()) {
        cout << "Nenhum empréstimo registrado." << endl;
        return;
    }

    for (size_t i = 0; i < emprestimos.size(); i++) {
        cout << "Empréstimo " << i + 1 << ":" << endl;
        emprestimos[i]->exibirInformacoes();
        cout << endl;
    }
}

void GerenciadorEmprestimos::listarEmprestimosPorUsuario(int idUsuario) {
    bool encontrou = false;
    if (emprestimos.empty()) {
        cout << "Nenhum empréstimo registrado." << endl;
        return;
    }

    for (Emprestimo* emprestimo : emprestimos) {
        if (emprestimo->getUsuario().getID() == idUsuario) {
            emprestimo->exibirInformacoes();
            encontrou = true;
        }
    }

    if (!encontrou) {
        cout << "Nenhum empréstimo encontrado para o usuário com ID: " << idUsuario << endl;
    }
}