#ifndef ANALISE_H
#define ANALISE_H

#define QUANTIDADE_DESPESAS 5

float calcularTotalGastos(float gastosFixos, float dividas);
float calcularSaldo(float salario, float totalGastos);
float calcularPercentual(float totalGastos, float salario);
void mostrarDiagnostico(float saldo, float percentual);
void analisarDespesas(int analiseFeita, float dividas);

#endif