#include <stdio.h>
#include "../include/simulacao.h"

void simularQuitarDivida(struct DadosFinanceiros *dados)
{
    float pagMensal, percentualQuitacao;
    float dividaRestante = dados->dividas;
    int meses = 0;

    printf("Quanto você consegue pagar por mês? \n");
    scanf("%f", &pagMensal);

    if (pagMensal <= 0)
    {
        printf("Pagamento mensal inválido.\n");
    }
    else
    {
        while (dividaRestante > 0)
        {
            dividaRestante = dividaRestante - pagMensal;
            meses++;

            if (dividaRestante < 0)
            {
                dividaRestante = 0;
            } 
            printf("Mês %d - Dívida restante: R$ %.2f\n", meses, dividaRestante);
        }

        percentualQuitacao = ((pagMensal / dados->salario) * 100);
        printf("\nDívida inicial: R$ %.2f\n", dados->dividas);
        printf("Pagamento mensal: R$ %.2f\n", pagMensal);
        printf("Percentual de renda usado para quitar: %.1f%%\n", percentualQuitacao);
        printf("Você quitará a dívida em %d meses.\n", meses);
    }
}
