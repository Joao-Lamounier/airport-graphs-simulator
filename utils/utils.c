#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"

#define ANSI_COLOR_BLACK   "\x1b[30m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_WHITE   "\x1b[37m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_GRAY    "\x1b[90m"


void color(int color) {
    switch (color) {
        case 0:
            printf(ANSI_COLOR_BLACK);
            break;
        case 1:
            printf(ANSI_COLOR_RED);
            break;
        case 2:
            printf(ANSI_COLOR_GREEN);
            break;
        case 3:
            printf(ANSI_COLOR_YELLOW);
            break;
        case 4:
            printf(ANSI_COLOR_BLUE);
            break;
        case 5:
            printf(ANSI_COLOR_MAGENTA);
            break;
        case 6:
            printf(ANSI_COLOR_CYAN);
            break;
        case 7:
            printf(ANSI_COLOR_WHITE);
            break;
        case 8:
            printf(ANSI_COLOR_GRAY);
            break;
        default:
            printf(ANSI_COLOR_RESET);
            break;
    }
}


void hour24Converter(const char *input, char *output) {
    int hours, minutes;
    char period;

    if (strlen(input) == 5) {
        sscanf(input, "%2d%2d%c", &hours, &minutes, &period);

        if (hours == 12) {
            hours = (period == 'P') ? 12 : 0;
        } else {
            hours = (period == 'P') ? hours + 12 : hours;
        }
    } else if (strlen(input) == 4) {
        sscanf(input, "%1d%2d%c", &hours, &minutes, &period);

        if (hours == 12) {
            hours = (period == 'P') ? 12 : 0;
        } else {
            hours = (period == 'P') ? hours + 12 : hours;
        }
    } else {
        printf("Invalid input format.\n");
        return;
    }

    sprintf(output, "%02d:%02d", hours, minutes);
}


void addTime(const char *currentTime, char *newTime, int sum) {
    int currentHour, currentMinute;
    sscanf(currentTime, "%d:%d", &currentHour, &currentMinute);

    currentHour = (currentHour + sum) % 24;

    sprintf(newTime, "%02d:%02d", currentHour, currentMinute);
}

void timeZoneToUTC(const char *input, char *output, int timeZone) {
    timeZone = (timeZone * (-1)) / 100;

    hour24Converter(input, output);
    addTime(output, output, timeZone);
}

int tempoParaMinutos(const char *hora) {
    int horas, minutos;
    sscanf(hora, "%d:%d", &horas, &minutos);
    return horas * 60 + minutos;
}

int timeDifference(const char *h1, const char *h2) {
    int minutos_h1 = tempoParaMinutos(h1);
    int minutos_h2 = tempoParaMinutos(h2);


    int diferenca_minutos = minutos_h2 - minutos_h1;

    if (diferenca_minutos < 0) {
        diferenca_minutos += 24 * 60;
    }

    return diferenca_minutos;
}

void convertMinutesToHours(char *output, int minutes) {
    if (output == NULL) {
        printf("Error: Invalid output pointer.\n");
        return;
    }

    int hours = minutes / 60;
    int remainingMinutes = minutes % 60;

    sprintf(output, "%02d:%02d", hours, remainingMinutes);
}