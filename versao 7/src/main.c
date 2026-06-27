#include <stdio.h>
#include <windows.h>
#include "../include/menu.h"
#include "../include/analise.h"
#include "../include/metas.h"
#include "../include/simulacao.h"
#include "../include/utils.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int opcao;
    int continuar = 1;
    int analiseFeita = 0;

    float salario = 0;
    float gastosFixos = 0;
    float dividas = 0;
    float saldo = 0;
    float totalGastos = 0;
    float percentual = 0;

    while (continuar == 1)
    {
        mostrarMenu();

        printf("\nDigite a opção: \n");
        if (scanf("%d", &opcao) != 1)
        {
            limparBuffer();
            printf("Opção inválida. Digite apenas números.\n");
            continue;
        }

        switch (opcao)
        {
        case 1:
            printf("\n===== ANÁLISE FINANCEIRA =====\n");

            printf("Digite o seu salário mensal: ");
            if (scanf("%f", &salario) != 1)
            {
                limparBuffer();
                printf("Valor inválido.\n");
                break;
            }

            if (salario <= 0)
            {
                printf("O salário deve ser maior que zero.\n");
                break;
            }

            printf("Digite os gastos fixos: ");
            if (scanf("%f", &gastosFixos) != 1)
            {
                limparBuffer();
                printf("Valor inválido.\n");
                break;
            }

            printf("Digite o valor de sua dívida: ");
            if (scanf("%f", &dividas) != 1)
            {
                limparBuffer();
                printf("Valor inválido.\n");
                break;
            }

            totalGastos = calcularTotalGastos(gastosFixos, dividas);
            saldo = calcularSaldo(salario, totalGastos);
            percentual = calcularPercentual(totalGastos, salario);

            printf("\nSalário: R$ %.2f\n", salario);
            printf("Saldo restante: R$ %.2f\n", saldo);
            printf("Percentual gasto: %.1f%%\n", percentual);
            analiseFeita = 1;
            break;

        case 2:
            if (analiseFeita == 0)
            {
                printf("Primeiro realize a análise financeira.\n");
            }
            else
            {
                simularQuitarDivida(salario, dividas);
            }
            break;

        case 3:
            if (analiseFeita == 0)
            {
                printf("Primeiro realize a análise financeira.\n");
            }
            else
            {
                mostrarDiagnostico(saldo, percentual);
            }
            break;

        case 4:
            if (analiseFeita == 0)
            {
                printf("Primeiro realize a análise financeira.\n");
            }
            else
            {
                printf("\n===== RESERVA DE EMERGÊNCIA =====\n");
                printf("Reserva recomendada: R$ %.2f\n", calcularReserva(gastosFixos));
            }
            break;

        case 5:
            criarMeta();
            break;

        case 6:
            if (analiseFeita == 0)
            {
                printf("Primeiro realize a análise financeira.\n");
            }
            else
            {
                printf("\n===== ECONOMIA POTENCIAL =====\n");
                calcularEconomiaPotencial(saldo);
            }
            break;

        case 7:
            analisarDespesas(analiseFeita, dividas);
            break;

        case 0:
            continuar = 0;
            printf("Programa encerrado.\n");
            break;

        default:
            printf("\nOpção inválida.\n");
        }
    }

    return 0;
}
