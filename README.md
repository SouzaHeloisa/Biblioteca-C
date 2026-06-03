# Sistema de Biblioteca em C

Projeto acadêmico desenvolvido em linguagem C para gerenciamento de uma biblioteca utilizando listas encadeadas, alocação dinâmica de memória e armazenamento de dados em arquivos texto.

## Objetivo

Desenvolver um sistema de biblioteca aplicando conceitos de:

* Estruturas de Dados
* Listas Encadeadas
* Ponteiros
* Alocação Dinâmica de Memória
* Manipulação de Arquivos
* Modularização em C

## Estrutura do Projeto

```text
biblioteca.c
biblioteca.h
main.c
README.md
```

## Funcionalidades Implementadas

### Gerenciamento de Livros

* Cadastro de livros
* Busca de livros por título
* Listagem de livros cadastrados
* Exclusão de livros

### Gerenciamento de Empréstimos

* Registro de empréstimos
* Registro de devoluções
* Listagem de empréstimos

### Persistência de Dados

* Salvamento automático dos livros em arquivo texto
* Salvamento automático dos empréstimos em arquivo texto
* Carregamento automático dos dados ao iniciar o sistema

## Estruturas Utilizadas

### Livro

Cada livro armazena:

* Código
* Título
* Autor
* Ano de publicação
* Quantidade disponível

### Empréstimo

Cada empréstimo armazena:

* Nome do aluno
* Matrícula
* Título do livro
* Data do empréstimo
* Data de entrega

## Tecnologias Utilizadas

* Linguagem C
* Listas Encadeadas Simples
* Alocação Dinâmica (`malloc` e `free`)
* Manipulação de Arquivos
* Manipulação de Strings

## Status do Projeto

🚧 Em desenvolvimento

Atualmente as funções principais da biblioteca já estão implementadas. A etapa final consiste na integração completa com o menu principal (`main.c`), testes e ajustes finais.


