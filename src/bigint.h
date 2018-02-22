struct BigInteger {
    unsigned int length;
    char *inner;
};

typedef struct BigInteger BigInteger;

BigInteger *BigInteger_create();

void BigInteger_destroy(BigInteger *big_integer);

int BigInteger_iszero(BigInteger *big_integer);

int BigInteger_eq(BigInteger *big_integer1, BigInteger *big_integer2);

int BigInteger_neq(BigInteger *big_integer1, BigInteger *big_integer2);