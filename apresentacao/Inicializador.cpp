#include "Inicializador.h"
#include "..\Gerenciadores\GerenciadorCadastro.h"
#include "..\acervo\Acervo.h"
#include "..\Livro\Livro.h"
#include "..\autor\Autor.h"
#include "..\editora\Editora.h"
#include "..\Usuario\Aluno.h"
#include "..\Usuario\Professor.h"
#include "..\endereco\Endereco.h"
#include <iostream>

using namespace std;

void Inicializador::carregarDadosPrecadastrados() {
    cout << "\n Carregando dados pre-cadastrados...\n";
    
    // ===== ENDERECOS (NECESSARIOS PARA EDITORAS) =====
    Endereco endereco1("Av. Paulista", 1000, "Bela Vista", "Sao Paulo", "SP", "01310-100");
    Endereco endereco2("Rua Bandeira", 702, "Vila Mariana", "Sao Paulo", "SP", "04012-130");
    Endereco endereco3("Rua Bandeira", 800, "Consolacao", "Sao Paulo", "SP", "01311-100");
    
    // ===== EDITORAS =====
    Editora* editora1 = new Editora(1, "Pearson Education", endereco1);
    Editora* editora2 = new Editora(2, "Companhia das Letras", endereco2);
    Editora* editora3 = new Editora(3, "O'Reilly Media", endereco3);
    
    GerenciadorCadastro::adicionarEditora(editora1);
    GerenciadorCadastro::adicionarEditora(editora2);
    GerenciadorCadastro::adicionarEditora(editora3);
    cout << " 3 Editoras carregadas\n";
    
    // ===== AUTORES =====
    Autor* autor1 = new Autor("Robert C. Martin", 1);
    Autor* autor2 = new Autor("Erich Gamma", 2);
    Autor* autor3 = new Autor("Gang of Four", 3);
    Autor* autor4 = new Autor("Machado de Assis", 4);
    Autor* autor5 = new Autor("Clarice Lispector", 5);
    
    GerenciadorCadastro::adicionarAutor(autor1);
    GerenciadorCadastro::adicionarAutor(autor2);
    GerenciadorCadastro::adicionarAutor(autor3);
    GerenciadorCadastro::adicionarAutor(autor4);
    GerenciadorCadastro::adicionarAutor(autor5);
    cout << " 5 Autores carregados\n";
    
    // ===== LIVROS =====
    vector<Autor*> autoresCleanCode;
    autoresCleanCode.push_back(autor1);
    
    Livro* livro1 = new Livro(
        101,                          // codigo
        "Clean Code",                 // titulo
        1,                            // edicao
        89.90,                        // preco
        *editora1,                    // editora
        2008,                         // ano
        0,                            // quantidade exemplares (sera ajustada)
        7,                            // dias emprestimo
        autoresCleanCode,             // autores
        1,                            // status agora
        1,                            // status futuro
        464                           // paginas
    );
    
    vector<Autor*> autoresDesignPatterns;
    autoresDesignPatterns.push_back(autor2);
    autoresDesignPatterns.push_back(autor3);
    
    Livro* livro2 = new Livro(
        102,
        "Design Patterns: Elements of Reusable Object-Oriented Software",
        1,
        95.50,
        *editora3,
        1994,
        0,
        14,
        autoresDesignPatterns,
        1,
        1,
        395
    );
    
    Acervo::acrecentarLivro(livro1);
    Acervo::acrecentarLivro(livro2);
    cout << " 2 Livros carregados\n";
    
    // ===== EXEMPLARES =====
    Acervo::criarExemplaresParaLivro(livro1, 3);
    Acervo::criarExemplaresParaLivro(livro2, 2);
    cout << " 5 Exemplares criados\n";
    
    // ===== USUARIOS =====
    Aluno* aluno1 = new Aluno(1, "Joao Silva", StatusUsuario::HABILITADO, "2023001");
    Aluno* aluno2 = new Aluno(2, "Maria Santos", StatusUsuario::HABILITADO, "2023002");
    
    GerenciadorCadastro::adicionarUsuario(aluno1);
    GerenciadorCadastro::adicionarUsuario(aluno2);
    cout << " 2 Alunos carregados\n";
    
    Professor* prof1 = new Professor(3, "Dr. Carlos", StatusUsuario::HABILITADO, "Departamento de Engenharia", 2);
    GerenciadorCadastro::adicionarUsuario(prof1);
    cout << " 1 Professor carregado\n";
    
    cout << "\n Todos os dados pre-cadastrados foram carregados com sucesso!\n\n";
}

void Inicializador::limparDados() {
    cout << "\n  Limpando dados do sistema...\n";
    
    // Liberacao de memoria feita no destrutor ou final do programa
    cout << " Dados limpos\n\n";
}

void Inicializador::exibirDadosCarregados() {
    cout << "\n" << string(60, '=') << "\n";
    cout << "            DADOS PRE-CADASTRADOS CARREGADOS\n";
    cout << string(60, '=') << "\n\n";
    
    cout << " LIVROS:\n";
    Acervo::listarTodos();
    
    cout << "\n USUARIOS:\n";
    for(Usuario* usuario : GerenciadorCadastro::getUsuarios()) {
        usuario->exibirInformacoes();
        cout << endl;
    }
    
    cout << "\n  AUTORES:\n";
    for(Autor* autor : GerenciadorCadastro::getAutores()) {
        cout << "ID: " << autor->getCodigo() << " | Nome: " << autor->getNome() << endl;
    }
    
    cout << "\n EDITORAS:\n";
    for(Editora* editora : GerenciadorCadastro::getEditoras()) {
        cout << "ID: " << editora->getId() << " | Nome: " << editora->getNome() << endl;
    }
    
    cout << "\n" << string(60, '=') << "\n\n";
}
