# 📚 Sistema de Biblioteca

Sistema de gerenciamento de biblioteca desenvolvido em **C++** utilizando os princípios da **Programação Orientada a Objetos (POO)**.

O objetivo do projeto é simular as principais operações de uma biblioteca, permitindo o gerenciamento de livros, usuários, empréstimos e reservas.

---

## 🚀 Funcionalidades

### 📖 Gerenciamento de Livros
- Cadastro de livros
- Cadastro de autores
- Cadastro de editoras
- Controle de exemplares
- Consulta ao acervo

### 👤 Gerenciamento de Usuários
- Cadastro de alunos
- Cadastro de professores
- Consulta de usuários
- Controle de status dos usuários

### 🔄 Empréstimos
- Realização de empréstimos
- Registro de devoluções
- Controle de empréstimos ativos

### 📌 Reservas
- Criação de reservas
- Gerenciamento de itens reservados
- Controle de disponibilidade

### 📚 Acervo
- Organização dos livros cadastrados
- Consulta de exemplares disponíveis

---

## 🏗️ Estrutura do Projeto

```
Sistema-de-Biblioteca/
│
├── Livro/
├── autor/
├── editora/
├── endereco/
├── Usuario/
├── StatusUsuario/
├── emp/
├── Reserva/
├── acervo/
├── menu/
├── Gerenciadores/
├── itemEmp/
├── ExemplarLivro/
│
└── main.cpp
```

---

## 🧩 Conceitos de POO Utilizados

- Encapsulamento
- Herança
- Polimorfismo
- Abstração
- Composição
- Associação entre objetos

### Hierarquia de Usuários

```
Usuario
├── Aluno
└── Professor
```

---

## ⚙️ Compilação

Na pasta raiz do projeto execute:

```bash
g++ main.cpp Livro/Livro.cpp autor/Autor.cpp editora/Editora.cpp endereco/Endereco.cpp Usuario/Usuario.cpp StatusUsuario/StatusUsuario.cpp emp/Emprestimo.cpp Reserva/Reserva.cpp Reserva/ItemReserva.cpp acervo/Acervo.cpp menu/menu.cpp Gerenciadores/GerenciadorCadastro.cpp Gerenciadores/GerenciadorEmprestimos.cpp itemEmp/ItemEmprestimo.cpp ExemplarLivro/ExemplarLivro.cpp ExemplarLivro/StatusEmprestimo.cpp Usuario/Aluno.cpp Usuario/Professor.cpp -o main
```

### Executar

Linux/Mac:

```bash
./main
```

Windows:

```bash
main.exe
```

---

## 📋 Regras de Negócio

- Apenas exemplares disponíveis podem ser emprestados.
- Um empréstimo está associado a um usuário e a um ou mais exemplares.
- Reservas podem ser realizadas para livros indisponíveis.
- Alunos e professores possuem tipos distintos de usuário.
- O sistema mantém o controle do status dos exemplares.

---

## 🛠️ Tecnologias Utilizadas

- C++
- Programação Orientada a Objetos
- Compilador G++

---

## 🎯 Objetivos Acadêmicos

Este projeto foi desenvolvido com o objetivo de praticar:

- Modelagem orientada a objetos
- Organização de projetos em múltiplos arquivos
- Separação entre interface (.h) e implementação (.cpp)
- Relacionamento entre classes
- Gerenciamento de empréstimos e reservas

---

## 👨‍💻 Autor

GitHub: :contentReference[oaicite:0]{index=0}

---

## 📄 Licença

Projeto desenvolvido para fins acadêmicos e de estudo.
