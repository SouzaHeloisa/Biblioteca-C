# Sistema de Biblioteca em C

Projeto acadêmico desenvolvido em linguagem C para gerenciamento de uma biblioteca utilizando **Listas Encadeadas**, **Tipos Abstratos de Dados (TADs)**, **Alocação Dinâmica de Memória** e **Persistência de Dados em Arquivos Texto**.

## Objetivo

O objetivo deste projeto é aplicar os conceitos estudados na disciplina de **Algoritmos e Estruturas de Dados I**, desenvolvendo um sistema capaz de realizar o gerenciamento de livros e empréstimos de uma biblioteca.

Durante o desenvolvimento foram utilizados conceitos fundamentais da linguagem C, incluindo:

- Estruturas de Dados
- Tipos Abstratos de Dados (TADs)
- Listas Encadeadas Simples
- Ponteiros e Duplo Ponteiro
- Alocação Dinâmica de Memória
- Manipulação de Arquivos
- Manipulação de Strings
- Modularização de Código
- Persistência de Dados
- Validação de Entradas com `time.h`

---

## Sobre o Sistema

O sistema permite o cadastro e gerenciamento de livros e empréstimos através de listas encadeadas alocadas dinamicamente.

As informações são mantidas em memória durante a execução do programa e armazenadas em arquivos texto para garantir a persistência dos dados entre diferentes execuções.

O projeto foi organizado utilizando TADs independentes com um módulo dedicado exclusivamente a validações:

### TAD Livro

Responsável pelo gerenciamento do acervo da biblioteca.

### TAD Empréstimo

Responsável pelo gerenciamento dos empréstimos realizados pelos usuários.

### Módulo de Validação

Responsável por todas as validações de entrada do sistema, incluindo validações dinâmicas com o relógio do sistema via `time.h`.

Essa separação torna o código mais organizado, modular e facilita futuras manutenções.

---

## Funcionalidades Implementadas

### Gerenciamento de Livros

- Cadastro de livros com validação completa de todos os campos
- Busca de livros por título
- Listagem de livros cadastrados
- Edição de livros (campo a campo, com atualização automática nos empréstimos)
- Exclusão de livros (bloqueada se houver empréstimos ativos)
- Controle da quantidade disponível

### Gerenciamento de Empréstimos

- Registro de empréstimos com validação de disponibilidade
- Registro de devoluções
- Listagem de empréstimos ativos
- Atualização automática da quantidade disponível dos livros
- Prevenção de empréstimo duplicado (mesmo aluno, mesmo livro)
- Validação de matrícula única por aluno

### Validações Implementadas

- Campos obrigatórios — nenhum campo pode ficar vazio
- Código de livro único e positivo
- Título único por livro
- Nome do autor com caracteres válidos
- Ano de publicação entre 1000 e o ano atual (validado com `time.h`)
- Quantidade disponível maior que zero
- Matrícula única por aluno (matrícula funciona como identificador do aluno)
- Data no formato `dd/mm/aaaa` com verificação de dia, mês e ano válidos
- Suporte a anos bissextos
- Data de empréstimo não pode ser futura (validada com `time.h`)
- Data de entrega não pode ser anterior à data de empréstimo

### Persistência de Dados

- Salvamento automático dos livros em arquivo texto formatado
- Salvamento automático dos empréstimos em arquivo texto formatado
- Carregamento automático dos dados ao iniciar o sistema
- Formato de arquivo legível com identificadores de registro

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
├── validacao.h
├── validacao.c
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
| validacao.h | Declarações das funções de validação e leitura de entrada |
| validacao.c | Implementação de todas as validações do sistema |
| livros.txt | Armazenamento dos livros cadastrados |
| emprestimos.txt | Armazenamento dos empréstimos registrados |
| README.md | Documentação do projeto |
| .gitignore | Arquivos ignorados pelo Git |

---

## Estruturas Utilizadas

### Estrutura Livro

Cada livro armazena:

- Código (único, positivo)
- Título (único)
- Autor
- Ano de publicação
- Quantidade disponível
- Ponteiro para o próximo livro

### Estrutura Empréstimo

Cada empréstimo armazena:

- Nome do aluno
- Matrícula (identificador único do aluno)
- Título do livro
- Data de empréstimo
- Data de devolução
- Ponteiro para o próximo empréstimo

---

## Organização em TADs

### TAD Livro

Responsável pelas seguintes operações:

- `cadastrarLivro()`
- `listarLivros()`
- `buscarLivro()`
- `editarLivro()`
- `excluirLivro()`
- `salvarlivros()`
- `carregarLivros()`

### TAD Empréstimo

Responsável pelas seguintes operações:

- `emprestarLivro()`
- `devolverLivro()`
- `listarEmprestimos()`
- `livroPossuiEmprestimos()`
- `salvaremprestimos()`
- `carregarEmprestimos()`

### Módulo Validação

Responsável pelas seguintes operações:

- `lerInteiro()` — leitura segura de inteiros
- `lerString()` — leitura segura de strings
- `textoVazio()` — verificação de campo vazio
- `validarCodigo()` — valida código do livro
- `validarQuantidade()` — valida quantidade disponível
- `validarMatricula()` — valida matrícula do aluno
- `validarNome()` — valida nome com caracteres permitidos
- `validarAnoPublicacao()` — valida ano com `time.h`
- `validarData()` — valida formato e consistência da data
- `validarDataEmprestimo()` — valida data contra o dia atual com `time.h`
- `validarDataEntrega()` — valida data de entrega contra data de empréstimo
- `codigoJaExiste()` — previne código duplicado
- `tituloJaExiste()` — previne título duplicado
- `validarDisponibilidade()` — verifica exemplares disponíveis
- `emprestimoJaExiste()` — previne empréstimo duplicado
- `matriculaCompativel()` — garante unicidade da matrícula por aluno

---

## Formato de Persistência

Os dados são armazenados em formato legível com identificadores de registro:

**livros.txt**
```
[LIVRO]
Codigo: 1
Titulo: Dom Casmurro
Autor: Machado de Assis
Ano: 1899
Quantidade: 3
```

**emprestimos.txt**
```
[EMPRESTIMO]
Aluno: Maria Silva
Matricula: 20231042
Livro: Dom Casmurro
DataEmprestimo: 10/06/2026
DataEntrega: 20/06/2026
```

Os arquivos são atualizados automaticamente sempre que um livro é cadastrado, editado, excluído, emprestado ou devolvido. Ao iniciar o sistema, os dados são carregados para a memória através de `carregarLivros()` e `carregarEmprestimos()`.

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
gcc main.c livro.c emprestimo.c validacao.c -o biblioteca.exe
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
gcc main.c livro.c emprestimo.c validacao.c -o biblioteca.exe
```

Execute:

```bash
.\biblioteca.exe
```

---

## Menu do Sistema

```text
========== BIBLIOTECA ==========
1. Cadastrar Livro
2. Emprestar Livro
3. Devolver Livro
4. Listar Livros
5. Buscar Livro
6. Listar Empréstimos
7. Excluir Livro
8. Editar Livro
0. Sair
===============================
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

O sistema implementa o gerenciamento de livros e empréstimos utilizando listas encadeadas simples, TADs, alocação dinâmica de memória, persistência de dados em arquivos texto e validação completa de entradas com uso do relógio do sistema via `time.h`, atendendo e expandindo os requisitos propostos para a disciplina.
