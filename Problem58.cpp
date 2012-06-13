#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;

bool isPrime(int);

int main(){
    long unsigned int primes, nums, sideLen, lastNum;
    for(sideLen = 5, primes = 3, nums = 5, lastNum = 9; (primes*10) > (nums); sideLen+=2){
        for(int diag = 1; diag < 4; diag++){
            if(isPrime(lastNum + (sideLen - 1)*diag)){primes++;}
        }
        lastNum += (sideLen - 1) * 4;
        nums += 4;
    }
    printf("%d,  %d,  %d\n",primes, nums, sideLen-2);
    return 0;
}

bool isPrime(int n){
    bool prime = true;
    int sqrtN;
    sqrtN = floor(sqrt(n));
    if(n % 2 == 0 && n != 2){prime = false;}
    for(int i = 3; i<=sqrtN && prime; i += 2){
        if(n%i==0){prime = false;}
    }
    return prime;
}
