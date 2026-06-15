#include <string.h>
#include <ctype.h>
#include <time.h>
#include "validacao.h"


int lerInteiro(const char *mensagem)
{
    char entrada[100];
    int valor;
    char extra;

    while (1)
    {
        printf("%s", mensagem);

        fgets(entrada, sizeof(entrada), stdin);

        if (sscanf(entrada, "%d %c", &valor, &extra) == 1)
        {
            return valor;
        }

        printf("Entrada inválida. Digite apenas números inteiros.\n");
    }
}

int validarNome(const char *nome)
{
    if (textoVazio(nome))
    {
        return 0;
    }

    for (int i = 0; nome[i] != '\0'; i++)
    {
        if (!isalpha((unsigned char)nome[i]) &&
            nome[i] != ' ' &&
            nome[i] != '.' &&
            nome[i] != '-')
        {
            return 0;
        }
    }

    return 1;
}
void lerString(const char *mensagem, char *buffer, int tamanho)
{
    do
    {
        printf("%s", mensagem);
        fgets(buffer, tamanho, stdin);

        // Se não leu o \n, ainda há dados no buffer — limpa
        if (strchr(buffer, '\n') == NULL) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }

        buffer[strcspn(buffer, "\n")] = '\0';

        if (textoVazio(buffer))
        {
            printf("O campo não pode ficar vazio.\n");
        }

    } while (textoVazio(buffer));
}

int textoVazio(const char *texto)
{
    while (*texto != '\0')
    {
        if (!isspace((unsigned char)*texto))
        {
            return 0; // Retorna 0 se encontrar um caractere que não seja espaço em branco
        }
        texto++;
    }
    return 1; // Retorna 1 se o texto for vazio ou contiver apenas espaços em branco
}

int validarCodigo(int codigo)
{
    return codigo > 0; // O código é válido se for um número positivo
}

int validarQuantidade(int quantidade)
{
    return quantidade > 0; // A quantidade é válida se for um número positivo
}

int validarMatricula(int matricula)
{
    return matricula > 0; // A matrícula é válida se for um número positivo
}

int validarAnoPublicacao(int ano)
{
    time_t t = time(NULL);
    struct tm *data = localtime(&t);

    int anoAtual = data->tm_year + 1900;
    return ano >= 1000 && ano <= anoAtual; // O ano de publicação é válido se estiver entre 1000 e o ano atual
}

int validarData(const char *data)
{
    int dia, mes, ano;

    if (sscanf(data, "%d/%d/%d", &dia, &mes, &ano) != 3)
        return 0;

    if (strlen(data) != 10)
        return 0;

    if (data[2] != '/' || data[5] != '/')
        return 0;

    for (int i = 0; i < 10; i++)
    {
        if (i == 2 || i == 5)
            continue;

        if (!isdigit((unsigned char)data[i]))
            return 0;
    }

    if (mes < 1 || mes > 12)
        return 0;

    int diasMes[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    /* Ano bissexto */
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
    {
        diasMes[1] = 29;
    }

    if (dia < 1 || dia > diasMes[mes - 1])
        return 0;

    return 1;
}

int validarDataEmprestimo(const char *data)
{
    int dia, mes, ano;

    if (!validarData(data))
    {
        return 0;
    }

    sscanf(data, "%d/%d/%d", &dia, &mes, &ano);

    time_t t = time(NULL);
    struct tm *hoje = localtime(&t);

    int diaAtual = hoje->tm_mday;
    int mesAtual = hoje->tm_mon + 1;
    int anoAtual = hoje->tm_year + 1900;

    if (ano > anoAtual)
        return 0;

    if (ano == anoAtual && mes > mesAtual)
        return 0;

    if (ano == anoAtual && mes == mesAtual && dia > diaAtual)
        return 0;

    return 1;
}

int validarDataEntrega(const char *dataEmprestimo, const char *dataEntrega)
{
    int diaEmp, mesEmp, anoEmp;
    int diaEnt, mesEnt, anoEnt;

    if (!validarData(dataEmprestimo))
        return 0;

    if (!validarData(dataEntrega))
        return 0;

    sscanf(dataEmprestimo, "%d/%d/%d",
           &diaEmp, &mesEmp, &anoEmp);

    sscanf(dataEntrega, "%d/%d/%d",
           &diaEnt, &mesEnt, &anoEnt);

    if (anoEnt < anoEmp)
        return 0;

    if (anoEnt == anoEmp && mesEnt < mesEmp)
        return 0;

    if (anoEnt == anoEmp &&
        mesEnt == mesEmp &&
        diaEnt < diaEmp)
        return 0;

    return 1;
}

int codigoJaExiste(Livro *livros, int codigo)
{
    Livro *atual = livros;
    while (atual != NULL)
    {
        if (atual->codlivro == codigo)
        {
            return 1; // Retorna 1 se o código já existir na lista de livros
        }
        atual = atual->prox;
    }
    return 0; // Retorna 0 se o código não existir na lista de livros
}

int tituloJaExiste(Livro *livros, const char *titulo)
{
    Livro *atual = livros;
    while (atual != NULL)
    {
        if (strcmp(atual->titulo, titulo) == 0)
        {
            return 1; // Retorna 1 se o título já existir na lista de livros
        }
        atual = atual->prox;
    }
    return 0; // Retorna 0 se o título não existir na lista de livros
}

int validarDisponibilidade(Livro *livros, const char *titulo)
{
    Livro *atual = livros;
    while (atual != NULL)
    {
        if (strcmp(atual->titulo, titulo) == 0)
        {
            return atual->quantidade > 0; // Retorna 1 se o livro estiver disponível (quantidade maior que 0) e 0 caso contrário
        }
        atual = atual->prox;
    }
    return 0; // Retorna 0 se o livro não for encontrado na lista de livros
}

int emprestimoJaExiste(Emprestimo *emprestimos, int matricula, const char *titulo)
{
    Emprestimo *atual = emprestimos;
    while (atual != NULL)
    {
        if (atual->matricula == matricula && strcmp(atual->titulolivro, titulo) == 0)
        {
            return 1; // Retorna 1 se um empréstimo já existir para o aluno e livro especificados
        }
        atual = atual->prox;
    }
    return 0; // Retorna 0 se nenhum empréstimo existir para o aluno e livro especificados
}

int matriculaCompativel(Emprestimo *emprestimos, int matricula, const char *nome)
{
    Emprestimo *atual = emprestimos;
    while (atual != NULL)
    {
        if (atual->matricula == matricula)
        {
            // Matrícula já existe — verifica se o nome bate
            if (strcmp(atual->nomealuno, nome) != 0)
            {
                return 0; // Matrícula pertence a outro aluno
            }
        }
        atual = atual->prox;
    }
    return 1; // Matrícula livre ou pertence ao mesmo aluno
}