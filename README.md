# Sistema de Biblioteca em C

Projeto acadêmico desenvolvido em linguagem C para gerenciamento de uma biblioteca utilizando listas encadeadas, alocação dinâmica de memória e persistência de dados em arquivos texto.

---

## Sobre o Projeto

Este sistema foi desenvolvido como atividade da disciplina de **Algoritmos e Estruturas de Dados I**, com o objetivo de aplicar conceitos fundamentais da programação em C e de estruturas de dados.

A aplicação permite realizar o gerenciamento de livros e empréstimos por meio de listas encadeadas simples, utilizando alocação dinâmica de memória e armazenamento permanente em arquivos texto.

Os dados cadastrados permanecem disponíveis entre diferentes execuções do programa graças ao mecanismo de persistência implementado.

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
- Atualização automática da quantidade de exemplares disponíveis

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
```

### Descrição dos Arquivos

| Arquivo | Descrição |
|----------|----------|
| biblioteca.h | Protótipos das funções e declarações utilizadas pelo sistema |
| biblioteca.c | Implementação das funcionalidades da biblioteca |
| main.c | Menu principal e interação com o usuário |
| livros.txt | Armazena os livros cadastrados |
| emprestimos.txt | Armazena os empréstimos registrados |
| README.md | Documentação do projeto |

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

### Estrutura Empréstimo

Cada empréstimo armazena:

- Nome do aluno
- Matrícula
- Título do livro
- Data de empréstimo
- Data de devolução
- Ponteiro para o próximo empréstimo

---

## Conceitos Aplicados

Durante o desenvolvimento do projeto foram aplicados os seguintes conceitos:

- Estruturas de Dados
- Listas Encadeadas Simples
- Ponteiros
- Alocação Dinâmica de Memória
- Manipulação de Arquivos
- Manipulação de Strings
- Modularização em Linguagem C
- Persistência de Dados
- Gerenciamento de Memória com `malloc()` e `free()`

---

## Tecnologias Utilizadas

- Linguagem C
- GCC / MinGW
- Visual Studio Code
- Git
- GitHub

---

## Compilação (Windows)

Com o GCC/MinGW instalado, execute no terminal:

```bash
gcc main.c biblioteca.c -o biblioteca.exe
```

Será gerado o arquivo executável:

```text
biblioteca.exe
```

---

## Execução (Windows)

Execute o programa pelo terminal:

```bash
.\biblioteca.exe
```

Ou execute diretamente o arquivo:

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

## Objetivos de Aprendizagem

Este projeto teve como objetivo praticar:

- Implementação de listas encadeadas
- Utilização de ponteiros
- Alocação dinâmica de memória
- Manipulação de arquivos texto
- Modularização de programas em C
- Desenvolvimento de sistemas utilizando estruturas de dados

---

## Autores

- Maria Heloísa Pessoa de Souza
- Francisco Eduardo de Andrade Oliveira

---

## Informações Acadêmicas

**Disciplina:** Algoritmos e Estruturas de Dados I

**Docente responsável:** Prof.ª Dr.ª Rosana Cibely Batista Rego

**Instituição:** Universidade Federal Rural do Semi-Árido (UFERSA) – Campus Pau dos Ferros

**Semestre:** 2026.1

---

## Licença

Este projeto foi desenvolvido exclusivamente para fins acadêmicos como atividade da disciplina de Algoritmos e Estruturas de Dados I.

A utilização do código para estudos e aprendizado é permitida, desde que os autores sejam devidamente citados.