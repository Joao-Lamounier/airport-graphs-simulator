#ifndef AIRPORT_GRAPHS_SIMULATOR_FLIGHT_H
#define AIRPORT_GRAPHS_SIMULATOR_FLIGHT_H

#define MAX_FLIGHTS 723

#define FILEFLIGHTS "files/flights.txt"

typedef struct _Flight {
    char airLine[3];
    int idFlight;
    char source[4];
    char *departure;
    char target[4];
    char *arrival;
    int stops;

    void (*toString)(struct _Flight *);
} _Flight;
typedef _Flight *Flight;

/**
 * Cria um novo voo com os parâmetros fornecidos.
 *
 * @param airLine Código da companhia aérea (deve ter no máximo 3 caracteres).
 * @param idFlight Identificador único do voo.
 * @param source Código do aeroporto de origem (deve ter no máximo 3 caracteres).
 * @param departure Data e hora de partida do voo.
 * @param target Código do aeroporto de destino (deve ter no máximo 3 caracteres).
 * @param arrival Data e hora de chegada do voo.
 * @param stops Número de escalas no voo.
 * @return Novo voo alocado dinamicamente.
 */
Flight
newFlight(char airLine[4], int idFlight, char source[4], char *departure, char target[4], char *arrival, int stops);

/**
 * Lê informações de voos de um arquivo e os armazena no array de voos.
 *
 * @param flights Array de voos onde as informações serão armazenadas.
 */
void newFlights(Flight flights[MAX_FLIGHTS]);

#endif //AIRPORT_GRAPHS_SIMULATOR_FLIGHT_H
