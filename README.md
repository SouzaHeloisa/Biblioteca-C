# Sistema de Biblioteca em C

Projeto acadêmico desenvolvido em linguagem C para gerenciamento de uma biblioteca utilizando listas encadeadas, alocação dinâmica de memória e persistência de dados em arquivos texto.

## Sobre o Projeto

Este sistema foi desenvolvido com o objetivo de aplicar os conceitos estudados na disciplina de Algoritmos e Estruturas de Dados I, implementando um sistema de biblioteca capaz de gerenciar livros e empréstimos de forma dinâmica.

Os dados são armazenados em listas encadeadas durante a execução do programa e persistidos em arquivos texto, permitindo a recuperação das informações mesmo após o encerramento da aplicação.

---

## Funcionalidades

### Gerenciamento de Livros

- Cadastro de livros
- Busca de livros por título
- Listagem de livros cadastrados
- Exclusão de livros
- Controle automático da quantidade disponível

### Gerenciamento de Empréstimos

- Registro de empréstimos
- Registro de devoluções
- Listagem de empréstimos ativos
- Atualização automática do estoque de exemplares

### Persistência de Dados

- Salvamento automático dos livros em arquivo texto
- Salvamento automático dos empréstimos em arquivo texto
- Carregamento automático dos dados ao iniciar o sistema

---

## Estrutura do Projeto

```text
Biblioteca-C/
│
├── biblioteca.c
├── biblioteca.h
├── main.c
├── README.md
├── livros.txt
└── emprestimos.txt
```

### Descrição dos Arquivos

| Arquivo | Descrição |
|----------|----------|
| biblioteca.h | Protótipos das funções e declarações do sistema |
| biblioteca.c | Implementação das funcionalidades |
| main.c | Menu principal e interação com o usuário |
| livros.txt | Armazena os livros cadastrados |
| emprestimos.txt | Armazena os empréstimos registrados |
| README.md | Documentação do projeto |

---

## Estruturas Utilizadas

### Livro

Cada livro possui:

- Código
- Título
- Autor
- Ano de publicação
- Quantidade disponível
- Ponteiro para o próximo livro

### Empréstimo

Cada empréstimo possui:

- Nome do aluno
- Matrícula
- Título do livro
- Data de empréstimo
- Data de devolução
- Ponteiro para o próximo empréstimo

---

## Conceitos Aplicados

Durante o desenvolvimento foram utilizados:

- Estruturas de Dados
- Listas Encadeadas Simples
- Ponteiros
- Alocação Dinâmica de Memória
- Manipulação de Arquivos
- Manipulação de Strings
- Modularização em C
- Persistência de Dados
- Gerenciamento de Memória (`malloc` e `free`)

---

## Tecnologias Utilizadas

- Linguagem C
- GCC / MinGW
- Visual Studio Code
- Git
- GitHub

---

## Compilação

Com o GCC instalado:

```bash
gcc main.c biblioteca.c -o biblioteca.exe
```

---

## Execução

No Windows:

```bash
.\biblioteca.exe
```

ou execute diretamente o arquivo:

```text
biblioteca.exe
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

**Professora:** Prof.ª Dr.ª Rosana Cibely Batista Rego

**Instituição:** Ufersa - Campus Pau dos Ferros

**Semestre:** 2026.1

---

## Status do Projeto

✅ Concluído

O sistema implementa o gerenciamento de livros e empréstimos utilizando listas encadeadas e persistência de dados em arquivos texto, atendendo aos requisitos propostos para a disciplina.