#include <stdio.h>
#include <string.h>
#include "../include/arquivo.h"

// Cada registro: uma linha com os 7 campos separados por espaços, seguida de uma linha "---"
// Exemplo:
// 2500.00 800.00 2000.00 2800.00 700.00 28.0 1
// ---

void salvarAnalise(struct DadosFinanceiros *dados)
{
    FILE *f = fopen("historico.txt", "a");
    if (f == NULL)
    {
        printf("Erro ao abrir historico.txt para escrita.\n");
        return;
    }

    fprintf(f, "Salario: %.2f\n", dados->salario);
    fprintf(f, "Gastos Fixos: %.2f\n", dados->gastosFixos);
    fprintf(f, "Dívidas: %.2f\n", dados->dividas);
    fprintf(f, "Total de Gastos: %.2f\n", dados->totalGastos);
    fprintf(f, "Saldo: %.2f\n", dados->saldo);
    fprintf(f, "Percentual: %.2f\n", dados->percentual);
    fprintf(f, "Análise Feita: %d\n", dados->analiseFeita);
    fprintf(f, "---\n");

    fclose(f);
    printf("Análise salva em historico.txt\n");
}

int carregarAnalise(struct DadosFinanceiros *dados)
{
    FILE *f = fopen("historico.txt", "r");
    if (f == NULL)
    {
        return 0;
    }

    char line[256];
    struct DadosFinanceiros temp = {0};
    int loaded = 0;

    while (fgets(line, sizeof(line), f) != NULL)
    {
        char *p = line;
        while (*p == ' ' || *p == '\t') p++;

        if (p[0] == '-')
        {
            // fim de um registro — marca como carregado
            if (temp.analiseFeita == 1)
            {
                loaded = 1;
            }
            continue;
        }

        float valor;
        int intValor;

        if (sscanf(p, "Salario: %f", &valor) == 1)
            temp.salario = valor;
        else if (sscanf(p, "Gastos Fixos: %f", &valor) == 1)
            temp.gastosFixos = valor;
        else if (sscanf(p, "Dívidas: %f", &valor) == 1)
            temp.dividas = valor;
        else if (sscanf(p, "Total de Gastos: %f", &valor) == 1)
            temp.totalGastos = valor;
        else if (sscanf(p, "Saldo: %f", &valor) == 1)
            temp.saldo = valor;
        else if (sscanf(p, "Percentual: %f", &valor) == 1)
            temp.percentual = valor;
        else if (sscanf(p, "Análise Feita: %d", &intValor) == 1)
            temp.analiseFeita = intValor;
    }

    fclose(f);

    if (loaded)
    {
        *dados = temp;
        return 1;
    }
    return 0;
}

void exibirHistorico(void)
{
    FILE *f = fopen("historico.txt", "r");
    if (f == NULL)
    {
        printf("Nenhum histórico encontrado (historico.txt não existe).\n");
        return;
    }

    char buffer[512];
    printf("===== HISTÓRICO DE ANÁLISES =====\n");
    while (fgets(buffer, sizeof(buffer), f) != NULL)
    {
        printf("%s", buffer);
    }
    printf("===== FIM DO HISTÓRICO =====\n");

    fclose(f);
}
