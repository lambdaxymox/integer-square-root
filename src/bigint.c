#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "bigint.h"


#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))


BigInteger *BigInteger_create() {
    return __BigInteger_create(32);
}

BigInteger *__BigInteger_create(unsigned int length) {
    unsigned int *inner = (unsigned int *) malloc(length * sizeof(unsigned int));
    memset(inner, 0, length);

    BigInteger *big_integer = (BigInteger *) malloc(sizeof(BigInteger));
    big_integer->length = length;
    big_integer->inner = inner;

    return big_integer;
}

void __BigInteger_expand(BigInteger *big_integer) {
    BigInteger *new_big_integer = __BigInteger_create(2 * big_integer->length);
    void * destination = (void *) new_big_integer->inner;
    void * source = (void *) big_integer->inner;
    unsigned int num = big_integer->length;
    memcpy(destination, source, num);
    BigInteger_destroy(big_integer);
    big_integer = new_big_integer;
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

void BigInteger_shl(BigInteger *big_integer, unsigned int shift_amount) {
    for (unsigned int shift = 0; shift < shift_amount; shift++) {
        unsigned int rem = 0;
        printf("Shifting.\n");
        for (unsigned int i = 0; i < big_integer->length; i++) {
            unsigned int int_i = big_integer->inner[i];
            big_integer->inner[i] = (int_i << 1) | rem;
            rem = (int_i & (1 << (sizeof(unsigned int)-1))) >> (sizeof(unsigned int)-1);
        }

        // We have an overflow from doing the bit shift.
        if (rem != 0) {
            __BigInteger_expand(big_integer);
        }
    }
}

void BigInteger_shr(BigInteger *big_integer, unsigned int shift_amount) {
    for (unsigned int shift = 0; shift < shift_amount; shift++) {
        unsigned int rem = 0;
        for (unsigned int i = big_integer->length; i > 0; i--) {
            unsigned int int_i = big_integer->inner[i-1];
            big_integer->inner[i-1] = (int_i >> 1) | rem;
            rem = (int_i & 1) << (sizeof(unsigned int)-1);
        }
    }
}

