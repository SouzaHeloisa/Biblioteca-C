#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

#include "livro.h"
#include "emprestimo.h"
#include "validacao.h"

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, ".UTF8");

    Livro *livros = NULL;
    Emprestimo *emprestimos = NULL;

    carregarLivros(&livros);
    carregarEmprestimos(&emprestimos);

    int opcao;

    do
    {
        system("cls");

        printf("\n========== BIBLIOTECA ==========\n");
        printf("1. Cadastrar Livro\n");
        printf("2. Emprestar Livro\n");
        printf("3. Devolver Livro\n");
        printf("4. Listar Livros\n");
        printf("5. Buscar Livro\n");
        printf("6. Listar Empréstimos\n");
        printf("7. Excluir Livro\n");
        printf("8. Editar Livro\n");
        printf("0. Sair\n");
        printf("===============================\n");

        opcao = lerInteiro("Escolha uma opção: ");

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

            lerString(
                "Digite o título do livro que deseja buscar: ",
                titulo,
                sizeof(titulo));

            buscarLivro(livros, titulo);
            break;
        }

        case 6:
            listarEmprestimos(emprestimos);
            break;

        case 7:
        {
            char titulo[50];

            lerString(
                "Digite o título do livro que deseja excluir: ",
                titulo,
                sizeof(titulo));

            excluirLivro(&livros, emprestimos, titulo);
            break;
        }

        case 8:
        {
            editarLivro(&livros, emprestimos);
            break;
        }

        case 0:
            printf("\nSaindo do sistema...\n");
            break;

        default:
            printf("\nOpção inválida.\n");
        }

        if (opcao != 0){
            printf("\nPressione Enter para continuar...");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }

    } while (opcao != 0);

    Livro *livroAtual = livros;
    while (livroAtual != NULL)
    {
        Livro *temp = livroAtual;
        livroAtual = livroAtual->prox;
        free(temp);
    }

    // Liberar lista de empréstimos
    Emprestimo *empAtual = emprestimos;
    while (empAtual != NULL)
    {
        Emprestimo *temp = empAtual;
        empAtual = empAtual->prox;
        free(temp);
    }

    return 0;
}