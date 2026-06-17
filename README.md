# 📚 Sistema de Biblioteca

Sistema de gerenciamento de biblioteca desenvolvido em **Java** utilizando os conceitos de **Programação Orientada a Objetos (POO)**.

O projeto permite o cadastro e gerenciamento de livros, usuários, empréstimos e reservas, simulando o funcionamento básico de uma biblioteca acadêmica.

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
- Controle de status do usuário

### 🔄 Empréstimos
- Realização de empréstimos
- Controle de devoluções
- Consulta de empréstimos ativos
- Histórico de empréstimos

### 📌 Reservas
- Criação de reservas
- Gerenciamento de filas de espera
- Controle de itens reservados

### 📚 Acervo
- Organização dos livros cadastrados
- Controle de disponibilidade dos exemplares

---

## 🏗️ Estrutura do Projeto

```
Sistema-de-Biblioteca
│
├── Livro/
│   └── Livro.java
│
├── Autor/
│   └── Autor.java
│
├── Editora/
│   └── Editora.java
│
├── Endereco/
│   └── Endereco.java
│
├── Usuario/
│   ├── Usuario.java
│   ├── Aluno.java
│   └── Professor.java
│
├── ExemplarLivro/
│   ├── ExemplarLivro.java
│   └── StatusEmprestimo.java
│
├── Emprestimo/
│   ├── Emprestimo.java
│   └── ItemEmprestimo.java
│
├── Reserva/
│   ├── Reserva.java
│   └── ItemReserva.java
│
├── Acervo/
│   └── Acervo.java
│
├── Gerenciadores/
│   ├── GerenciadorCadastro.java
│   └── GerenciadorEmprestimos.java
│
├── Menu/
│   └── Menu.java
│
└── Main.java
```

---

## 🧩 Conceitos de POO Utilizados

- Encapsulamento
- Herança
- Polimorfismo
- Abstração
- Composição
- Associação entre classes

### Exemplo de Herança

```java
Usuario
├── Aluno
└── Professor
```

---

## ⚙️ Como Compilar

Na pasta raiz do projeto execute:

```bash
g++ main.cpp Livro/Livro.cpp Autor/Autor.cpp Editora/Editora.cpp Endereco/Endereco.cpp Usuario/Usuario.cpp StatusUsuario/StatusUsuario.cpp Emprestimo/Emprestimo.cpp Reserva/Reserva.cpp Reserva/ItemReserva.cpp Acervo/Acervo.cpp Menu/Menu.cpp Gerenciadores/GerenciadorCadastro.cpp Gerenciadores/GerenciadorEmprestimos.cpp ItemEmprestimo/ItemEmprestimo.cpp ExemplarLivro/ExemplarLivro.cpp ExemplarLivro/StatusEmprestimo.cpp Usuario/Aluno.cpp Usuario/Professor.cpp -o main
```

Executar:

```bash
./main
```

No Windows:

```bash
main.exe
```

---

## 🖥️ Exemplo de Uso

1. Cadastrar usuário
2. Cadastrar livro
3. Consultar acervo
4. Realizar empréstimo
5. Registrar devolução
6. Realizar reserva

---

## 📋 Regras de Negócio

- Um livro só pode ser emprestado se houver exemplar disponível.
- Usuários podem possuir empréstimos ativos.
- Reservas são registradas quando não há exemplares disponíveis.
- Alunos e professores podem possuir regras de empréstimo distintas.

---

## 👨‍💻 Desenvolvedor

**S3VL4**

GitHub:
https://github.com/sevla7

---

## 📄 Licença

Projeto desenvolvido para fins acadêmicos e de aprendizado em Programação Orientada a Objetos.
