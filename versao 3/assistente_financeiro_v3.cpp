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
	float saldo;
	float totalGastos;
	float percentual;
	float divida1;
	float pagMensal;
	float reserva;
	float meta;
	float metaRestante;
	float economiaMensal;
	float umAno;
	float doisAnos;
	float cincoAnos;
	float percentualQuitacao;
		
	while (continuar == 1)
	{
    printf("\n===== ASSISTENTE FINANCEIRO =====\n");
    printf("1 - Analise Financeira\n");
    printf("2 - Simulacao e Quitacao de Divida\n");
    printf("3 - Diagnostico e Dicas Financeiras\n");
    printf("4 - Reserva de Emergencia\n");
	printf("5 - Meta Financeira\n");
	printf("6 - Economia Potencial\n");
    printf("0 - Sair\n");

	printf("\nMENU\n\n");
	printf("Digite a opcao: \n");
    scanf("%d", &opcao);

    switch(opcao)
    {
        case 1:
			
			printf("ANALISE FINCANCEIRA\n");
			
			
			printf("Digite o seu salario mensal: \n");
			scanf("%f", &salario);
			
			if (salario <= 0)
			{
			    printf("O salario deve ser maior que zero.\n");
			break;
			}
			
			printf("Digite os gastos fixos: \n");
			scanf("%f", &gastosFixos);
			
			printf("Digite o valor de sua divida: \n");
			scanf("%f", &dividas);
			
			totalGastos = gastosFixos + dividas;
			saldo = salario - totalGastos;
			percentual = ((totalGastos / salario)*100);

			printf("\nSalario: %.2f\n", salario);
			printf("Saldo restante: %.2f\n", saldo);
			printf("Percentual gasto: %.1f%%\n", percentual);

			analiseFeita = 1;
			
			break;

        case 2:
            
			printf("SIMULACAO E QUITACAO DE DIVIDA\n");
            
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
			percentualQuitacao = ((pagMensal / salario)*100);
			printf("\nDivida atual: %.2f\n", dividas);
			printf("Pagamento mensal: %.2f\n", pagMensal);
			printf("Percentual de renda usado para quitar: %.1f%%\n", percentualQuitacao);
			printf("Voce quitara a divida em %d meses.\n", meses);
			}
			}
            break;

        case 3:
            printf("DIAGNÓSTICO E DICAS FINANCEIRAS.\n");
            
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
        
        case 4:
        	printf("RESERVA DE EMERGENCIA.\n");
        	 if (analiseFeita == 0)
            {
            	printf("Primeiro realize a analise financeira.\n");
			}
            else
            {
            	reserva = gastosFixos * 6;
            	printf("Reserva recomendada: %.2f\n", reserva);
        	}
			break;
		
		case 5:
			printf("\nMETA FINANCEIRA.\n");
			
			printf("Qual e sua meta financeira?\n");
			scanf("%f", &meta);
			
			if (meta <= 0)
			{
				printf("Meta invalida.\n");
				break;
			}
			
			printf("Quanto voce consegue guardar por mes?\n");
			scanf("%f", &economiaMensal);
			
			if (economiaMensal <= 0)
			{
				printf("Valor invalido.\n");
			}
			else 
			{
				meses = 0;
				metaRestante = meta;
				
				while (metaRestante > 0)
			{
				metaRestante = metaRestante - economiaMensal;
				meses++;
			}
			printf("Voce atingira a meta em %d meses.\n", meses);
			}
			break;
		
		case 6:
			printf("ECONOMIA POTENCIAL\n");
			
			if (analiseFeita == 0)
			{
            	printf("Primeiro realize a analise financeira.\n");
			}
            else
            {
            if (saldo <= 0)
            {
            	printf("Valor precisa ser maior que zero\n.");
			}
			else
			{
				umAno = saldo * 12;
				doisAnos = saldo * 24;
				cincoAnos = saldo * 60;
				
				printf("\nSe voce guardar todo o saldo de %.2f.\n", saldo);
				printf("\nEm um ano tera: %.2f\n", umAno);
				printf("Em dois anos tera: %.2f\n", doisAnos);
				printf("Em cinco anos tera: %.2f\n", cincoAnos);
			}
			}
			break;
			
        case 0:
            continuar = 0;
			printf("Programa encerrado.\n");
            break;
	
        default:
            printf("Opcao invalida.\n");
    }
	}
    return 0;
}