//01101000 01100101 01101100


#include <stdio.h>

#include "header.h"

void swapCharDoer(int places[]) {
    //HERE
}

void swapCharactersInsideSentence() {
    fseek(file, 0, SEEK_SET);
    srand((unsigned int)time(NULL));

    for (size_t i = 0; i < keySize; i++) {
        unsigned int size = (unsigned char)key[i];
        if (size == 0) continue;

        int *changePlace = malloc(sizeof(int) * size);
        if (changePlace == NULL) return;

        for (unsigned int b = 0; b < size; b++) changePlace[b] = 1 + rand() % size;

        swapCharDoer(changePlace);
        free(changePlace);
    }
}

void encryptionLogicStart() {
    swapCharactersInsideSentence();
}
