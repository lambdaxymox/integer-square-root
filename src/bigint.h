struct BigInteger {
    unsigned int length;
    char *inner;
};

typedef struct BigInteger BigInteger;

BigInteger *BigInteger_create();

void BigInteger_destroy(BigInteger *big_integer);

BigInteger *BigInteger_from_long(unsigned long val);

BigInteger *BigInteger_from_int(unsigned int val);

int BigInteger_iszero(BigInteger *big_integer);

int BigInteger_eq(BigInteger *big_integer1, BigInteger *big_integer2);

int BigInteger_neq(BigInteger *big_integer1, BigInteger *big_integer2);

int BigInteger_gt(BigInteger *big_integer1, BigInteger *big_integer2);

int BigInteger_lt(BigInteger *big_integer1, BigInteger *big_integer2);

int BigInteger_gt_eq(BigInteger *big_integer1, BigInteger *big_integer2);

int BigInteger_lt_eq(BigInteger *big_integer1, BigInteger *big_integer2);