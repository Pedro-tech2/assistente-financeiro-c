#include <stdio.h>
#include "../include/metas.h"

float calcularReserva(float gastosFixos)
{
    return gastosFixos * 6;
}

void calcularEconomiaPotencial(float saldo)
{
    if (saldo <= 0)
    {
        printf("O valor precisa ser maior que zero.\n");
    }
    else
    {
        printf("\nSe você guardar todo o saldo de R$ %.2f:\n", saldo);
        printf("Em um ano terá: R$ %.2f\n", saldo * 12);
        printf("Em dois anos terá: R$ %.2f\n", saldo * 24);
        printf("Em cinco anos terá: R$ %.2f\n", saldo * 60);
    }
}

void criarMeta(struct DadosFinanceiros *dados)
{
    float meta, economiaMensal, metaRestante;
    int meses = 0;

    printf("\n===== META FINANCEIRA =====\n");

    printf("Qual é sua meta financeira? (R$)\n");
    scanf("%f", &meta);

    if (meta <= 0)
    {
        printf("Meta inválida.\n");
        return;
    }

    printf("Quanto você consegue guardar por mês? (R$)\n");
    scanf("%f", &economiaMensal);

    if (economiaMensal <= 0)
    {
        printf("Valor inválido.\n");
    }
    else
    {
        metaRestante = meta;
        while (metaRestante > 0)
        {
            metaRestante = metaRestante - economiaMensal;
            meses++;
        }
        printf("Você atingirá a meta em %d meses.\n", meses);
    }
}
