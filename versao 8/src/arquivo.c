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

    fprintf(f, "%.2f %.2f %.2f %.2f %.2f %.2f %d\n", dados->salario, dados->gastosFixos, dados->dividas, dados->totalGastos, dados->saldo, dados->percentual, dados->analiseFeita);
    fprintf(f, "---\n");

    fclose(f);
    printf("Análise salva em historico.txt\n");
}

int carregarAnalise(struct DadosFinanceiros *dados)
{
    FILE *f = fopen("historico.txt", "r");
    if (f == NULL)
    {
        return 0; // não existe histórico
    }

    char line[256];
    struct DadosFinanceiros temp = {0};
    int loaded = 0;

    // Lê linha a linha; qualquer linha que não comece com '-' deve conter os valores
    while (fgets(line, sizeof(line), f) != NULL)
    {
        // remover espaços iniciais
        char *p = line;
        while (*p == ' ' || *p == '\t') p++;
        if (p[0] == '-' )
        {
            continue; // separador
        }

        // tenta parsear 7 campos
        float salario, gastosFixos, dividas, totalGastos, saldo, percentual;
        int analiseFeita;
        int n = sscanf(p, "%f %f %f %f %f %f %d", &salario, &gastosFixos, &dividas, &totalGastos, &saldo, &percentual, &analiseFeita);
        if (n == 7)
        {
            temp.salario = salario;
            temp.gastosFixos = gastosFixos;
            temp.dividas = dividas;
            temp.totalGastos = totalGastos;
            temp.saldo = saldo;
            temp.percentual = percentual;
            temp.analiseFeita = analiseFeita;
            loaded = 1;
        }
    }

    fclose(f);

    if (loaded)
    {
        *dados = temp; // copia os valores lidos
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
