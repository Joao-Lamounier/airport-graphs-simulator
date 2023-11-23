#ifndef AIRPORT_GRAPHS_SIMULATOR_ROUTE_H
#define AIRPORT_GRAPHS_SIMULATOR_ROUTE_H

#define MAX_ROUTES 34

#define FILEROUTES "files/routes.txt"

typedef struct _Route {
    char source[4];
    char target[4];

    void (*toString)(struct _Route *);
} _Route;
typedef _Route *Route;


Route newRoute(char source[4], char target[4]);

void printRoute(Route route);

void newRoutes(Route routes[MAX_ROUTES]);


#endif //AIRPORT_GRAPHS_SIMULATOR_ROUTE_H
