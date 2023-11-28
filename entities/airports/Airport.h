#ifndef AIRPORT_GRAPHS_SIMULATOR_AIRPORT_H
#define AIRPORT_GRAPHS_SIMULATOR_AIRPORT_H

#define MAX_AIRPORTS 23

#define FILEAIRPORT "files/airports.txt"

typedef struct _Airport {
    char code[4];
    int timezone;
    int latitude;
    int longitude;
    char *city;
    char *state;

    void (*toString)(struct _Airport *);
} _Airport;
typedef _Airport *Airport;

/**
 * Cria um novo aeroporto com os parâmetros fornecidos.
 *
 * @param code Código do aeroporto (deve ter no máximo 3 caracteres).
 * @param timezone Fuso horário do aeroporto.
 * @param latitude Latitude do aeroporto.
 * @param longitude Longitude do aeroporto.
 * @param city Nome da cidade onde o aeroporto está localizado.
 * @param state Estado onde o aeroporto está localizado.
 * @return Novo aeroporto alocado dinamicamente.
 */
Airport newAirport(char code[3], int timezone, int latitude, int longitude, char *city, char *state);

/**
 * Lê informações de aeroportos de um arquivo e os armazena no array de aeroportos.
 *
 * @param airports Array de aeroportos onde as informações serão armazenadas.
 */
void newAirports(Airport airports[MAX_AIRPORTS]);

#endif //AIRPORT_GRAPHS_SIMULATOR_AIRPORT_H
