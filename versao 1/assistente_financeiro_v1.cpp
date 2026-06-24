#include <stdio.h>
int main() {
	//Valores de entrada a receber nas variaveis declaradas
	float salario;
	float gastosFixos;
	float dividas;
	float divida1;
	//Valores de entrada a calcular nas variaveis declaradas
	float totalGastos;
	float saldo;
	float percentual;
	float pagMensal;
	//Colocar variavel int para opções de continuar ou não
	int continuar = 1;
	int simular = 0;
	int meses;
	while (continuar ==1){
	
	//Entrada de dados, interação com o usuario e armazenamento de valor na variavel
	printf("\n===== ASSISTENTE FINANCEIRO =====\n");
	
	printf("Digite o seu salario mensal: \n");
	scanf("%f", &salario);
	
	printf("Mostre os seus gastos fixos: \n");
	scanf("%f", &gastosFixos);
	
	printf("Digite o valor de sua divida: \n");
	scanf("%f", &dividas);
	// Declarar operações matematicas das variaveis
	totalGastos = gastosFixos + dividas;
	saldo = salario - totalGastos;
	percentual = ((totalGastos / salario)*100);
	//Saida de dados
	printf("\nRELATORIO FINANCEIRO\n");
	
	printf("\nSalario: R$ %.2f\n", salario);
	printf("Gastos: R$ %.2f\n", totalGastos);
	printf("Saldo: R$ %.2f\n", saldo);
	printf("Percentual: %.2f%%\n", percentual);
	//Simulacao de divida
	printf("\n===== SIMULACAO DE DIVIDA =====\n");
	
	printf("\nDeseja fazer simulacao da divida?\n");
	printf("1 - Sim\n");
	printf("0 - Nao\n");
	scanf("%d", &simular); 
	meses = 0;
	if (simular == 1)
	{
	printf("Qual e o valor da sua divida?\n");
	scanf("%f", &divida1);
	
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
	//Decisoes inteligentes: alertas
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
	printf("\nDeseja fazer outra analise?\n");
	printf("1 - Sim\n");
	printf("0 - Nao\n");
	scanf("%d", &continuar);
}
	printf("\nPrograma Encerrado.\n");
	
return 0;
}