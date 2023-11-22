#include <malloc.h>
#include <string.h>
#include "routes.h"
#include "../../files/readFile.h"

Route newRoute(char source[4], char target[4]) {
    Route route = (Route) malloc(sizeof(_Route));
    strcpy(route->source, source);
    strcpy(route->target, target);
    route->toString = printRoute;

    return route;
}

void printRoute(Route route) {
    printf("\n🛫 Origem: %s", route->source);
    printf("\n🛬 Destino: %s", route->target);
}

void newRoutes(Route routes[MAX_ROUTES]) {
    char *allRoutes = readFile(FILEROUTES);
    char *token = strtok(allRoutes, "\n");

    int count = 0;
    while (token != NULL && count < MAX_ROUTES) {
        char origin[4], target[4];

        if (sscanf(token, "%3s %3s", origin, target) ==2) {
            origin[3] = '\0';
            target[3] = '\0';

            routes[count] = newRoute(origin, target);
            count++;

        }
        token = strtok(NULL, "\n");
    }
}