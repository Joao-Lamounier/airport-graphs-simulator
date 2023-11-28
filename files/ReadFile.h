#ifndef AIRPORT_GRAPHS_SIMULATOR_READFILE_H
#define AIRPORT_GRAPHS_SIMULATOR_READFILE_H

/**
 * Lê o conteúdo de um arquivo e retorna como uma string.
 *
 * @param filename Nome do arquivo a ser lido.
 * @return Conteúdo do arquivo como uma string alocada dinamicamente. Retorna NULL em caso de erro.
 */
char *readFile(const char *filename);

#endif //AIRPORT_GRAPHS_SIMULATOR_READFILE_H
