#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include "biblioteca.h"

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, " ");
    Livro *livros = NULL;           // Ponteiro para a lista de livros, inicialmente vazio
    Emprestimo *emprestimos = NULL; // Ponteiro para a lista de empréstimos, inicialmente vazio

    carregarLivros(&livros);           // Carrega os livros do arquivo para a lista
    carregarEmprestimos(&emprestimos); // Carrega os empréstimos do arquivo para a lista

    int opcao;

    do
    {
        system("cls"); // Limpa a tela para uma melhor visualização do menu
        printf("\nMenu:\n");
        printf("1. Cadastrar Livro\n");
        printf("2. Emprestar Livro\n");
        printf("3. Devolver Livro\n");
        printf("4. Listar Livros\n");
        printf("5. Buscar Livro\n");
        printf("6. Listar Empréstimos\n");
        printf("7. Excluir Livro\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            cadastrarLivro(&livros);
            break;
        case 2:
            emprestarLivro(livros, &emprestimos);
            break;
        case 3:
            devolverLivro(livros, &emprestimos);
            break;
        case 4:
            listarLivros(livros);
            break;
        case 5:
        {
            char titulo[50];
            printf("Digite o título do livro que deseja buscar: ");
            scanf(" %[^\n]", titulo);
            buscarLivro(livros, titulo);
            break;
        }
        case 6:
            listarEmprestimos(emprestimos);
            break;
        case 7:
        {
            char titulo[50];
            printf("Digite o título do livro que deseja excluir: ");
            scanf(" %[^\n]", titulo);
            excluirLivro(&livros, titulo);
            break;
        }
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
        }
        if (opcao != 0){
            printf("\nPressione Enter para continuar...");
            getchar(); // Limpa o buffer do teclado
            getchar(); // Aguarda o usuário pressionar Enter
        }
    } while (opcao != 0);

    return 0;
}