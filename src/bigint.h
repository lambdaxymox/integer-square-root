struct BigInteger {
    unsigned int length;
    char *inner;
};

typedef struct BigInteger BigInteger;

BigInteger *BigInteger_create();

void BigInteger_destroy(BigInteger *big_integer);
