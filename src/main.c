#include <stdio.h>
#include "bigint.h"
#include "parser.h"


int main(int argc, char **argv) {
    BigInteger *bigint1 = BigInteger_from_int(245);

    BigInteger_shl(bigint1, 4);
    printf("Done Shifting.\n");
    printf("%d\n", bigint1->inner[0]);

    return 0;
}
