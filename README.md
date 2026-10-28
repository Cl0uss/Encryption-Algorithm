# Encryption Algorithm

A file encryption project written in C, featuring custom key generation, binary file processing, and dynamic memory management.

## Overview

The program accepts a file through command-line arguments and generates a variable-length key based on its contents and size.

The key is constructed by reading bytes from randomly selected positions in the original file and converting their values into a numerical sequence.

The generated key is stored in a binary file named `key.bin`.

## Key Generation

The key generation algorithm begins by determining the original file size using `fseek()` and `ftell()`.

A temporary array is allocated using `malloc()`, and the variable `leftBytes` is initialized to the file size minus one.

The program selects random positions within the original file, excluding the first byte, and reads their values using `fgetc()`.

Each value is processed using the following expression:

```c
long int maxValue = leftBytes < 255 ? leftBytes : 255;
randomCharacterFromFile = 1 + c % maxValue;
```

The resulting number is stored in `tempKey`, and `leftBytes` is decreased by that number.

```c
tempKey[usedBytes++] = (unsigned char)randomCharacterFromFile;
leftBytes -= randomCharacterFromFile;
```

The process continues until `leftBytes` reaches zero.

The sum of all generated key values is therefore equal to the original file size minus one.

For example, a file containing 200 bytes could produce:

```text
65 40 80 14
```

Where:

```text
65 + 40 + 80 + 14 = 199
```

The number of elements in the key depends on the values generated during execution.

## Memory Management

The program initially stores generated values in a dynamically allocated array:

```c
unsigned char *tempKey = malloc(amountOfBytesInOriginalFile);
```

After generation, a local array is created with enough space for the generated values:

```c
unsigned char key[usedBytes + 1];
```

The populated portion of `tempKey` is copied into `key`:

```c
memcpy(key, tempKey, usedBytes);
key[usedBytes] = '\0';
free(tempKey);
```

The final array is a variable-length array (VLA), while the temporary array uses dynamically allocated memory.

## Binary Key Storage

The generated key is written to:

```text
encryption/key.bin
```

The file is opened in binary write mode:

```c
FILE *keyFile = fopen("encryption/key.bin", "wb");
```

The generated values are stored using:

```c
fwrite(key, 1, keySize, keyFile);
```

Each element of the key occupies one byte.

For example:

```text
33 102 53 11
```

The binary file contains four bytes:

```text
00100001 01100110 00110101 00001011
```

The stored values can be examined using:

```bash
xxd encryption/key.bin
```

The file can also be read byte by byte using `fgetc()` or in blocks using `fread()`.

## Project Structure

```text
Encryption-Algorithm/
├── encryption/
│   ├── encryption.c
│   └── key.bin
├── decryption/
├── build/
├── main.c
├── header.h
├── CMakeLists.txt
├── run.sh
├── sample.txt
└── README.md
```

`key.bin` and the contents of `build/` are generated during execution and compilation.

## Building and Running

### Requirements

- GCC
- CMake
- Bash
- Linux

Make the execution script executable:

```bash
chmod +x run.sh
```

Run the program:

```bash
./run.sh sample.txt -e
```

The script configures and builds the project using CMake, then executes the program with the specified command-line arguments.

The program reads `sample.txt`, generates the key, and saves the result in `encryption/key.bin`.

## Implementation

The project uses the following C functions:

| Function | Purpose |
|----------|---------|
| `fopen()` | Opens input and output files |
| `fclose()` | Closes files |
| `fseek()` | Changes the current position within a file |
| `ftell()` | Retrieves the current file position |
| `fgetc()` | Reads individual bytes |
| `fwrite()` | Writes binary data |
| `rand()` | Generates pseudorandom values |
| `malloc()` | Allocates dynamic memory |
| `memcpy()` | Copies data between arrays |
| `free()` | Releases allocated memory |

## Current Implementation

The following components are implemented:

- Command-line argument processing
- Input file handling
- File size detection
- Random byte selection
- Variable-length key generation
- Dynamic memory allocation
- Binary key storage

File encryption and decryption functions are not yet implemented.