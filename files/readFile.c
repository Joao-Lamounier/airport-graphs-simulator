#include <bits/types/FILE.h>
#include <stdio.h>
#include <malloc.h>
#include "readFile.h"

char *readFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo %s\n", filename);
        return NULL;
    }

    // Determina o tamanho do arquivo
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Aloca memória para a string
    char *content = (char *)malloc(file_size + 1);
    if (content == NULL) {
        fclose(file);
        fprintf(stderr, "Erro ao alocar memória para o conteúdo do arquivo\n");
        return NULL; // Retorna NULL indicando falha na alocação de memória
    }

    // Lê o conteúdo do arquivo para a string
    fread(content, 1, file_size, file);
    content[file_size] = '\0'; // Adiciona o caractere nulo ao final da string

    fclose(file);
    return content;
}