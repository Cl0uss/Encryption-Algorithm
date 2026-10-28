#include "../header.h"


FILE* file;

void output() {
    int character;
    while ((character = fgetc(file)) != EOF) printf("%c",character);
    printf("\n");
}


void lineOrganizer() {

}

void encryption(char* input) {

    char *path = malloc(strlen(input)+4);
    if (path == NULL) {printf("\nALLOC FAILED\n"); return;}
    snprintf(path, strlen(input)+4, "../%s", input);

    file = fopen(path, "r");
    if (file == NULL) {printf("\nNO FILE\n"); return;}

    output();
    fclose(file);
    free(path);
}