#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "dados.h"

// Salva os campos de `dados` no arquivo historico.txt (modo append).
void salvarAnalise(struct DadosFinanceiros *dados);

// Carrega o último registro de historico.txt para `dados`.
// Retorna 1 se carregou com sucesso, 0 caso contrário.
int carregarAnalise(struct DadosFinanceiros *dados);

// Exibe todo o conteúdo de historico.txt na tela.
void exibirHistorico(void);

#endif // ARQUIVO_H
