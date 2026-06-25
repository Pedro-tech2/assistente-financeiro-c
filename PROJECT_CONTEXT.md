# Assistente Financeiro - Contexto do Projeto

## Visão Geral

O Assistente Financeiro é um projeto pessoal desenvolvido em linguagem C com foco principal em aprendizado.

O projeto está sendo construído gradualmente por um estudante de Análise e Desenvolvimento de Sistemas (ADS), atualmente em fase inicial da graduação.

O objetivo não é apenas criar um software funcional, mas utilizar o projeto como ferramenta prática para aprender os fundamentos da programação e do desenvolvimento de software.

Cada nova versão deve introduzir novos conceitos de forma progressiva, permitindo consolidar o conhecimento adquirido nas disciplinas da faculdade.

---

# Objetivos de Aprendizado

O projeto foi criado para praticar:

* Lógica de programação
* Entrada e saída de dados
* Variáveis
* Operadores matemáticos
* Estruturas condicionais
* Estruturas de repetição
* Funções
* Arrays (vetores)
* Modularização
* Structs
* Manipulação de arquivos
* Organização de projetos
* Controle de versão com Git e GitHub

O foco está em compreender profundamente cada conceito antes de avançar para o próximo.

---

# Objetivo do Sistema

O Assistente Financeiro tem como finalidade auxiliar usuários no controle básico das finanças pessoais.

Atualmente o sistema permite:

* Análise financeira
* Simulação de quitação de dívidas
* Diagnóstico financeiro
* Sugestões financeiras
* Cálculo de reserva de emergência
* Planejamento de metas financeiras
* Estimativa de economia potencial

---

# Histórico das Versões

## Versão 1 (V1)

Objetivo:

Aprender entrada e saída de dados.

Conceitos utilizados:

* printf()
* scanf()
* Variáveis simples

Funcionalidade:

* Receber salário
* Receber gastos
* Mostrar saldo

---

## Versão 2 (V2)

Objetivo:

Praticar estruturas condicionais.

Conceitos utilizados:

* if
* else if
* else

Funcionalidade:

* Classificação básica da situação financeira
* Mensagens diferentes conforme o saldo

---

## Versão 3 (V3)

Objetivo:

Praticar estruturas de repetição.

Conceitos utilizados:

* while

Funcionalidade:

* Simulação de pagamento de dívidas mês a mês
* Cálculo do tempo necessário para quitar dívidas

---

## Versão 4 (V4)

Objetivo:

Praticar menus e navegação do programa.

Conceitos utilizados:

* switch
* case
* break

Funcionalidade:

* Menu principal
* Separação das funcionalidades

---

## Versão 5 (V5)

Objetivo:

Praticar criação e uso de funções.

Conceitos utilizados:

* Funções sem retorno (void)
* Funções com retorno (float)

Funções criadas:

* mostrarMenu()
* mostrarDiagnostico()
* calcularTotalGastos()
* calcularSaldo()
* calcularPercentual()
* calcularReserva()
* calcularEconomiaPotencial()
* criarMeta()
* simularQuitarDivida()

Benefícios:

* Código mais organizado
* Reaproveitamento de lógica
* Melhor manutenção

---

# Funcionalidades Atuais

## 1 - Análise Financeira

Recebe:

* Salário
* Gastos fixos
* Dívidas

Calcula:

* Total de gastos
* Saldo restante
* Percentual comprometido da renda

---

## 2 - Simulação e Quitação de Dívida

Recebe:

* Valor da dívida
* Pagamento mensal

Calcula:

* Quantidade de meses necessários
* Evolução da dívida mês a mês

---

## 3 - Diagnóstico e Dicas Financeiras

Analisa:

* Saldo
* Percentual comprometido

Retorna sugestões de acordo com a situação financeira.

---

## 4 - Reserva de Emergência

Calcula:

* Seis meses de gastos fixos

Objetivo:

Mostrar valor recomendado para uma reserva financeira.

---

## 5 - Meta Financeira

Recebe:

* Valor da meta
* Economia mensal

Calcula:

* Quantidade de meses para atingir a meta

---

## 6 - Economia Potencial

Utiliza o saldo mensal disponível para projetar:

* 1 ano
* 2 anos
* 5 anos

de acumulação financeira.

---

# Tecnologias Utilizadas

Linguagem:

* C

IDE Inicial:

* Dev-C++

IDE Atual:

* Visual Studio Code

Controle de Versão:

* Git
* GitHub

Sistema Operacional:

* Windows

---

# Próximas Etapas Planejadas

## V6 - Arrays

Objetivo:

Aprender armazenamento de múltiplos valores.

Exemplos:

* Despesas mensais
* Histórico de gastos

Conceitos:

```c
float despesas[12];
```

---

## V7 - Modularização

Objetivo:

Separar o projeto em múltiplos arquivos.

Estrutura prevista:

```text
src/
│
├── main.c
├── menu.c
├── financeiro.c
├── simulacao.c

include/
│
├── menu.h
├── financeiro.h
├── simulacao.h
```

---

## V8 - Structs

Objetivo:

Agrupar informações relacionadas.

Exemplo:

```c
struct Usuario
{
    float salario;
    float gastosFixos;
    float dividas;
};
```

---

## V9 - Arquivos

Objetivo:

Persistir dados.

Conceitos:

* fopen()
* fprintf()
* fscanf()
* fclose()

Exemplos:

* Salvar análises
* Salvar histórico financeiro
* Carregar dados salvos

---

## V10 - Projeto de Portfólio

Objetivo:

Transformar o Assistente Financeiro em um projeto completo para GitHub.

Recursos esperados:

* Funções
* Arrays
* Structs
* Arquivos
* Modularização
* Documentação

---

# Filosofia do Projeto

O objetivo principal não é apenas finalizar um software.

O objetivo é utilizar o Assistente Financeiro como um laboratório prático para aprender programação e desenvolvimento de software de forma gradual.

Cada nova versão deve introduzir poucos conceitos novos, mantendo o foco no aprendizado sólido e na compreensão do funcionamento interno do código.

A prioridade é aprender bem os fundamentos antes de avançar para tópicos mais complexos.

---

# Perfil do Desenvolvedor

Curso:

* Análise e Desenvolvimento de Sistemas (ADS)

Fase:

* Início da graduação (transição para o 2º período)

Objetivo:

* Construir base sólida em programação
* Desenvolver projetos próprios
* Aprender Git e GitHub
* Criar portfólio técnico
* Evoluir gradualmente para projetos maiores envolvendo Python, banco de dados, redes, cloud e desenvolvimento de software
