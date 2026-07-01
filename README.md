Assistente Financeiro Pessoal

Projeto em console desenvolvido para praticar conceitos de programação em C/C++, com foco em organização financeira básica, cálculo de saldo, diagnóstico de gastos e simulação de dívidas.

---

Objetivo

Construir um assistente financeiro simples, com evolução gradual de funcionalidades, desde operações básicas até uma estrutura mais modular e organizada.

---

Evolução do projeto

Versão 1
- Entrada de dados básicos: salário, gastos fixos e dívidas
- Cálculo simples de saldo e percentual gasto
- Primeira versão de execução em console

Versão 2
- Melhor organização do fluxo do programa
- Introdução de validações básicas
- Uso de estruturas condicionais para decisões

Versão 3
- Implementação de repetição com laços
- Simulação de quitação de dívidas
- Mensagens de diagnóstico financeiro

Versão 4
- Menu interativo com switch/case
- Divisão das funcionalidades em opções do sistema
- Melhor experiência de uso no terminal

Versão 5
- Maior organização do código
- Evolução das regras de negócio para análise financeira
- Inclusão de dicas e sugestões com base no saldo e percentual

Versão 6
- Introdução de funções para separar responsabilidades
- Criação de funções para reserva de emergência, meta financeira e economia potencial
- Análise de despesas com arrays

Versão 7
- Estruturação em múltiplos arquivos: header e implementação
- Uso de structs para armazenar dados financeiros
- Melhor separação entre menu, análise, metas e simulação

Versão 8
- Organização modular em pastas: src, include, tools e output
- Persistência em arquivo com salvamento e carregamento de análises
- Exibição de histórico de registros
- Tratamento mais robusto de entrada de dados
- Suporte a encoding UTF-8 no console

---

Principais funcionalidades

- Cálculo de total de gastos
- Cálculo de saldo restante
- Cálculo de percentual gasto em relação à renda
- Simulação de quitação de dívidas
- Diagnóstico financeiro com dicas
- Cálculo de reserva de emergência
- Definição de metas financeiras
- Estimativa de economia potencial
- Análise de despesas básicas
- Persistência das informações em arquivo

---

Tecnologias e ferramentas

- Linguagem: C
- Compilador: GCC / MinGW
- Ambiente de desenvolvimento: VS Code
- Controle de versão: Git / GitHub
- Estrutura: módulos separados em arquivos .c e .h

---

Como executar a versão 8

1. Abra a pasta do projeto
2. Entre na pasta da versão 8
3. Execute o script de build:
   - Windows PowerShell: `.\tools\build_all.bat`
4. O executável será gerado em `output/assistente.exe`

Ou, alternativamente, compile manualmente com o GCC, incluindo os arquivos da pasta src.

---

Próximos passos

- Interface gráfica
- Banco de dados ou armazenamento mais robusto
- Validações mais completas
- Exportação de relatórios
- Testes automatizados