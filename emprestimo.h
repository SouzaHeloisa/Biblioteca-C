#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H
#include <stdio.h>   // Inclusão da biblioteca padrão de entrada e saída
#include <stdlib.h>  // Inclusão da biblioteca padrão de utilidades
#include "livro.h"  // Inclusão do header para a estrutura Livro

typedef struct emprestimo{
    char nomealuno[50];
    int matricula;
    char titulolivro[50];
    char dataemprestimo[11];
    char dataentrega[11];
    struct emprestimo *prox;
} Emprestimo;

void emprestarLivro(Livro *livros, Emprestimo **emprestimos); // Declaração da função para emprestar um livro
void devolverLivro(Livro *livros, Emprestimo **emprestimos);  // Declaração da função para devolver um livro
void listarEmprestimos(Emprestimo *emprestimos);              // Declaração da função para listar os empréstimos realizados
void salvaremprestimos(Emprestimo *emprestimos);              // Declaração da função para salvar os empréstimos em um arquivo
void carregarEmprestimos(Emprestimo **emprestimos);           // Declaração da função para carregar os empréstimos de um arquivo

#endif /* EMPRESTIMO_H */