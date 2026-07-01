#include <windows.h>
#include <iostream>
#include <vector>
#include <limits>
#include <stdexcept>
#include <locale.h>
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
#include "apresentacao/LogoSistema.h"
#include "apresentacao/Inicializador.h"
#include "Negocio/RegrasNegocio.h"

using namespace std;

int getSafeIntegerInput() {
    int value;
    while (!(cin >> value)) {
        cout << "Entrada invalida. Por favor, digite um numero: ";
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return value;
}

float getSafeFloatInput() {
    float value;
    while (!(cin >> value)) {
        cout << "Entrada invalida. Por favor, digite um numero decimal: ";
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

    // ===== APRESENTACAO DO SISTEMA =====
    LogoSistema::exibirLogo();
    LogoSistema::exibirMensagemBemVindo();
    LogoSistema::exibirCarregando();
    
    // ===== CARREGAR DADOS PRE-CADASTRADOS =====
    Inicializador::carregarDadosPrecadastrados();
    
    // DESCOMENTE A LINHA ABAIXO PARA VER OS DADOS CARREGADOS
    // Inicializador::exibirDadosCarregados();

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

                    cout << "Digite o codigo: " << endl;
                    c = getSafeIntegerInput();

                    // USAR REGRA DE NEGOCIO: Verificar duplicacao
                    if (RegrasNegocio::livroJaExiste(c, Acervo::getListaLivros())) {
                        throw runtime_error("[ERRO] Livro com este codigo ja existe! Cadastros duplicados nao sao permitidos.");
                    }

                    cout << "Digite o titulo: " << endl;
                    t = getSafeStringInput();

                    cout << "Digite a edicao: " << endl;
                    e = getSafeIntegerInput();

                    cout << "Digite o preco: " << endl;
                    p = getSafeFloatInput();

                    cout << "Digite o id da editora: " << endl;
                    idEditora = getSafeIntegerInput();
                    
                    Editora* editora = GerenciadorCadastro::verificaEditora(idEditora);
                    if (editora == nullptr) {
                        throw runtime_error("[ERRO] Editora nao encontrada! Cadastre a editora primeiro.");
                    }

                    cout << "Digite o ano: " << endl;
                    a = getSafeIntegerInput();

                    cout << "Quantidade de exemplares: " << endl;
                    qtdExe = getSafeIntegerInput();

                    // --- LOGICA DE AUTORES ---
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
                            throw runtime_error("[ERRO] Autor com o ID especificado nao foi encontrado!");
                        }
                        autoresDoLivro.push_back(aut);
                    }

                    if (autoresDoLivro.empty()) { 
                        throw runtime_error("[ERRO] E necessario pelo menos um autor valido para cadastrar o livro.");
                    }

                    cout << "Numero de paginas: " << endl;
                    pag = getSafeIntegerInput();

                    Livro* livro = new Livro(c, t, e, p, *editora, a, 0, diasEmp, autoresDoLivro, 1, 1, pag);
                    Acervo::acrecentarLivro(livro);
                    Acervo::criarExemplaresParaLivro(livro, qtdExe);

                    cout << "\nLivro cadastrado com sucesso!\n";
                    break;
                }

                case 2: { // CADASTRAR AUTOR
                    int idAutor;
                    string nomeAutor;

                    cout << "Digite o ID do autor: ";
                    idAutor = getSafeIntegerInput();
                    
                    // USAR REGRA DE NEGOCIO: Verificar duplicacao
                    if (RegrasNegocio::autorJaExiste(idAutor, GerenciadorCadastro::getAutores())) {
                        throw runtime_error("[ERRO] Autor com este ID ja existe! Nao e permitido cadastro duplicado.");
                    }

                    cout << "Digite o nome do autor: ";
                    nomeAutor = getSafeStringInput();
                    
                    if(GerenciadorCadastro::buscarAutorPorNome(nomeAutor) != nullptr) {
                        throw runtime_error("[ERRO] Autor com este nome ja existe!");
                    }

                    Autor autor_obj = cadastraAutor(idAutor, nomeAutor);
                    Autor* autor = new Autor(autor_obj);
                    GerenciadorCadastro::adicionarAutor(autor); 
                    cout << "\nAutor cadastrado com sucesso!\n";
                    break;
                }

                case 3: { // CADASTRAR ALUNO
                    int idUsuario;
                    string nomeAluno;
                    cout << "Digite o ID do aluno: ";
                    idUsuario = getSafeIntegerInput();
                    
                    // USAR REGRA DE NEGOCIO: Verificar duplicacao
                    if (RegrasNegocio::usuarioJaExiste(idUsuario, GerenciadorCadastro::getUsuarios())) {
                        throw runtime_error("[ERRO] Usuario com este ID ja existe! Nao e permitido ID duplicado.");
                    }
                    
                    Aluno aluno_obj = cadastraAluno(idUsuario, nomeAluno);
                    Aluno* aluno = new Aluno(aluno_obj);
                    GerenciadorCadastro::adicionarUsuario(aluno); 
                    cout << "Aluno cadastrado com sucesso!" << endl;
                    break;
                }

                case 4: { // CADASTRAR PROFESSOR
                    int idUsuario;
                    string nomeProfessor;
                    cout << "Digite o ID do professor: ";
                    idUsuario = getSafeIntegerInput();
                    
                    // USAR REGRA DE NEGOCIO: Verificar duplicacao
                    if (RegrasNegocio::usuarioJaExiste(idUsuario, GerenciadorCadastro::getUsuarios())) {
                        throw runtime_error("[ERRO] Usuario com este ID ja existe! Nao e permitido ID duplicado.");
                    }
                    
                    Professor professor_obj = cadastraProfessor(idUsuario, nomeProfessor);
                    Professor* professor = new Professor(professor_obj);
                    GerenciadorCadastro::adicionarUsuario(professor); 
                    cout << "Professor cadastrado com sucesso!" << endl;
                    break;
                }

                case 5: { // CADASTRAR EDITORA
                    int idEditora;
                    string nomeEditora;

                    cout << "Digite o ID da editora: ";
                    idEditora = getSafeIntegerInput();
                    
                    // USAR REGRA DE NEGOCIO: Verificar duplicacao
                    if (RegrasNegocio::editoraJaExiste(idEditora, GerenciadorCadastro::getEditoras())) {
                        throw runtime_error("[ERRO] Editora com este ID ja existe! Nao e permitido ID duplicado.");
                    }
                    
                    Editora editora_obj = cadastraEditora(idEditora, nomeEditora);
                    Editora* novaEditora = new Editora(editora_obj);
                    GerenciadorCadastro::adicionarEditora(novaEditora); 
                    cout << "\nEditora cadastrada com sucesso!\n";
                    break;
                }

                default:
                    cout << "\nOpcao invalida no menu de cadastro!" << endl;
                }
                break;
            }

            case 2: { // EDITAR LIVRO
                int codigo;
                cout << "\nCodigo do livro: ";
                codigo = getSafeIntegerInput();

                Livro* livro = Acervo::buscarLivro(codigo);
                if (livro == nullptr) {
                    throw runtime_error("[ERRO] Livro nao encontrado.");
                }

                int opcEditar = -1;
                do {
                    cout << "\n== Editar Livro (Codigo: " << livro->getCodigo() << ") ==\n";
                    cout << "1 - Titulo (atual: " << livro->getTitulo() << ")\n";
                    cout << "2 - Edicao (atual: " << livro->getEdicao() << ")\n";
                    cout << "3 - Preco (atual: " << livro->getPreco() << ")\n";
                    cout << "4 - Editora (atual: " << livro->getEditora().getNome() << ")\n";
                    cout << "5 - Ano (atual: " << livro->getAno() << ")\n";
                    cout << "6 - Dias permitidos para emprestimo (atual: " << livro->getNroDiasPermitidoEmprestimo() << ")\n";
                    cout << "7 - Numero de paginas (atual: " << livro->getNroPaginas() << ")\n";
                    cout << "8 - Adicionar autor\n";
                    cout << "0 - Sair do editor\n";
                    cout << "Opcao: ";
                    opcEditar = getSafeIntegerInput();

                    switch(opcEditar) {
                        case 1: {
                            cout << "Novo titulo: ";
                            string novoTitulo = getSafeStringInput();
                            livro->setTitulo(novoTitulo);
                            cout << "Titulo atualizado.\n";
                            break;
                        }
                        case 2: {
                            cout << "Nova edicao: ";
                            int ed = getSafeIntegerInput();
                            livro->setEdicao(ed);
                            cout << "Edicao atualizada.\n";
                            break;
                        }
                        case 3: {
                            cout << "Novo preco: ";
                            float preco = getSafeFloatInput();
                            livro->setPreco(preco);
                            cout << "Preco atualizado.\n";
                            break;
                        }
                        case 4: {
                            cout << "ID da nova editora: ";
                            int idEditora = getSafeIntegerInput();
                            Editora* editora = GerenciadorCadastro::verificaEditora(idEditora);
                            if (editora == nullptr) {
                                cout << "Editora nao encontrada.\n";
                            } else {
                                livro->setEditora(*editora);
                                cout << "Editora atualizada.\n";
                            }
                            break;
                        }
                        case 5: {
                            cout << "Novo ano: ";
                            int ano = getSafeIntegerInput();
                            livro->setAno(ano);
                            cout << "Ano atualizado.\n";
                            break;
                        }
                        case 6: {
                            cout << "Novo numero de dias permitidos para emprestimo: ";
                            int dias = getSafeIntegerInput();
                            livro->setNroDiasPermitidoEmprestimo(dias);
                            cout << "Dias de emprestimo atualizados.\n";
                            break;
                        }
                        case 7: {
                            cout << "Novo numero de paginas: ";
                            int paginas = getSafeIntegerInput();
                            livro->setNroPaginas(paginas);
                            cout << "Numero de paginas atualizado.\n";
                            break;
                        }
                        case 8: {
                            cout << "ID do autor a adicionar: ";
                            int idAutor = getSafeIntegerInput();
                            Autor* autor = GerenciadorCadastro::verificaAutor(idAutor);
                            if (autor == nullptr) {
                                cout << "Autor nao encontrado.\n";
                            } else {
                                livro->adicionarAutor(autor);
                                cout << "Autor adicionado ao livro.\n";
                            }
                            break;
                        }
                        case 0:
                            cout << "Saindo do editor do livro...\n";
                            break;
                        default:
                            cout << "Opcao invalida no editor." << endl;
                    }

                } while (opcEditar != 0);

                cout << "\nLivro atualizado com sucesso!" << endl;
                break;
            }

            case 3: { // REMOVER LIVRO
                int codigo;
                cout << "\nCodigo do livro a remover: ";
                codigo = getSafeIntegerInput();
                
                Livro* livro = Acervo::buscarLivro(codigo);
                if (livro == nullptr) {
                    throw runtime_error("[ERRO] Livro nao encontrado.");
                }
                
                if (!RegrasNegocio::podeRemoverLivro(livro,
                                                    GerenciadorEmprestimos::getEmprestimos(),
                                                    reservas)) {
                    break;
                }
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
                    throw runtime_error("[ERRO] Usuario nao encontrado.");
                }
                cout << "Usuario: " << usuario->getNome()  << endl;

                cout << "Codigo do livro: ";
                codigoLivro = getSafeIntegerInput();

                Livro* livro = Acervo::buscarLivro(codigoLivro);
                if(livro == nullptr){
                    throw runtime_error("[ERRO] Livro nao encontrado.");
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
                        throw runtime_error("[ERRO] Nenhum exemplar disponivel para a data informada (Ja reservados).");
                    } else {
                        throw runtime_error("[ERRO] Nenhum exemplar disponivel para este livro.");
                    }
                }

                Reserva* reserva = new Reserva(idReserva, dataReserva, usuario);
                ItemReserva* item = new ItemReserva(1, dataRetirada, exemplarDisponivel);

                reserva->adicionarItem(item);
                reservas.push_back(reserva);

                cout << "\nReserva criada com sucesso para o exemplar " << exemplarDisponivel->getNroExemplar() << "!\n";
                break;
            }

            case 5: { // EMPRESTIMO
                int codigoLivro, idUsuario;
                cout << "\nCRIAR EMPRESTIMO\n";
                cout << "Codigo do livro: "; codigoLivro = getSafeIntegerInput();
                cout << "ID do usuario: "; idUsuario = getSafeIntegerInput();

                Livro* livro = Acervo::buscarLivro(codigoLivro);
                Usuario* usuario = GerenciadorCadastro::verificaUsuario(idUsuario);

                if (livro == nullptr || usuario == nullptr) {
                    throw runtime_error("[ERRO] Livro ou Usuario nao encontrados para efetuar emprestimo.");
                }

                GerenciadorEmprestimos::CriarEmprestimo(usuario, livro);
                break;
            }

            case 6: { // DEVOLUCAO DE EMPRESTIMO
                cout << "\nDEVOLUCAO DE EMPRESTIMO\n";
                cout << "Escolha o metodo de identificacao:\n";
                cout << "1 - ID do Emprestimo\n";
                cout << "2 - ID do Usuario + Codigo do Livro\n";
                cout << "Opcao: ";
                int metodo = getSafeIntegerInput();

                if (metodo == 1) {
                    int idEmprestimo, dataDevolucao;
                    cout << "Digite o ID do emprestimo: "; idEmprestimo = getSafeIntegerInput();
                    cout << "Data de devolucao: "; dataDevolucao = getSafeIntegerInput();
                    GerenciadorEmprestimos::devolverEmprestimoPorId(idEmprestimo, dataDevolucao);
                } else if (metodo == 2) {
                    int codigoLivro, idUsuario, dataDevolucao;
                    cout << "Codigo do livro: "; codigoLivro = getSafeIntegerInput();
                    cout << "ID do usuario: "; idUsuario = getSafeIntegerInput();
                    cout << "Data de devolucao: "; dataDevolucao = getSafeIntegerInput();
                    GerenciadorEmprestimos::devolverEmprestimo(idUsuario, codigoLivro, dataDevolucao);
                } else {
                    cout << "\nMetodo invalido." << endl;
                }

                break;
            }

            case 7: { // CONSULTAS
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
                    cout << "\nDigite o ID do usuario: ";
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

            case 9: {
                int idRes;
                cout << "\nDigite o ID da reserva a ser removida: ";
                idRes = getSafeIntegerInput();
                bool found = false;
                for (auto it = reservas.begin(); it != reservas.end(); ++it) {
                    Reserva* r = *it;
                    if (r != nullptr && r->getID() == idRes) {
                        delete r;
                        reservas.erase(it);
                        cout << "\nReserva removida com sucesso." << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "\nReserva com esse ID nao encontrada." << endl;
                break;
            }

            case 8:
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

    } while(opcao != 8);

    // Liberacao de memoria
    for(Autor* autor : GerenciadorCadastro::getAutores()) delete autor; 
    for(Usuario* usuario : GerenciadorCadastro::getUsuarios()) delete usuario; 
    for(Editora* editora : GerenciadorCadastro::getEditoras()) delete editora; 
    for(Livro* livro : Acervo::getListaLivros()) delete livro;
    for(ExemplarLivro* exemplar : Acervo::getListaExemplares()) delete exemplar;
    for(Reserva* reserva : reservas) delete reserva;

    return 0;
}