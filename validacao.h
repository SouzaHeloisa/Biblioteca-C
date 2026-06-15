#ifndef VALIDACAO_H
#define VALIDACAO_H
#include <stdio.h>   // Inclusão da biblioteca padrão de entrada e saída
#include <stdlib.h>  // Inclusão da biblioteca padrão de utilidades
#include "livro.h"  // Inclusão do header para a estrutura Livro
#include "emprestimo.h" // Inclusão do header para a estrutura Emprestimo

int lerInteiro(const char *mensagem); // Declaração da função para ler um número inteiro do usuário, exibindo uma mensagem de prompt
int validarNome(const char *nome); // Declaração da função para validar o nome do aluno. Retorna 1 se o nome for válido (não vazio e sem caracteres inválidos) e 0 caso contrário.
void lerString(const char *mensagem, char *buffer, int tamanho); // Declaração da função para ler uma string do usuário, exibindo uma mensagem de prompt e armazenando a entrada em um buffer com um tamanho máximo

int textoVazio(const char *texto); // Declaração da função para verificar se um texto é vazio (sem caracteres ou apenas espaços em branco). Retorna 1 se o texto for vazio e 0 caso contrário.

int validarCodigo(int codigo); // Declaração da função para validar o código do livro. Retorna 1 se o código for válido (número positivo) e 0 caso contrário.
int validarQuantidade(int quantidade); // Declaração da função para validar a quantidade de livros. Retorna 1 se a quantidade for válida (número não negativo) e 0 caso contrário.
int validarMatricula(int matricula); // Declaração da função para validar a matrícula do aluno. Retorna 1 se a matrícula for válida (número positivo) e 0 caso contrário.
int validarAnoPublicacao(int ano); // Declaração da função para validar o ano de publicação do livro. Retorna 1 se o ano for válido (entre 1000 e o ano atual) e 0 caso contrário.

int validarData(const char *data); // Declaração da função para validar o formato de uma data. Retorna 1 se a data estiver no formato correto (dd/mm/aaaa) e 0 caso contrário.
int validarDataEmprestimo(const char *data); // Declaração da função para validar a data de empréstimo. Retorna 1 se a data de empréstimo for válida (não pode ser uma data futura) e 0 caso contrário.
int validarDataEntrega(const char *dataEmprestimo, const char *dataEntrega); // Declaração da função para validar a data de entrega. Retorna 1 se a data de entrega for válida (não pode ser anterior à data de empréstimo) e 0 caso contrário.

int codigoJaExiste(Livro *livros, int codigo); // Declaração da função para verificar se um código de livro já existe na lista de livros. Retorna 1 se o código já existir e 0 caso contrário.
int tituloJaExiste(Livro *livros, const char *titulo); // Declaração da função para verificar se um título de livro já existe na lista de livros. Retorna 1 se o título já existir e 0 caso contrário.

int validarDisponibilidade(Livro *livros, const char *titulo); // Declaração da função para validar a disponibilidade de um livro para empréstimo. Retorna 1 se o livro estiver disponível (quantidade maior que 0) e 0 caso contrário.

int emprestimoJaExiste(Emprestimo *emprestimos, int matricula, const char *titulo); // Declaração da função para verificar se um empréstimo já existe para um determinado aluno e livro. Retorna 1 se o empréstimo já existir e 0 caso contrário.
int matriculaCompativel(Emprestimo *emprestimos, int matricula, const char *nome); // Declaração da função para verificar se a matrícula do aluno é compatível com o nome fornecido. Retorna 1 se a matrícula for compatível com o nome e 0 caso contrário.

#endif /* VALIDACAO_H */