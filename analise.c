#include <stdio.h>  
  
#include "..\include\analise.h"  
  
// Funá∆o: calcular total de gastos  
float calcularTotalGastos(float gastosFixos, float dividas)  
{  
    return gastosFixos + dividas;  
}  
  
// Funá∆o: calcular saldo restante  
float calcularSaldo(float salario, float totalGastos)  
{  
    return salario - totalGastos;  
}  
  
// Funá∆o: calcular percentual comprometido  
float calcularPercentual(float totalGastos, float salario)  
{  
    return (totalGastos / salario) * 100;  
}  
  
// Funá∆o: mostrar diagn¢stico e dicas  
void mostrarDiagnostico(float saldo, float percentual)  
{  
    printf("\n===== DIAGN‡STICO E DICAS FINANCEIRAS =====\n");  
  
    if (saldo < 0)  
    {  
        printf("Oráamento no vermelho.\n");  
        printf("Sugest∆o: reduzir gastos e priorizar pagamento de d°vidas.\n");  
    }  
    else if (percentual > 80)  
    {  
        printf("ATENÄ«O: vocà est† gastando mais de 80%%%% da renda.\n");  
        printf("Sugest∆o: criar uma reserva de emergància.\n");  
    }  
    else if(percentual > 50)  
    {  
        printf("Situaá∆o moderada.\n");  
        printf("Sugest∆o: acompanhar os gastos mensalmente.\n");  
    }  
    else  
    {  
        printf("Excelente controle financeiro.\n");  
    }  
}  
  
// Funá∆o: an†lise de despesas com array  
void analisarDespesas(int analiseFeita, float dividas)  
{  
    float despesas[QUANTIDADE_DESPESAS];  
    float total = 0, maior = 0, menor, media;  
    int i;  
    int c;  
  
    printf("\n===== ANµLISE DE DESPESAS =====\n");  
    printf("Cadastre %d despesas para an†lise:\n\n", QUANTIDADE_DESPESAS);  
  
    // Leitura das despesas com validaá∆o  
    for(i = 0; i < QUANTIDADE_DESPESAS; i++)  
    {  
        printf("Digite a despesa %d: ", i + 1);  
  
        // Validaá∆o: verifica se Ç um n£mero v†lido  
        if (scanf("%f", &despesas[i]) != 1)  
        {  
            printf("Erro: Digite apenas n£meros!\n");  
            while((c = getchar()) != '\n' && c != EOF);  
            i--;  
            continue;  
        }  
  
        // Validaá∆o: valor n∆o pode ser zero ou negativo  
        if (despesas[i] <= 0)  
        {  
            printf("Erro: Despesa deve ser maior que zero!\n");  
            i--;  
            continue;  
        }  
  
        total += despesas[i];  
  
        // Na primeira iteraá∆o, inicializa maior e menor  
        if(i == 0)  
        {  
            maior = despesas[i];  
            menor = despesas[i];  
        }  
        else  
        {  
            if(despesas[i] > maior)  
