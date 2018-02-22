#include <stdio.h>
#include "bigint.h"


int main(int argc, char **argv) {
    BigInteger *bigint1 = BigInteger_from_int(245);
    BigInteger *bigint2 = BigInteger_from_int(567);
    printf("%d\n", BigInteger_gt(bigint2, bigint1));
    BigInteger_destroy(bigint1);
    BigInteger_destroy(bigint2);
}
