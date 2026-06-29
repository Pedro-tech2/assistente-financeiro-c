#include <stdio.h>
#include <windows.h>
#include "../include/menu.h"
#include "../include/analise.h"
#include "../include/metas.h"
#include "../include/simulacao.h"
#include "../include/utils.h"
#include "../include/arquivo.h"
#include "../include/dados.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    struct DadosFinanceiros dados = {0};
    int opcao = -1;

    while (1)
    {
        mostrarMenu();
        printf("\nDigite a opção: ");

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

            if (dados.salario <= 0.0f)
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
            dados.analiseFeita = 1;

            printf("\nSalário: R$ %.2f\n", dados.salario);
            printf("Saldo restante: R$ %.2f\n", dados.saldo);
            printf("Percentual gasto: %.1f%%\n", dados.percentual);
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

        case 8:
            if (dados.analiseFeita == 0)
            {
                printf("Primeiro realize a análise financeira antes de salvar.\n");
            }
            else
            {
                salvarAnalise(&dados);
            }
            break;

        case 9:
            if (carregarAnalise(&dados))
            {
                printf("\nÚltima análise carregada:\n");
                printf("Salário: R$ %.2f\n", dados.salario);
                printf("Gastos fixos: R$ %.2f\n", dados.gastosFixos);
                printf("Dívidas: R$ %.2f\n", dados.dividas);
                printf("Total gastos: R$ %.2f\n", dados.totalGastos);
                printf("Saldo: R$ %.2f\n", dados.saldo);
                printf("Percentual gasto: %.1f%%\n", dados.percentual);
            }
            else
            {
                printf("Nenhuma análise disponível para carregar.\n");
            }
            break;

        case 10:
            exibirHistorico();
            break;

        case 0:
            printf("Programa encerrado.\n");
            return 0;

        default:
            printf("\nOpção inválida.\n");
        }
    }

    return 0;
}
