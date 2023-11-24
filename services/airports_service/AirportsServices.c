#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "AirportsServices.h"

bool isValidCode(const char code[]) {
    if (strlen(code) != 3) {
        printf("O código deve ter exatamente três letras.\n");
        return false;
    }

    for (int i = 0; i < 3; ++i) {
        if (!isalpha(code[i])) {
            printf("O código deve conter apenas letras.\n");
            return false;
        }
    }
    return true;
}
void getCodeFromUser(const char *prompt, char code[]) {
    do {
        printf("✈️ Insira o código do aeroporto de %s: ", prompt);
        scanf("%s", code);
    } while (!isValidCode(code));
}
