struct BigInteger {
    unsigned int length;
    unsigned int *inner;
};

typedef struct BigInteger BigInteger;

BigInteger *BigInteger_create();

BigInteger *__BigInteger_create(unsigned int length);

void __BigInteger_expand(BigInteger *big_integer);

void BigInteger_destroy(BigInteger *big_integer);

BigInteger *BigInteger_from_int(unsigned int val);

int BigInteger_iszero(BigInteger *big_integer);

int BigInteger_eq(BigInteger *big_integer1, BigInteger *big_integer2);

int BigInteger_neq(BigInteger *big_integer1, BigInteger *big_integer2);

int BigInteger_gt(BigInteger *big_integer1, BigInteger *big_integer2);

int BigInteger_lt(BigInteger *big_integer1, BigInteger *big_integer2);

int BigInteger_gt_eq(BigInteger *big_integer1, BigInteger *big_integer2);

int BigInteger_lt_eq(BigInteger *big_integer1, BigInteger *big_integer2);

void BigInteger_shl(BigInteger *big_integer, unsigned int shift_amount);

void BigInteger_shr(BigInteger *big_integer, unsigned int shift_amount);