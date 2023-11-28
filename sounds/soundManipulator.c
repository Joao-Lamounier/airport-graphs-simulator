#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <wait.h>
#include "soundManipulator.h"

void playSound(const char *soundFile) {
    char command[100];
    snprintf(command, sizeof(command), "aplay -f cd %s > /dev/null 2>&1 &", soundFile);
    system(command);
}

void initialSound() {
    playSound("sounds/audioInicial.wav");
}

void finalSound() {
    playSound("sounds/audioFinal.wav");
}
