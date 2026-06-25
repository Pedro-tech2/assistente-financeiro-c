#include <stdio.h>
#include <windows.h>

// ============================================
// FUNÇÕES AUXILIARES
// ============================================

void mostrarMenu()
{
    printf("\n===== ASSISTENTE FINANCEIRO =====\n");
    printf("1 - Análise Financeira\n");
    printf("2 - Simulação e Quitação de Dívida\n");
    printf("3 - Diagnóstico e Dicas Financeiras\n");
    printf("4 - Reserva de Emergência\n");
    printf("5 - Meta Financeira\n");
    printf("6 - Economia Potencial\n");
    printf("7 - Análise de Despesas\n");  // Nova opção
    printf("0 - Sair\n");
}

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
    else if(percentual > 50)
    {
        printf("Situação moderada.\n");
        printf("Sugestão: acompanhar os gastos mensalmente.\n");
    }
    else
    {
        printf("Excelente controle financeiro.\n");
    }
}

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

void criarMeta()
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

void simularQuitarDivida(float salario, float dividas)
{
    float pagMensal, percentualQuitacao;
    float dividaRestante = dividas;
    int meses = 0;
            
    printf("Quanto você consegue pagar por mês? \n");
    scanf("%f", &pagMensal);
            
    if (pagMensal <= 0)
    {
        printf("Pagamento mensal inválido.\n");
    }
    else
    {
        while(dividaRestante > 0)
        {
            dividaRestante = dividaRestante - pagMensal;
            meses++;
            
            if (dividaRestante < 0)
            {
                dividaRestante = 0;
            }
            printf("Mês %d - Dívida restante: R$ %.2f\n", meses, dividaRestante);
        }
        
        percentualQuitacao = ((pagMensal / salario) * 100);
        printf("\nDívida inicial: R$ %.2f\n", dividas);
        printf("Pagamento mensal: R$ %.2f\n", pagMensal);
        printf("Percentual de renda usado para quitar: %.1f%%\n", percentualQuitacao);
        printf("Você quitará a dívida em %d meses.\n", meses);
    }
}

// ============================================
// NOVA FUNÇÃO: ANÁLISE DE DESPESAS COM ARRAY
// ============================================

void analisarDespesas()
{
    float despesas[5];
    float total = 0, maior = 0, menor, media;
    int i;
    
    printf("\n===== ANÁLISE DE DESPESAS =====\n");
    printf("Cadastre 5 despesas para análise:\n\n");
    
    // Loop único: lê, soma e calcula maior/menor
    for(i = 0; i < 5; i++)
    {
        printf("Digite a despesa %d: ", i + 1);
        scanf("%f", &despesas[i]);
        
        total += despesas[i];
        
        // Na primeira iteração, inicializa maior e menor
        if(i == 0)
        {
            maior = despesas[i];
            menor = despesas[i];
        }
        else
        {
            // Atualiza maior e menor no mesmo loop
            if(despesas[i] > maior)
            {
                maior = despesas[i];
            }
            if(despesas[i] < menor)
            {
                menor = despesas[i];
            }
        }
    }
    
    // Exibição organizada
    printf("\n=== Despesas Cadastradas ===\n");
    for(i = 0; i < 5; i++)
    {
        printf("Despesa %d: R$ %.2f\n", i + 1, despesas[i]);
    }
    
    printf("\n=== Resumo ===\n");
    printf("Total das despesas: R$ %.2f\n", total);
    printf("Maior despesa: R$ %.2f\n", maior);
    printf("Menor despesa: R$ %.2f\n", menor);
    
    media = total / 5;
    printf("Média das despesas: R$ %.2f\n", media);
}

// ============================================
// FUNÇÃO PRINCIPAL (MAIN)
// ============================================

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
    
    // Variável para limpar buffer (estava faltando no código original)
    int c;
        
    while (continuar == 1)
    {
        mostrarMenu();

        printf("\nDigite a opção: \n");
        if (scanf("%d", &opcao) != 1) 
        {
            while((c = getchar()) != '\n' && c != EOF); 
            
            printf("Opção inválida. Digite apenas números.\n");
            continue;
        }

        switch(opcao)
        {
            case 1:
                printf("\n===== ANÁLISE FINANCEIRA =====\n");
                
                printf("Digite o seu salário mensal: ");
                scanf("%f", &salario);
                
                if (salario <= 0)
                {
                    printf("O salário deve ser maior que zero.\n");
                    break;
                }
                
                printf("Digite os gastos fixos: ");
                scanf("%f", &gastosFixos);
                
                printf("Digite o valor de sua dívida: ");
                scanf("%f", &dividas);
                
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
            
            // ============================================
            // NOVO CASE 7: ANÁLISE DE DESPESAS
            // ============================================
            case 7:
                analisarDespesas();  // ← CHAMADA DA FUNÇÃO
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