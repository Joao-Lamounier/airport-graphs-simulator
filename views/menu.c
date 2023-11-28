#include <stdio.h>
#include <unistd.h>
#include "menu.h"
#include "../utils/utils.h"
#include "../services/path_graph_matrix_service/PathGraphsMatrix.h"
#include "../services/payh_graph_list_service/PathGraphList.h"
#include "../services/airports_service/AirportsServices.h"
#include "../sounds/soundManipulator.h"


void printHeader() {
    color(5);
    printf("✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎︎✈︎✈︎✈︎✈︎︎✈︎✈︎✈✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎");
    printf("\n✈︎");
    color(7);
    printf("                             Bem-vindo ao                             ");
    color(5);
    printf("✈︎\n✈︎");
    color(7);
    printf("                               AeroGraph                              ");
    color(5);
    printf("✈︎\n");
    color(5);
    printf("✈︎");
    color(8);
    printf("               Controle Inteligente de Voos e Rotas Aéreas            ");
    color(5);
    printf("✈︎\n");
    printf("✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎︎✈︎✈︎✈︎✈︎︎✈︎✈︎✈✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎✈︎");
    color(7);

}
void animateText(const char *text) {
    for (int i = 0; text[i] != '\0'; i++) {
        putchar(text[i]);
        fflush(stdout);
        usleep(50000);
    }
}

void printMainMenu() {
    color(9);
    color(7);
    printf("\n");
    printf("\nSelecione uma opção: ");
    printf("\n1. Mostrar caminho entre 2 aeroportos");
    printf("\n2. Pesquisar voos diretos");
    printf("\n3. Viagem com menor custo (tempo e distância)");
    printf("\n4. Verificar se possível atingir todos os outros");
    printf("\n5. Verificar circuito Hamiltoniano");
    printf("\n6. Mostrar rotas");
    printf("\n7. Mostrar Voos");
    printf("\n8. Sair");
    color(9);
    printf("\n-> ");
    color(9);
}


bool mainMenu(GraphRoutes graphRoutes, GraphFlights graphFlights, bool *initial) {
    if (*initial) {
        initialSound();
        printHeader();
        color(4);
        animateText("\n\n                      Inicializando módulos...");
        color(9);
        usleep(500000);
        printf("\n\n");
        *initial = false;
    }

    int option;
    printMainMenu();
    scanf("%d", &option);

    if (option == 8) {
        finalSound();
        color(4);
        animateText("\n\n                    Saindo do programa. Até logo!\n\n");
        usleep(500000);
        return false;
    }

    designateOp(graphRoutes, graphFlights, option);

    return true;
}
void designateOp(GraphRoutes graphRoutes, GraphFlights graphFlights, int op) {
    switch (op) {
        case 1:
            pathInGraph(graphRoutes);
            break;
        case 2:
            getDirectFlights(graphFlights);
            break;
        case 3: {
            char codOrigin[4], codTarget[4];
            getCodeFromUser("origem", codOrigin);
            getCodeFromUser("destino", codTarget);
            shortestWay(graphRoutes, codOrigin, codTarget);
            shortestPathTime(graphFlights, codOrigin, codTarget);
            break;
        }
        case 4:
            accessToAll(graphRoutes, false);
            break;
        case 5:
            accessToAll(graphRoutes, true);
            break;
        case 6:
            graphRoutes->toString(graphRoutes);
            break;
        case 7:
            graphFlights->toString(graphFlights);
            break;
        default:
            printf("\nOpção inválida");
    }
}