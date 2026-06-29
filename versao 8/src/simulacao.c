#include <stdio.h>
#include "../include/simulacao.h"

void simularQuitarDivida(struct DadosFinanceiros *dados)
{
    float pagMensal, percentualQuitacao;
    float dividaRestante = dados->dividas;
    int meses = 0;

    printf("Quanto você consegue pagar por mês? \n");
    scanf("%f", &pagMensal);

    if (pagMensal <= 0.0f)
    {
        printf("Pagamento mensal inválido.\n");
        return;
    }

    while (dividaRestante > 0.0f)
    {
        dividaRestante -= pagMensal;
        meses++;

        if (dividaRestante < 0.0f)
        {
            dividaRestante = 0.0f;
        }
        printf("Mês %d - Dívida restante: R$ %.02f\n", meses, dividaRestante);
    }

    if (dados->salario > 0.0f)
    {
        percentualQuitacao = (pagMensal / dados->salario) * 100;
    }
    else
    {
        percentualQuitacao = 0.0f;
        printf("Salário não informado ou inválido. Percentual não calculado.\n");
    }

    printf("\nDívida inicial: R$ %.2f\n", dados->dividas);
    printf("Pagamento mensal: R$ %.2f\n", pagMensal);
    printf("Percentual de renda usado para quitar: %.1f%%\n", percentualQuitacao);
    printf("Você quitará a dívida em %d meses.\n", meses);
}
