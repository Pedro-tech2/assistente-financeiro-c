#include <stdio.h>
#include "../include/analise.h"
#include "../include/utils.h"

float calcularTotalGastos(float gastosFixos, float dividas)
{
    return gastosFixos + dividas;
}

float calcularSaldo(float salario, float totalGastos)
{
    return salario - totalGastos;
}

float calcularPercentual(float totalGastos, float salario)
{
    if (salario == 0.0f)
    {
        return 0.0f;
    }
    return (totalGastos / salario) * 100;
}

void mostrarDiagnostico(float saldo, float percentual)
{
    printf("\n===== DIAGNÓSTICO E DICAS FINANCEIRAS =====\n");

    if (saldo < 0)
    {
        printf("Orçamento no vermelho.\n");
        printf("Sugestão: reduzir gastos e priorizar pagamento de dívidas.\n");
    }
    else if (percentual > 80)
    {
        printf("ATENÇÃO: você está gastando mais de 80%% da renda.\n");
        printf("Sugestão: criar uma reserva de emergência.\n");
    }
    else if (percentual > 50)
    {
        printf("Situação moderada.\n");
        printf("Sugestão: acompanhar os gastos mensalmente.\n");
    }
    else
    {
        printf("Excelente controle financeiro.\n");
    }
}

void analisarDespesas(struct DadosFinanceiros *dados)
{
    float despesas[QUANTIDADE_DESPESAS];
    float total = 0.0f, maior = 0.0f, menor = 0.0f, media;
    int i;

    printf("\n===== ANÁLISE DE DESPESAS =====\n");
    printf("Cadastre %d despesas para análise:\n\n", QUANTIDADE_DESPESAS);

    for (i = 0; i < QUANTIDADE_DESPESAS; i++)
    {
        printf("Digite a despesa %d: ", i + 1);

        if (scanf("%f", &despesas[i]) != 1)
        {
            printf("Erro: Digite apenas números!\n");
            limparBuffer();
            i--;
            continue;
        }

        if (despesas[i] <= 0)
        {
            printf("Erro: Despesa deve ser maior que zero!\n");
            limparBuffer();
            i--;
            continue;
        }

        total += despesas[i];

        if (i == 0)
        {
            maior = despesas[i];
            menor = despesas[i];
        }
        else
        {
            if (despesas[i] > maior)
            {
                maior = despesas[i];
            }
            if (despesas[i] < menor)
            {
                menor = despesas[i];
            }
        }
    }

    printf("\n=== Despesas Cadastradas ===\n");
    for (i = 0; i < QUANTIDADE_DESPESAS; i++)
    {
        printf("Despesa %d: R$ %.2f\n", i + 1, despesas[i]);
    }

    printf("\n=== Resumo ===\n");
    printf("Total das despesas: R$ %.2f\n", total);
    printf("Maior despesa: R$ %.2f\n", maior);
    printf("Menor despesa: R$ %.2f\n", menor);

    media = total / QUANTIDADE_DESPESAS;
    printf("Media das despesas: R$ %.2f\n", media);

    if (dados->analiseFeita == 1 && total > dados->totalGastos)
    {
        printf("\n⚠️  Atenção: Total de despesas (R$ %.2f) é maior que o total de gastos declarado (R$ %.2f)\n",
               total, dados->totalGastos);
        printf("    Considere revisar os valores.\n");
    }
}
