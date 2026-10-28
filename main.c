#include "header.h"

int main(int argc, char *argv[]) {
    srand((unsigned int)time(NULL));
    if (strcmp(argv[1], "-e") == 0) encryption(argv[2]);
    //else if (strcmp(argv[1], "-d") == 0) decryption(argv[2],argv[3]);
    free(key);
    key = NULL;
    keySize = 0;
    return 0;
}
