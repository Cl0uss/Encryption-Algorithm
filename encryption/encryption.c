#include "../header.h"

FILE* file = NULL;


void output() {
    int character;
    rewind(file);

    while ((character = fgetc(file)) != EOF) {
        printf("%c", character);
    }

    printf("\n");
    rewind(file);
}


void encryption(char* input) {
    file = fopen(input, "rb");

    if (file == NULL) {
        perror("CANNOT OPEN FILE");
        return;
    }

    keyGeneration();
    if (key != NULL) {
        encryptionLogicStart();
    }
    fclose(file);
    file = NULL;
}
