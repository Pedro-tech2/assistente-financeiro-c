#include <stdio.h>
int main()
{
    int opcao;
    int continuar = 1;
	int simular = 0;
	int meses;
	int analiseFeita = 0;
	
	float salario;
	float gastosFixos;
	float dividas;
	float divida1;
	
	float totalGastos;
	float saldo;
	float percentual;
	float pagMensal;
		
    printf("===== ASSISTENTE FINANCEIRO =====\n");
    printf("1 - Analise Financeira\n");
    printf("2 - Simulacao de Divida\n");
    printf("3 - Dicas Financeiras\n");
    printf("0 - Sair\n");

    while (continuar ==1)
	{
	printf("\nMENU\n\n");
	printf("Digite a opcao: \n");
    scanf("%d", &opcao);

    switch(opcao)
    {
        case 1:
			
			printf("ANALISE FINCANCEIRA\n");
			
			printf("Digite o seu salario mensal: \n");
			scanf("%f", &salario);
			
			printf("Digite os gastos fixos: \n");
			scanf("%f", &gastosFixos);
			
			printf("Digite o valor de sua divida: \n");
			scanf("%f", &dividas);
			
			totalGastos = gastosFixos + dividas;
			saldo = salario - totalGastos;
			percentual = ((totalGastos / salario)*100);

			
			printf("\nSaldo restante: %.2f\n", saldo);
			analiseFeita = 1;
			break;

        case 2:
            
			printf("SIMULACAO DE DIVIDA\n");
            
            if (analiseFeita == 0)
            {
            	printf("Primeiro realize a analise financeira.\n");
			}
            else
        	{
			meses = 0;
			divida1 = dividas;
			
			printf("Quanto voce consegue pagar por mes?\n");
			scanf("%f", &pagMensal);
			
			if (pagMensal <= 0)
			{
				printf("Pagamento mensal invalido.\n");
			}
			else
			{
			while(divida1 > 0)
			{
				divida1 = divida1 - pagMensal;
				meses++;
			
			if (divida1 < 0)
			{
				divida1 = 0;
			}
				printf("Mes %d - Divida restante: %.2f\n", meses, divida1);
			}
			printf("\nVoce quitara a divida em %d meses.\n", meses);
			}
			}
            break;

        case 3:
            printf("DICAS FINANCEIRAS.\n");
            
            if (analiseFeita == 0)
            {
            	printf("Primeiro realize a analise financeira.\n");
			}
            else
            {
           	if (saldo < 0){
			printf("\nOrcamento no vermelho.\n");
			printf("\nSugestao: reduzir gastos e priorizar pagamento de dividas.\n");
			} 
			else if (percentual > 80)
			{
			printf("\nATENCAO: voce esta gastando mais de 80%% da renda.\n");
			printf("\nSugestao: criar uma reserva de emergencia.\n");
			}
			else if(percentual > 50)
			{
			printf("\nSituacao moderada.\n");
			printf("Sugestao: acompanhar os gastos mensalmente.\n");
			}
			else
			{
			printf("Excelente controle financeiro.\n");
			}
			analiseFeita = 1;
			}
            break;

        case 0:
            printf("Programa encerrado.\n");
            break;
	
        default:
            printf("Opcao invalida.\n");
    }
    printf("Deseja continuar?\n");
    printf("1 - Sim\n");
	printf("0 - Nao\n");
	scanf("%d", &continuar);
	}
    return 0;
}