#include <cstdio>
#include <cstdlib>

using namespace std;

int squareLoop(int);
int squareDigits(int);

int main(){
    int hashTable[567];
    int n89 = 0;
    for(int n = 0; n < 567; n++){
        hashTable[n] = squareLoop(n + 1);
    }
    for(int n = 1; n < 10000000; n++){
        if(hashTable[squareDigits(n)-1]==89){n89++;}
    }
    printf("%d",n89);
}

int squareLoop(int n){

    do{
        n = squareDigits(n);
    }while(n != 1 && n != 89);
    return n;
}

int squareDigits(int n){
    int sum = 0;
    do{
        sum += (n%10)*(n%10);
        n /= 10;
    }while(n>0);
    return sum;
}
