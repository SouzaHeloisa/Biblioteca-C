#ifndef BIBLIOTECA_H // Include guard para evitar múltiplas inclusões do mesmo header
#define BIBLIOTECA_H // Definição das estruturas Livro e Emprestimo
#include <stdio.h> // Inclusão da biblioteca padrão de entrada e saída
#include <stdlib.h> // Inclusão da biblioteca padrão de utilidades

typedef struct livro Livro; // Declaração da estrutura Livro para uso posterior
typedef struct emprestimo Emprestimo; // Declaração da estrutura Emprestimo para uso posterior

void cadastrarLivro(Livro *livros); // Declaração da função para cadastrar um livro
void emprestarLivro(Livro *livros, Emprestimo *emprestimos); // Declaração da função para emprestar um livro
void devolverLivro(Livro *livros, Emprestimo *emprestimos); // Declaração da função para devolver um livro
void listarLivros(Livro *livros); // Declaração da função para listar os livros disponíveis
void buscarLivro(Livro *livros, char *titulo); // Declaração da função para buscar um livro pelo título
void listarEmprestimos(Emprestimo *emprestimos); // Declaração da função para listar os empréstimos realizados
void excluirLivro(Livro *livros, char *titulo); // Declaração da função para excluir um livro
void salvarlivros(Livro *livros); // Declaração da função para salvar os livros em um arquivo
void salvaremprestimos(Emprestimo *emprestimos); // Declaração da função para salvar os empréstimos em um arquivo
void carregarLivros(Livro **livros); // Declaração da função para carregar os livros de um arquivo
void carregarEmprestimos(Emprestimo **emprestimos); // Declaração da função para carregar os empréstimos de um arquivo


#endif /* BIBLIOTECA_H */ // Fim do include guard