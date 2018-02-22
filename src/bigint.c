#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "bigint.h"


BigInteger *BigInteger_create() {
    unsigned int length = 32;
    char *inner = (char *) malloc(length);
    //memset(inner, 0, length);
    for (unsigned int i = 0; i < length; i++) {
        inner[i] = 0;
    }

    BigInteger *big_integer = (BigInteger *) malloc(sizeof(int) + sizeof(char *));
    big_integer->length = length;
    big_integer->inner = inner;

    return big_integer;
}

void BigInteger_destroy(BigInteger *big_integer) {
    free(big_integer->inner);
    free(big_integer);
}
