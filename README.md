# Assistente Financeiro Pessoal

Projeto em console desenvolvido para praticar conceitos de programação em C, com foco em organização financeira básica, análise de gastos, simulação de dívidas e planejamento financeiro pessoal.

## Objetivo

Construir um assistente financeiro simples, mas funcional, que evolui progressivamente à medida que novos conceitos de programação são aprendidos e aplicados.

## Evolução do projeto

### Versão 1
- Entrada de dados básicos: salário, gastos fixos e dívidas
- Cálculo simples de saldo e percentual gasto
- Primeira versão com interação no terminal

### Versão 2
- Menu interativo com switch/case
- Divisão das funcionalidades em opções do sistema
- Melhor organização do fluxo do programa
- Introdução de validações básicas

### Versão 3
- Implementação de repetição com laços
- Simulação de quitação de dívidas
- Mensagens de diagnóstico financeiro
- Uso de estruturas condicionais para decisões

### Versão 4
- Organização e melhoria do fluxo do programa
- Refinamento das funcionalidades principais
- Melhor experiência de uso no terminal

### Versão 5
- Maior organização do código
- Evolução das regras de negócio para análise financeira
- Inclusão de dicas e sugestões com base no saldo e percentual

### Versão 6
- Introdução de funções para separar responsabilidades
- Criação de funções para reserva de emergência, meta financeira e economia potencial
- Análise de despesas com arrays

### Versão 7
- Estruturação em múltiplos arquivos: cabeçalhos e implementação
- Uso de structs para armazenar dados financeiros
- Melhor separação entre menu, análise, metas e simulação

### Versão 8
- Organização modular em pastas: src, include, tools e output
- Persistência em arquivo com salvamento e carregamento de análises
- Exibição de histórico de registros
- Tratamento mais robusto de entrada de dados
- Suporte a UTF-8 no console

## Funcionalidades principais

- Cálculo do total de gastos
- Cálculo do saldo restante
- Cálculo do percentual gasto em relação à renda
- Simulação de quitação de dívidas
- Diagnóstico financeiro com dicas
- Cálculo de reserva de emergência
- Definição de metas financeiras
- Estimativa de economia potencial
- Análise básica de despesas
- Persistência das informações em arquivo

## Tecnologias e ferramentas

- Linguagem: C
- Compilador: GCC / MinGW
- Ambiente de desenvolvimento: VS Code
- Controle de versão: Git / GitHub
- Estrutura: módulos separados em arquivos .c e .h
- .gitignore configurado para ignorar binários e dados pessoais

## Como executar a versão 8

1. Abra a pasta do projeto.
2. Acesse a pasta da versão 8.
3. Execute o script de build no PowerShell:
   - `.\tools\build_all.bat`
4. O executável será gerado em `output/assistente.exe`.

Também é possível compilar manualmente com o GCC, incluindo os arquivos da pasta src.

## Próximos passos

- versão em Python com API web
- integração com banco de dados
- evolução contínua conforme novos conceitos forem aprendidos