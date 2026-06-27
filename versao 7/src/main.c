#include <stdio.h>
#include <windows.h>
#include "../include/menu.h"
#include "../include/analise.h"
#include "../include/metas.h"
#include "../include/simulacao.h"
#include "../include/utils.h"
#include "../include/dados.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int opcao;
    int continuar = 1;

    struct DadosFinanceiros dados = {0};

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
            if (scanf("%f", &dados.salario) != 1)
            {
                limparBuffer();
                printf("Valor inválido.\n");
                break;
            }

            if (dados.salario <= 0)
            {
                printf("O salário deve ser maior que zero.\n");
                break;
            }

            printf("Digite os gastos fixos: ");
            if (scanf("%f", &dados.gastosFixos) != 1)
            {
                limparBuffer();
                printf("Valor inválido.\n");
                break;
            }

            printf("Digite o valor de sua dívida: ");
            if (scanf("%f", &dados.dividas) != 1)
            {
                limparBuffer();
                printf("Valor inválido.\n");
                break;
            }

            dados.totalGastos = calcularTotalGastos(dados.gastosFixos, dados.dividas);
            dados.saldo = calcularSaldo(dados.salario, dados.totalGastos);
            dados.percentual = calcularPercentual(dados.totalGastos, dados.salario);

            printf("\nSalário: R$ %.2f\n", dados.salario);
            printf("Saldo restante: R$ %.2f\n", dados.saldo);
            printf("Percentual gasto: %.1f%%\n", dados.percentual);
            dados.analiseFeita = 1;
            break;

        case 2:
            if (dados.analiseFeita == 0)
            {
                printf("Primeiro realize a análise financeira.\n");
            }
            else
            {
                simularQuitarDivida(&dados);
            }
            break;

        case 3:
            if (dados.analiseFeita == 0)
            {
                printf("Primeiro realize a análise financeira.\n");
            }
            else
            {
                mostrarDiagnostico(dados.saldo, dados.percentual);
            }
            break;

        case 4:
            if (dados.analiseFeita == 0)
            {
                printf("Primeiro realize a análise financeira.\n");
            }
            else
            {
                printf("\n===== RESERVA DE EMERGÊNCIA =====\n");
                printf("Reserva recomendada: R$ %.2f\n", calcularReserva(dados.gastosFixos));
            }
            break;

        case 5:
            criarMeta(&dados);
            break;

        case 6:
            if (dados.analiseFeita == 0)
            {
                printf("Primeiro realize a análise financeira.\n");
            }
            else
            {
                printf("\n===== ECONOMIA POTENCIAL =====\n");
                calcularEconomiaPotencial(dados.saldo);
            }
            break;

        case 7:
            analisarDespesas(&dados);
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
