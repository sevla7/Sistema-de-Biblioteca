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
using namespace std;


int main() {
    vector<Reserva*> reservas;

    int opcao;

    do {

        exibirMenu();

        cin >> opcao;

        switch(opcao) {

        case 1: { // CADASTRO

            int opcCadastro;

            cout << "\nCADASTRAR\n";
            cout << "1. Livro\n";
            cout << "2. Autor\n";
            cout << "3. Aluno" << endl;
            cout << "4. Professor" << endl;
            cout << "5. Editora\n";
            cout << "Opcao: ";

            cin >> opcCadastro;

            cout << endl;

            switch(opcCadastro) {

            case 1: {
                int c; //codigo
                string t; //titulo
                int e; //edição
                float p; //preço
                int a; //ano
                int qtdExe; //quantidade de exemplares
                int pag; //numero de paginas
                int idEditora;
                int diasEmp = 7; // Default value for days of loan

                cout << "Digite o código." << endl;
                cin >> c;

                cout << "Digite o título." << endl;
                cin.ignore();
                getline(cin, t);

                cout << "Digite a edição." << endl;
                cin >> e;

                cout << "Digite o preço." << endl;
                cin >> p;

                cout << "Digite o id da editora." << endl;
                cin >> idEditora;
                Editora* editora = GerenciadorCadastro::verificaEditora(idEditora);
                if (editora == nullptr) {
                    cout << "\n[ERRO] Editora não encontrada! Cadastre a editora primeiro.\n";
                    break;
                }

                cout << "Digite o ano." << endl;
                cin >> a;

                cout << "Quantidade de exemplares." << endl;
                cin >> qtdExe;

                // --- LÓGICA DE AUTORES ---
                vector<Autor*> autoresDoLivro;
                int qtdAutores;
                cout << "Quantos autores tem o livro? ";
                cin >> qtdAutores;

                bool falhaAutor = false;
                for(int i = 0; i < qtdAutores; i++) {
                    int idAutor;
                    cout << "Digite o ID do autor " << (i + 1) << ": ";
                    cin >> idAutor;
                    Autor* aut = GerenciadorCadastro::verificaAutor(idAutor);
                    if(aut != nullptr) {
                        autoresDoLivro.push_back(aut);
                    } else {
                        cout << "Autor com ID " << idAutor << " não encontrado!" << endl;
                        falhaAutor = true;
                        break; // Sai do loop se algum autor falha
                    }
                }

                if (falhaAutor || autoresDoLivro.empty()) { // Checa se algum autor falhou ou se não tem autores
                    cout << "\nLivro não cadastrado: É necessário pelo menos um autor válido.\n";
                    break; // Sai do case 1
                }


                cout << "Número de páginas." << endl;
                cin >> pag;

                Livro* livro = new Livro(c, t, e, p, *editora, a, 0, diasEmp, autoresDoLivro, 1, 1, pag);
                // quantidadeExemplares inicializa em 0, é atualizado por Acervo::criarExemplaresParaLivro

                Acervo::acrecentarLivro(livro);

                // --- GERANDO OS EXEMPLARES ---
                Acervo::criarExemplaresParaLivro(livro, qtdExe);

                cout << "\nLivro cadastrado com sucesso!\n";

                break;
            }

            case 2: {
                int idAutor;
                cout << "Digite o ID do autor: ";
                cin >> idAutor;
                Autor* aut = GerenciadorCadastro::verificaAutor(idAutor);
                    if(aut != nullptr) {
                        cout << "Autor com ID " << idAutor << " já existe!" << endl;
                        break; // Sai do loop se algum autor falha
                    } else {
                        Autor autor_obj = cadastraAutor(idAutor);
                        Autor* autor = new Autor(autor_obj);
                        GerenciadorCadastro::adicionarAutor(autor); // Adiciona ao gerenciador
                        cout << "\nAutor cadastrado com sucesso!\n";
                        break;
                    }
            }

            case 3:
            {
                int idUsuario;
                cout << "Digite o ID do aluno: ";
                cin >> idUsuario;
                Usuario* user = GerenciadorCadastro::verificaUsuario(idUsuario);
                    if(user != nullptr) {
                        cout << "Usuário com ID " << idUsuario << " já existe!" << endl;
                        break; // Sai do loop se algum usuário falha
                    } else {
                        Aluno aluno_obj = cadastraAluno(idUsuario);
                        Aluno* aluno = new Aluno(aluno_obj);
                        GerenciadorCadastro::adicionarUsuario(aluno); // Adicionado ao gerenciador

                        cout << "Aluno cadastrado!" << endl;

                        break;
                    }
            }

            case 4:
            {
                int idUsuario;
                cout << "Digite o ID do professor: ";
                cin >> idUsuario;
                Usuario* user = GerenciadorCadastro::verificaUsuario(idUsuario);
                if(user != nullptr) {
                    cout << "Usuário com ID " << idUsuario << " já existe!" << endl;
                    break; // Sai do loop se algum usuário falha
                }
                else {
                  Professor professor_obj = cadastraProfessor(idUsuario);
                  Professor* professor = new Professor(professor_obj);
                  GerenciadorCadastro::adicionarUsuario(professor); // Adicionado ao gerenciador

                  cout << "Professor cadastrado!" << endl;

                  break;
                }
            }

            case 5: {
                int idEditora;
                cout << "Digite o ID da editora: ";
                cin >> idEditora;
                Editora* editora = GerenciadorCadastro::verificaEditora(idEditora);
                if(editora != nullptr) {
                    cout << "Editora com ID " << idEditora << " já existe!" << endl;
                    break; // Sai do loop se alguma editora falha
                }
                else {
                  Editora editora_obj = cadastraEditora(idEditora);
                  Editora* editora = new Editora(editora_obj);
                  GerenciadorCadastro::adicionarEditora(editora); // Adicionado ao gerenciador

                  cout << "\nEditora cadastrada com sucesso!\n";

                  break;
                }
            }

            default:
                cout << "\nOpcao invalida!" << endl;
            }

            break;
        }

        case 2: { // EDITAR LIVRO

            int codigo;

            cout << "\nCodigo do livro: ";
            cin >> codigo;

            Livro* livro = Acervo::buscarLivro(codigo);

            if (livro == nullptr) {

                cout << "\nLivro nao encontrado." << endl;

            } else {

                string novoTitulo;

                cin.ignore();

                cout << "Novo titulo: ";

                getline(cin, novoTitulo);

                livro->setTitulo(novoTitulo);

                cout << "\nLivro atualizado com sucesso!" << endl;
            }

            break;
        }

        case 3: { // REMOVER LIVRO

            int codigo;

            cout << "\nCodigo do livro a remover: ";

            cin >> codigo;

            Acervo::removerLivroPorCodigo(codigo);

            break;
        }

        case 4:
        {           
            int idReserva;
            int dataReserva;
            int dataRetirada;
            int codigoLivro;
            int idUsuario;

            cout << "\n=== CRIAR RESERVA ===\n";

            cout << "ID da reserva: ";
            cin >> idReserva;

            cout << "Data da reserva: ";
            cin >> dataReserva;

            cout << "Data para retirada: ";
            cin >> dataRetirada;

            cout << "ID do usuario: ";
            cin >> idUsuario;

            Usuario* usuario =
                GerenciadorCadastro::verificaUsuario(idUsuario);

            if(usuario == nullptr){

                cout << "Usuario nao encontrado." << endl;

                break;
            }
            else {
              cout << "Usuário: " << usuario->getNome()  << endl;
            }

            cout << "Codigo do livro: ";
            cin >> codigoLivro;

            Livro* livro = Acervo::buscarLivro(codigoLivro);

            if(livro == nullptr){

                cout << "Livro nao encontrado." << endl;

                break;
            }

            // --- LOGICA PARA VERIFICAR DISPONIBILIDADE DE EXEMPLAR PARA RESERVA ---
            ExemplarLivro* exemplarDisponivel = nullptr;
            bool exemplarJaReservadoParaData = false;

            for (ExemplarLivro* ex : Acervo::getListaExemplares()) { 
                if (ex->getLivro() == livro) { 
                    // Check if this specific exemplar is already reserved for the desired date
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
                        // This exemplar is available for reservation on this date
                        exemplarDisponivel = ex;
                        break; 
                    }
                }
            }

            if (exemplarDisponivel == nullptr) {
                if (exemplarJaReservadoParaData) {
                    cout << "\nNenhum exemplar disponivel para reserva na data " << dataRetirada << ". Todos os exemplares ja estao reservados para essa data.\n";
                } else {
                    cout << "\nNenhum exemplar disponivel do livro '" << livro->getTitulo() << "' para reserva.\n";
                }
                break; 
            }

            Reserva* reserva =
                new Reserva(
                    idReserva,
                    dataReserva,
                    usuario);

            ItemReserva* item =
                new ItemReserva(
                    1,
                    dataRetirada,
                    exemplarDisponivel); 

            reserva->adicionarItem(item);

            reservas.push_back(reserva);

            cout << "\nReserva criada com sucesso para o exemplar " << exemplarDisponivel->getNroExemplar() << "!\n";

            break;
        }

        case 5:
        {           
            int codigoLivro;
            int idUsuario;

            cout << "\nCRIAR EMPRESTIMO\n";

            cout << "Codigo do livro: ";
            cin >> codigoLivro;

            cout << "ID do usuario: ";
            cin >> idUsuario;

            Livro* livro =
                Acervo::buscarLivro(codigoLivro);

            Usuario* usuario =
                GerenciadorCadastro::verificaUsuario(idUsuario); 

            GerenciadorEmprestimos::CriarEmprestimo(
                usuario,
                livro
            );

            break;
        }

        case 6: { // CONSULTAS

            int opcConsulta;

            exibirSubMenuConsultar(); 

            cin >> opcConsulta;

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

            case 4: // Listar todas as Reservas
            {
                if(reservas.empty()){

                    cout << "\nNenhuma reserva cadastrada." << endl;

                } else {

                    for(Reserva* reserva : reservas){

                        reserva->exibirInformacoes();

                        cout << endl;
                    }
                }

                break;
            }

            case 5: // Reservas de um Usuario
            {
                int id;

                cout << "\nDigite o ID do usuario: ";
                cin >> id;

                bool encontrou = false;

                for(Reserva* r : reservas){

                    if(r->getUsuario() != nullptr &&
                       r->getUsuario()->getID() == id){

                        r->exibirInformacoes();
                        encontrou = true;
                    }
                }

                if(!encontrou){
                    cout << "Nenhuma reserva encontrada para esse usuario." << endl;
                }

                break;
            }

            case 6:
            {
                int id;
                cout << "\nDigite o ID do usuário: ";
                cin >> id;
                GerenciadorEmprestimos::listarEmprestimosPorUsuario(id);
                break;
            }

            case 7:
            {
                GerenciadorEmprestimos::listarTodosEmprestimosAtuais();
                break;
            }

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
            break;
        }

    } while(opcao != 7); 

    // Liberação de memória

    for(Autor* autor : GerenciadorCadastro::getAutores()) delete autor; 

    for(Usuario* usuario : GerenciadorCadastro::getUsuarios()) delete usuario; 

    for(Editora* editora : GerenciadorCadastro::getEditoras()) delete editora; 

    for(Livro* livro : Acervo::getListaLivros()) delete livro;

    for(ExemplarLivro* exemplar : Acervo::getListaExemplares()) delete exemplar;

    for(Reserva* reserva : reservas)
        delete reserva;


    return 0;
}