#ifndef LIVRO_H // Include guard para evitar múltiplas inclusões do mesmo header
#define LIVRO_H
#include <stdio.h>   
#include <stdlib.h> 

typedef struct livro
{
    int codlivro;
    char titulo[50];
    char autor[50];
    int anopublicacao;
    int quantidade;
    struct livro *prox;
} Livro;

void cadastrarLivro(Livro **livros);                          // Declaração da função para cadastrar um livro
void listarLivros(Livro *livros);                             // Declaração da função para listar os livros disponíveis
void buscarLivro(Livro *livros, char *titulo);                // Declaração da função para buscar um livro pelo título
void excluirLivro(Livro **livros, char *titulo);              // Declaração da função para excluir um livro
void salvarlivros(Livro *livros);                             // Declaração da função para salvar os livros em um arquivo
void carregarLivros(Livro **livros);                          // Declaração da função para carregar os livros de um arquivo

#endif /* LIVRO_H */ // Fim do include guard
