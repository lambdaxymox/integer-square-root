#include <stdio.h>
#include "bigint.h"


int main(int argc, char **argv) {
    BigInteger *zero = BigInteger_create();
    BigInteger_destroy(zero);
}
