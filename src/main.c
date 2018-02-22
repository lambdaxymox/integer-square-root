#include <stdio.h>
#include "bigint.h"


int main(int argc, char **argv) {
    BigInteger *zero1 = BigInteger_create();
    BigInteger *zero2 = BigInteger_create();
    printf("%d\n", !BigInteger_eq(zero1, zero2));
    BigInteger_destroy(zero1);
    BigInteger_destroy(zero2);
}
