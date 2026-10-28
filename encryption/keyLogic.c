#include "../header.h"

unsigned char* key = NULL;
size_t keySize = 0;

void writeKeyInFile(const unsigned char key[], size_t keySize) {
    FILE* keyFile = fopen("encryption/key.bin", "wb");

    if (keyFile == NULL) {
        perror("CANNOT CREATE KEY FILE");
        return;
    }

    if (fwrite(key, 1, keySize, keyFile) != keySize) {
        printf("\nERROR WRITING KEY\n");
    }

    if (fclose(keyFile) != 0) {
        printf("\nERROR CLOSING KEY FILE\n");
    }
}

void keyGeneration() {
    free(key);
    key = NULL;
    keySize = 0;

    if (fseek(file, 0, SEEK_END) != 0) {
        printf("\nFSEEK FAILED\n");
        return;
    }

    long int amountOfBytesInOriginalFile = ftell(file);

    if (amountOfBytesInOriginalFile < 2) {
        printf("\nFILE IS TOO SMALL OR SIZE DETECTION FAILED\n");
        return;
    }

    rewind(file);
    unsigned char* tempKey = malloc((size_t)amountOfBytesInOriginalFile);

    if (tempKey == NULL) {
        printf("\nTEMPKEY MALLOC FAILED\n");
        return;
    }

    long int leftBytes = amountOfBytesInOriginalFile - 1;
    long int usedBytes = 0;
    long int randomPlaceFromFile;
    int randomCharacterFromFile;

    while (leftBytes > 0) {
        randomPlaceFromFile = 1 + rand() % (amountOfBytesInOriginalFile - 1);

        if (fseek(file, randomPlaceFromFile, SEEK_SET) != 0) {
            printf("\nFSEEK FAILED\n");
            free(tempKey);
            return;
        }

        int c = fgetc(file);

        if (c == EOF) {
            printf("\nFILE READ ERROR\n");
            free(tempKey);
            return;
        }

        randomCharacterFromFile = 1 + c % (leftBytes < 255 ? leftBytes : 255);
        tempKey[usedBytes++] = (unsigned char)randomCharacterFromFile;
        leftBytes -= randomCharacterFromFile;
    }

    key = tempKey;
    keySize = (size_t)usedBytes;
    printf("\nGenerated key (%zu bytes):\n", keySize);
    writeKeyInFile(key, keySize);
}
