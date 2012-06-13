#include <cstdio>
#include <cstdlib>

using namespace std;

bool elem(int*, int, int);
int factorialSum(int);
int factorial(int);

int main(){
    int chain[60];
    int hits = 0;
    bool repeated;
    for(int i = 1; i < 1000000; i++){
        chain[0] = i;
        repeated = false;
        for(int n = 1; n < 60 && !repeated; n++){
            chain[n] = factorialSum(chain[n-1]);
            repeated = elem(chain,chain[n],n);
        }
        if(!repeated){hits++;}
    }
    printf("%d",hits);
    return 0;
}

bool elem(int* array, int check, int n){
    bool hit = false;
    for(int i = 0; i < n; i++){
        if(array[i]==check){hit = true;}
    }
    return hit;
}

int factorialSum(int n){
    int sum = 0;
    do{
        sum += factorial(n%10);
        n /= 10;
    }while(n>0);
    return sum;
}

int factorial(int n){
    int m = 1;
    for(int i = 1;i <= n;i++){
        m *= i;
    }
    return m;
}
