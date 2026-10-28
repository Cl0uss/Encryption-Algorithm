#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
extern FILE* file;

extern void encryption(char*input);
extern void keyGeneration();
extern void encryptionLogicStart();
extern unsigned char* key;
extern size_t keySize;
