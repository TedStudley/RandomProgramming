#include <cstdio>
#include <cstdlib>

#define UPPER_BOUND 1000000000
#define UPPER_PRIME 100

using namespace std;

void hammingRecurse(bool * hammingArray, unsigned long long number);

static int first50Primes[] = {2,   3,   5,   7,   11,
                              13,  17,  19,  23,  29,
                              31,  37,  41,  43,  47,
                              53,  59,  61,  67,  71,
                              73,  79,  83,  89,  97,
                              101, 103, 107, 109, 113,
                              127, 131, 137, 139, 149,
                              151, 157, 163, 167, 173,
                              179, 181, 191, 193, 197,
                              199, 211, 223, 227, 229};
int main(){
    bool * hammingArray = new bool[UPPER_BOUND + 1];
    int numHamming = 0;

    hammingArray[0] = false;
    hammingArray[1] = true;
    for(int i = 2; i <= UPPER_BOUND; i++){
        hammingArray[i] = false;
    }

    for(int i = 0; first50Primes[i] <= UPPER_PRIME; i++){
        hammingRecurse(hammingArray, first50Primes[i]);
    }

    for(int i = 1; i <= UPPER_BOUND; i++){
        numHamming += hammingArray[i];
    }

    printf("%d", numHamming);

    return 0;
}

void hammingRecurse(bool * hammingArray, unsigned long long number){
    if(number <= UPPER_BOUND && !hammingArray[number]){
        hammingArray[number] = true;
        for(int i = 0; first50Primes[i] <= UPPER_PRIME; i++){
            hammingRecurse(hammingArray, number * first50Primes[i]);
        }
    }
    return;
}
