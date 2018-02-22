#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "bigint.h"


#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))


BigInteger *BigInteger_create() {
    unsigned int length = 32;
    unsigned int *inner = (unsigned int *) malloc(length);
    memset(inner, 0, length);

    BigInteger *big_integer = (BigInteger *) malloc(sizeof(BigInteger));
    big_integer->length = length;
    big_integer->inner = inner;

    return big_integer;
}

void BigInteger_destroy(BigInteger *big_integer) {
    free(big_integer->inner);
    free(big_integer);
}

int BigInteger_iszero(BigInteger *big_integer) {
    for (unsigned int i = 0; i < big_integer->length; i++) {
        if (big_integer->inner[i] != 0) {
            return 0;
        }
    }

    return 1;
}

BigInteger *BigInteger_from_int(unsigned int val) {
    BigInteger * new_integer = BigInteger_create();
    new_integer->inner[0] = val;

    return new_integer;
}

int BigInteger_eq(BigInteger *big_integer1, BigInteger *big_integer2) {
    unsigned int length1 = big_integer1->length;
    unsigned int length2 = big_integer2->length;
    unsigned int length_smaller_int = MIN(big_integer1->length, big_integer2->length);
    
    for (unsigned int i = 0; i < length_smaller_int; i++) {
        if (big_integer1->inner[i] != big_integer2->inner[i]) {
            return 0;
        }
    }

    if (length1 > length2) {
        for (unsigned int i = length2; i < length1; i++) {
            if (big_integer1->inner[i] != 0) {
                return 0;
            }
        }
    } 

    if (length2 > length1) {
        for (unsigned int i = length1; i < length2; i++) {
            if (big_integer2->inner[i] != 0) { 
                return 0;
            }
        }
    }

    return 1;
}

int BigInteger_neq(BigInteger *big_integer1, BigInteger *big_integer2) {
    return !BigInteger_eq(big_integer1, big_integer2);
}

int BigInteger_gt(BigInteger *big_integer1, BigInteger *big_integer2) {
    unsigned int length1 = big_integer1->length;
    unsigned int length2 = big_integer2->length;
    unsigned int length_smaller_int = MIN(big_integer1->length, big_integer2->length);
    
    for (unsigned int i = 0; i < length_smaller_int; i++) {
        if (big_integer1->inner[i] > big_integer2->inner[i]) {
            return 1;
        }

        if (big_integer1->inner[i] < big_integer2->inner[i]) {
            return 0;
        }
    }

    if (length1 > length2) {
        for (unsigned int i = length2; i < length1; i++) {
            if (big_integer1->inner[i] != 0) {
                return 1;
            }
        }
    } 

    if (length2 > length1) {
        for (unsigned int i = length1; i < length2; i++) {
            if (big_integer2->inner[i] != 0) { 
                return 0;
            }
        }
    }

    return 0;
}

int BigInteger_lt(BigInteger *big_integer1, BigInteger *big_integer2) {
    unsigned int length1 = big_integer1->length;
    unsigned int length2 = big_integer2->length;
    unsigned int length_smaller_int = MIN(big_integer1->length, big_integer2->length);
    
    for (unsigned int i = 0; i < length_smaller_int; i++) {
        if (big_integer1->inner[i] < big_integer2->inner[i]) {
            return 1;
        }

        if (big_integer1->inner[i] > big_integer2->inner[i]) {
            return 0;
        }
    }

    if (length1 > length2) {
        for (unsigned int i = length2; i < length1; i++) {
            if (big_integer1->inner[i] != 0) {
                return 0;
            }
        }
    } 

    if (length2 > length1) {
        for (unsigned int i = length1; i < length2; i++) {
            if (big_integer2->inner[i] != 0) { 
                return 1;
            }
        }
    }

    return 0;
}

int BigInteger_gt_eq(BigInteger *big_integer1, BigInteger *big_integer2) {
    return BigInteger_gt(big_integer1, big_integer2) 
        || BigInteger_eq(big_integer1, big_integer2);
}

int BigInteger_lt_eq(BigInteger *big_integer1, BigInteger *big_integer2) {
    return BigInteger_lt(big_integer1, big_integer2) 
        || BigInteger_eq(big_integer1, big_integer2);
}
