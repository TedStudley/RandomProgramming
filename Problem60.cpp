#include <cstdlib>
#include <cstdio>

#define UPPER_SIEVE 100000
#define UPPER_PRIME 10000

#define twoconcat(a,b) is_prime(concat_int(a,b)) && is_prime(concat_int(b,a))
#define threeconcat(a,b,c) twoconcat(a,b) && twoconcat(b,c) && twoconcat(a,c)
#define fourconcat(a,b,c,d) threeconcat(a,b,c) && threeconcat(b,c,d) && twoconcat(a,d)
#define fiveconcat(a,b,c,d,e) fourconcat(a,b,c,d) && fourconcat(b,c,d,e) && twoconcat(a,e)

typedef unsigned char u_char;

bool * prime_sieve();
bool is_prime(int test_num);

int concat_int(int a, int b);

bool * prime_array = prime_sieve();

int main()
{
    for(int a = 2; a < UPPER_PRIME; a++)
        if(prime_array[a])
            for(int b = 2; b < a; b++)
                if(prime_array[b] && twoconcat(a,b))
                    for(int c = 2; c < b; c++)
                        if(prime_array[c] && threeconcat(a,b,c))
                            for(int d = 2; d < c; d++)
                                if(prime_array[d] && fourconcat(a,b,c,d))
                                    for(int e = 2; e < d; e++)
                                        if(prime_array[e] && fiveconcat(a,b,c,d,e))
                                        {
                                            printf("%d\t%d\t%d\t%d\t%d:\t%d\n",a,b,c,d,e,a+b+c+d+e );
                                            return 0;
                                        }
    return 0;
}

bool * prime_sieve()
{
    bool * temp_array = (bool *) malloc(UPPER_SIEVE);
    temp_array[0] = false;
    temp_array[1] = false;
    for(int i = 2; i < UPPER_SIEVE; i++)
    {
        temp_array[i] = true;
    }
    for(int i = 2; i < UPPER_SIEVE; i++)
        if(temp_array[i])
            for(int j = 2*i; j < UPPER_SIEVE; j+=i)
                temp_array[j] = false;
    return temp_array;
}

bool is_prime(int test_num)
{
    bool primeQ = (test_num % 2 != 0);
    for(int i = 3; primeQ && i * i <= test_num; i+=2)
        if(prime_array[i])
            primeQ = (test_num % i != 0);
    return primeQ;
}

int concat_int(int a, int b)
{
    int c = 10;
    while(c<b)
        c*=10;
    c = c * a + b;
    return c;
}
