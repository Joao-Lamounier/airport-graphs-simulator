#ifndef AIRPORT_GRAPHS_SIMULATOR_UTILS_H
#define AIRPORT_GRAPHS_SIMULATOR_UTILS_H

/**
 * Aplica uma cor ANSI ao texto no terminal.
 *
 * @param color Número correspondente à cor desejada:
 *              0: Preto, 1: Vermelho, 2: Verde, 3: Amarelo,
 *              4: Azul, 5: Magenta, 6: Ciano, 7: Branco, 8: Cinza.
 *              Qualquer outro número ou valor padrão: Reset.
 */
void color(int color);

/**
 * Converte uma hora de um fuso horário para UTC.
 *
 * @param input Hora no formato de 12 ou 24 horas.
 * @param output Saída para a hora em UTC.
 * @param timeZone Diferença em minutos entre o fuso horário local e UTC.
 */
void timeZoneToUTC(const char *input, char *output, int timeZone);

/**
 * Calcula a diferença em minutos entre duas horas no formato HH:mm.
 *
 * @param h1 Primeira hora.
 * @param h2 Segunda hora.
 * @return Diferença em minutos.
 */
int timeDifference(const char *h1, const char *h2);

/**
 * Converte um valor em minutos para o formato HH:mm.
 *
 * @param output Saída para a hora convertida.
 * @param minutes Valor em minutos a ser convertido.
 */
void convertMinutesToHours(char *output, int minutes);

#endif //AIRPORT_GRAPHS_SIMULATOR_UTILS_H
