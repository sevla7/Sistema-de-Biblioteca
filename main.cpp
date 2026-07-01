#include "autor/Autor.h"
#include "editora/Editora.h"
#include "emp/Emprestimo.h"
#include "endereco/Endereco.h"
#include "Livro/Livro.h"
#include "Usuario/Usuario.h"
#include "itemEmp/ItemEmprestimo.h"
#include "ExemplarLivro/ExemplarLivro.h"
#include "ExemplarLivro/StatusEmprestimo.h"
#include "Gerenciadores/GerenciadorEmprestimos.h"
#include "Gerenciadores/GerenciadorCadastro.h"
#include "Reserva/Reserva.h"
#include "Reserva/ItemReserva.h"
#include "acervo/Acervo.h"
#include "Usuario/Aluno.h"
#include "Usuario/Professor.h"
#include "Menu/menu.h"
#include <locale.h>
#include <windows.h>
#include <iostream>
#include <vector>
#include <limits>
#include <stdexcept>

using namespace std;

int getSafeIntegerInput() {
    int value;
    while (!(cin >> value)) {
        cout << "Entrada inválida. Por favor, digite um número: ";
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return value;
}

float getSafeFloatInput() {
    float value;
    while (!(cin >> value)) {
        cout << "Entrada inválida. Por favor, digite um número decimal: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return value;
}

string getSafeStringInput() {
    string value;
    getline(cin, value);
    return value;
}

int main() {
    vector<Reserva*> reservas;
    SetConsoleOutputCP(65001);
    setlocale(LC_ALL, "Portuguese_Brazil");

    int opcao;

    do {
        exibirMenu();
        opcao = getSafeIntegerInput();

        try {
            switch(opcao) {

            case 1: { // CADASTRO
                int opcCadastro;

                cout << "\nCADASTRAR\n";
                cout << "1. Livro\n";
                cout << "2. Autor\n";
                cout << "3. Aluno\n";
                cout << "4. Professor\n";
                cout << "5. Editora\n";
                cout << "Opcao: ";

                opcCadastro = getSafeIntegerInput();
                cout << endl;

                switch(opcCadastro) {

                case 1: { // CADASTRAR LIVRO
                    int c, e, a, qtdExe, pag, idEditora;
                    string t;
                    float p;
                    int diasEmp = 7; 

                    cout << "Digite o código: " << endl;
                    c = getSafeIntegerInput();

                    if (Acervo::buscarLivro(c) != nullptr) {
                        throw runtime_error("[ERRO] Livro com o código fornecido já existe!");
                    }

                    cout << "Digite o título: " << endl;
                    t = getSafeStringInput();

                    cout << "Digite a edição: " << endl;
                    e = getSafeIntegerInput();

                    cout << "Digite o preço: " << endl;
                    p = getSafeFloatInput();

                    cout << "Digite o id da editora: " << endl;
                    idEditora = getSafeIntegerInput();
                    
                    Editora* editora = GerenciadorCadastro::verificaEditora(idEditora);
                    if (editora == nullptr) {
                        throw runtime_error("[ERRO] Editora não encontrada! Cadastre a editora primeiro.");
                    }

                    cout << "Digite o ano: " << endl;
                    a = getSafeIntegerInput();

                    cout << "Quantidade de exemplares: " << endl;
                    qtdExe = getSafeIntegerInput();

                    // --- LÓGICA DE AUTORES ---
                    vector<Autor*> autoresDoLivro;
                    int qtdAutores;
                    cout << "Quantos autores tem o livro? ";
                    qtdAutores = getSafeIntegerInput();

                    for(int i = 0; i < qtdAutores; i++) {
                        int idAutor;
                        cout << "Digite o ID do autor " << (i + 1) << ": ";
                        idAutor = getSafeIntegerInput();
                        Autor* aut = GerenciadorCadastro::verificaAutor(idAutor);
                        
                        if(aut == nullptr) {
                            throw runtime_error("[ERRO] Autor com o ID especificado não foi encontrado!");
                        }
                        autoresDoLivro.push_back(aut);
                    }

                    if (autoresDoLivro.empty()) { 
                        throw runtime_error("[ERRO] É necessário pelo menos um autor válido para cadastrar o livro.");
                    }

                    cout << "Número de páginas: " << endl;
                    pag = getSafeIntegerInput();

                    Livro* livro = new Livro(c, t, e, p, *editora, a, 0, diasEmp, autoresDoLivro, 1, 1, pag);
                    Acervo::acrecentarLivro(livro);
                    Acervo::criarExemplaresParaLivro(livro, qtdExe);

                    cout << "\nLivro cadastrado com sucesso!\n";
                    break;
                }

                case 2: { // CADASTRAR AUTOR
                    int idAutor;
                    cout << "Digite o ID do autor: ";
                    idAutor = getSafeIntegerInput();
                    
                    Autor* aut = GerenciadorCadastro::verificaAutor(idAutor);
                    if(aut != nullptr) {
                        throw runtime_error("[ERRO] Autor com o ID informado já existe!");
                    } 
                    
                    Autor autor_obj = cadastraAutor(idAutor);
                    Autor* autor = new Autor(autor_obj);
                    GerenciadorCadastro::adicionarAutor(autor); 
                    cout << "\nAutor cadastrado com sucesso!\n";
                    break;
                }

                case 3: { // CADASTRAR ALUNO
                    int idUsuario;
                    cout << "Digite o ID do aluno: ";
                    idUsuario = getSafeIntegerInput();
                    
                    Usuario* user = GerenciadorCadastro::verificaUsuario(idUsuario);
                    if(user != nullptr) {
                        throw runtime_error("[ERRO] Usuário com o ID informado já existe!");
                    } 
                    
                    Aluno aluno_obj = cadastraAluno(idUsuario);
                    Aluno* aluno = new Aluno(aluno_obj);
                    GerenciadorCadastro::adicionarUsuario(aluno); 
                    cout << "Aluno cadastrado com sucesso!" << endl;
                    break;
                }

                case 4: { // CADASTRAR PROFESSOR
                    int idUsuario;
                    cout << "Digite o ID do professor: ";
                    idUsuario = getSafeIntegerInput();
                    
                    Usuario* user = GerenciadorCadastro::verificaUsuario(idUsuario);
                    if(user != nullptr) {
                        throw runtime_error("[ERRO] Usuário com o ID informado já existe!");
                    }
                    
                    Professor professor_obj = cadastraProfessor(idUsuario);
                    Professor* professor = new Professor(professor_obj);
                    GerenciadorCadastro::adicionarUsuario(professor); 
                    cout << "Professor cadastrado com sucesso!" << endl;
                    break;
                }

                case 5: { // CADASTRAR EDITORA
                    int idEditora;
                    cout << "Digite o ID da editora: ";
                    idEditora = getSafeIntegerInput();
                    
                    Editora* editora = GerenciadorCadastro::verificaEditora(idEditora);
                    if(editora != nullptr) {
                        throw runtime_error("[ERRO] Editora com o ID informado já existe!");
                    }
                    
                    Editora editora_obj = cadastraEditora(idEditora);
                    Editora* novaEditora = new Editora(editora_obj);
                    GerenciadorCadastro::adicionarEditora(novaEditora); 
                    cout << "\nEditora cadastrada com sucesso!\n";
                    break;
                }

                default:
                    cout << "\nOpção inválida no menu de cadastro!" << endl;
                }
                break;
            }

            case 2: { // EDITAR LIVRO
                int codigo;
                cout << "\nCodigo do livro: ";
                codigo = getSafeIntegerInput();

                Livro* livro = Acervo::buscarLivro(codigo);
                if (livro == nullptr) {
                    throw runtime_error("[ERRO] Livro não encontrado.");
                } 

                string novoTitulo;
                cout << "Novo titulo: ";
                novoTitulo = getSafeStringInput();
                livro->setTitulo(novoTitulo);
                cout << "\nLivro atualizado com sucesso!" << endl;
                break;
            }

            case 3: { // REMOVER LIVRO
                int codigo;
                cout << "\nCodigo do livro a remover: ";
                codigo = getSafeIntegerInput();
                Acervo::removerLivroPorCodigo(codigo);
                break;
            }

            case 4: { // RESERVA
                int idReserva, dataReserva, dataRetirada, codigoLivro, idUsuario;

                cout << "\n=== CRIAR RESERVA ===\n";
                cout << "ID da reserva: "; idReserva = getSafeIntegerInput();
                cout << "Data da reserva: "; dataReserva = getSafeIntegerInput();
                cout << "Data para retirada: "; dataRetirada = getSafeIntegerInput();
                cout << "ID do usuario: "; idUsuario = getSafeIntegerInput();

                Usuario* usuario = GerenciadorCadastro::verificaUsuario(idUsuario);
                if(usuario == nullptr){
                    throw runtime_error("[ERRO] Usuário não encontrado.");
                }
                cout << "Usuário: " << usuario->getNome()  << endl;

                cout << "Codigo do livro: ";
                codigoLivro = getSafeIntegerInput();

                Livro* livro = Acervo::buscarLivro(codigoLivro);
                if(livro == nullptr){
                    throw runtime_error("[ERRO] Livro não encontrado.");
                }

                ExemplarLivro* exemplarDisponivel = nullptr;
                bool exemplarJaReservadoParaData = false;

                for (ExemplarLivro* ex : Acervo::getListaExemplares()) {
                    if (ex->getLivro() == livro) {
                        bool isReserved = false;
                        for (Reserva* r : reservas) {
                            for (ItemReserva* item : r->getItems()) {
                                if (item->getExemplar() == ex && item->getDataDeRetirada() == dataRetirada) {
                                    isReserved = true;
                                    exemplarJaReservadoParaData = true;
                                    break;
                                }
                            }
                            if (isReserved) break;
                        }
                        if (!isReserved) {
                            exemplarDisponivel = ex;
                        }
                    }
                }

                if (exemplarDisponivel == nullptr) {
                    if (exemplarJaReservadoParaData) {
                        throw runtime_error("[ERRO] Nenhum exemplar disponível para a data informada (Já reservados).");
                    } else {
                        throw runtime_error("[ERRO] Nenhum exemplar disponível para este livro.");
                    }
                }

                Reserva* reserva = new Reserva(idReserva, dataReserva, usuario);
                ItemReserva* item = new ItemReserva(1, dataRetirada, exemplarDisponivel);

                reserva->adicionarItem(item);
                reservas.push_back(reserva);

                cout << "\nReserva criada com sucesso para o exemplar " << exemplarDisponivel->getNroExemplar() << "!\n";
                break;
            }

            case 5: { // EMPRÉSTIMO
                int codigoLivro, idUsuario;
                cout << "\nCRIAR EMPRESTIMO\n";
                cout << "Codigo do livro: "; codigoLivro = getSafeIntegerInput();
                cout << "ID do usuario: "; idUsuario = getSafeIntegerInput();

                Livro* livro = Acervo::buscarLivro(codigoLivro);
                Usuario* usuario = GerenciadorCadastro::verificaUsuario(idUsuario);

                if (livro == nullptr || usuario == nullptr) {
                    throw runtime_error("[ERRO] Livro ou Usuário não encontrados para efetuar empréstimo.");
                }

                GerenciadorEmprestimos::CriarEmprestimo(usuario, livro);
                break;
            }

            case 6: { // CONSULTAS
                int opcConsulta;
                exibirSubMenuConsultar();
                opcConsulta = getSafeIntegerInput();
                cout << endl;

                switch(opcConsulta) {
                case 1:
                    Acervo::listarTodos();
                    break;
                case 2:
                    for(Autor* autor : GerenciadorCadastro::getAutores()) {
                        autor->exibirInformacoes();
                        cout << endl;
                    }
                    break;
                case 3:
                    for(Usuario* usuario : GerenciadorCadastro::getUsuarios()) {
                        usuario->exibirInformacoes();
                        cout << endl;
                    }
                    break;
                case 4:
                    if(reservas.empty()){
                        cout << "\nNenhuma reserva cadastrada." << endl;
                    } else {
                        for(Reserva* reserva : reservas){
                            reserva->exibirInformacoes();
                            cout << endl;
                        }
                    }
                    break;
                case 5: {
                    int id;
                    cout << "\nDigite o ID do usuario: ";
                    id = getSafeIntegerInput();
                    bool encontrou = false;

                    for(Reserva* r : reservas){
                        if(r->getUsuario() != nullptr && r->getUsuario()->getID() == id){
                            r->exibirInformacoes();
                            encontrou = true;
                        }
                    }
                    if(!encontrou){
                        cout << "Nenhuma reserva encontrada para esse usuario." << endl;
                    }
                    break;
                }
                case 6: {
                    int id;
                    cout << "\nDigite o ID do usuário: ";
                    id = getSafeIntegerInput();
                    GerenciadorEmprestimos::listarEmprestimosPorUsuario(id);
                    break;
                }
                case 7:
                    GerenciadorEmprestimos::listarTodosEmprestimosAtuais();
                    break;
                default:
                    cout << "\nOpcao invalida!" << endl;
                }
                break;
            }

            case 7:
                cout << "\nEncerrando sistema..." << endl;
                break;

            default:
                cout << "\nOpcao invalida!" << endl;
            }

        } 
        catch (const runtime_error& e) {
            cout << "\n----------------------------------------" << endl;
            cout << e.what() << endl;
            cout << "Retornando ao menu principal..." << endl;
            cout << "----------------------------------------\n" << endl;
        }

    } while(opcao != 7);

    // Liberação de memória
    for(Autor* autor : GerenciadorCadastro::getAutores()) delete autor; 
    for(Usuario* usuario : GerenciadorCadastro::getUsuarios()) delete usuario; 
    for(Editora* editora : GerenciadorCadastro::getEditoras()) delete editora; 
    for(Livro* livro : Acervo::getListaLivros()) delete livro;
    for(ExemplarLivro* exemplar : Acervo::getListaExemplares()) delete exemplar;
    for(Reserva* reserva : reservas) delete reserva;

    return 0;
}