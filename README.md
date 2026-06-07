# Sistema de Biblioteca em C

Projeto acadêmico desenvolvido em linguagem C para gerenciamento de uma biblioteca utilizando **Listas Encadeadas**, **Tipos Abstratos de Dados (TADs)**, **Alocação Dinâmica de Memória** e **Persistência de Dados em Arquivos Texto**.

## Objetivo

O objetivo deste projeto é aplicar os conceitos estudados na disciplina de **Algoritmos e Estruturas de Dados I**, desenvolvendo um sistema capaz de realizar o gerenciamento de livros e empréstimos de uma biblioteca.

Durante o desenvolvimento foram utilizados conceitos fundamentais da linguagem C, incluindo:

- Estruturas de Dados
- Tipos Abstratos de Dados (TADs)
- Listas Encadeadas Simples
- Ponteiros
- Alocação Dinâmica de Memória
- Manipulação de Arquivos
- Manipulação de Strings
- Modularização de Código
- Persistência de Dados

---

## Sobre o Sistema

O sistema permite o cadastro e gerenciamento de livros e empréstimos através de listas encadeadas alocadas dinamicamente.

As informações são mantidas em memória durante a execução do programa e armazenadas em arquivos texto para garantir a persistência dos dados entre diferentes execuções.

O projeto foi organizado utilizando dois TADs independentes:

### TAD Livro

Responsável pelo gerenciamento do acervo da biblioteca.

### TAD Empréstimo

Responsável pelo gerenciamento dos empréstimos realizados pelos usuários.

Essa separação torna o código mais organizado, modular e facilita futuras manutenções.

---

## Funcionalidades Implementadas

### Gerenciamento de Livros

- Cadastro de livros
- Busca de livros por título
- Listagem de livros cadastrados
- Exclusão de livros
- Controle da quantidade disponível

### Gerenciamento de Empréstimos

- Registro de empréstimos
- Registro de devoluções
- Listagem de empréstimos ativos
- Atualização automática da quantidade disponível dos livros

### Persistência de Dados

- Salvamento automático dos livros em arquivo texto
- Salvamento automático dos empréstimos em arquivo texto
- Carregamento automático dos dados ao iniciar o sistema

---

## Estrutura do Projeto

```text
Biblioteca-C/
│
├── main.c
│
├── livro.h
├── livro.c
│
├── emprestimo.h
├── emprestimo.c
│
├── livros.txt
├── emprestimos.txt
│
├── .gitignore
└── README.md
```

---

## Descrição dos Arquivos

| Arquivo | Descrição |
|----------|----------|
| main.c | Menu principal e interação com o usuário |
| livro.h | Declarações e definição da estrutura Livro |
| livro.c | Implementação das funções relacionadas aos livros |
| emprestimo.h | Declarações e definição da estrutura Empréstimo |
| emprestimo.c | Implementação das funções relacionadas aos empréstimos |
| livros.txt | Armazenamento dos livros cadastrados |
| emprestimos.txt | Armazenamento dos empréstimos registrados |
| README.md | Documentação do projeto |
| .gitignore | Arquivos ignorados pelo Git |

---

## Estruturas Utilizadas

### Estrutura Livro

Cada livro armazena:

- Código
- Título
- Autor
- Ano de publicação
- Quantidade disponível
- Ponteiro para o próximo livro

A estrutura é utilizada para formar uma lista encadeada simples contendo todos os livros cadastrados.

### Estrutura Empréstimo

Cada empréstimo armazena:

- Nome do aluno
- Matrícula
- Título do livro
- Data de empréstimo
- Data de devolução
- Ponteiro para o próximo empréstimo

A estrutura é utilizada para formar uma lista encadeada simples contendo todos os empréstimos registrados.

---

## Organização em TADs

### TAD Livro

Responsável pelas seguintes operações:

- cadastrarLivro()
- listarLivros()
- buscarLivro()
- excluirLivro()
- salvarlivros()
- carregarLivros()

### TAD Empréstimo

Responsável pelas seguintes operações:

- emprestarLivro()
- devolverLivro()
- listarEmprestimos()
- salvaremprestimos()
- carregarEmprestimos()

---

## Persistência de Dados

Os dados são armazenados nos arquivos:

```text
livros.txt
emprestimos.txt
```

Sempre que um livro é cadastrado, excluído, emprestado ou devolvido, os arquivos são atualizados automaticamente.

Ao iniciar o sistema, os dados são carregados novamente para a memória através das funções:

- carregarLivros()
- carregarEmprestimos()

Dessa forma, as informações permanecem disponíveis mesmo após o encerramento do programa.

---

## Tecnologias Utilizadas

- Linguagem C
- GCC (MinGW)
- Visual Studio Code
- Git
- GitHub

---

## Compilação

Com o GCC instalado:

```bash
gcc main.c livro.c emprestimo.c -o biblioteca.exe
```

---

## Execução

No Windows:

```bash
.\biblioteca.exe
```

Ou execute diretamente:

```text
biblioteca.exe
```

---

## Clonando o Repositório

Abra o terminal e execute:

```bash
git clone https://github.com/SouzaHeloisa/Biblioteca-C.git
```

Acesse a pasta do projeto:

```bash
cd Biblioteca-C
```

Compile o sistema:

```bash
gcc main.c livro.c emprestimo.c -o biblioteca.exe
```

Execute:

```bash
.\biblioteca.exe
```

---

## Menu do Sistema

```text
1. Cadastrar Livro
2. Emprestar Livro
3. Devolver Livro
4. Listar Livros
5. Buscar Livro
6. Listar Empréstimos
7. Excluir Livro
0. Sair
```

---

## Autores

- Maria Heloísa Pessoa de Souza
- Francisco Eduardo de Andrade Oliveira

---

## Informações Acadêmicas

**Disciplina:** Algoritmos e Estruturas de Dados I

**Docente:** Prof.ª Dr.ª Rosana Cibely Batista Rego

**Instituição:** Universidade Federal Rural do Semi-Árido (UFERSA) – Campus Pau dos Ferros

**Semestre:** 2026.1

---

## Status do Projeto

✅ Concluído

O sistema implementa o gerenciamento de livros e empréstimos utilizando listas encadeadas simples, TADs, alocação dinâmica de memória e persistência de dados em arquivos texto, atendendo aos requisitos propostos para a disciplina.