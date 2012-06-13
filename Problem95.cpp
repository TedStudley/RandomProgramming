#include <cstdio>
#include <cstdlib>

using namespace std;

typedef struct chainResult {
    int min;
    int len;
} chainResult;

chainResult chain(int);
int divisorSigma(int);

int main(){
    chainResult result;
    int min = 1000000, maxLen = 0;

    chain(6);
    system("pause");


    for(int i = 1; i < 1000000; i++){
        result = chain(i);
        if(result.len > maxLen){
            maxLen = result.len;
            min = result.min;
            printf("n: %d\tnewLen: %d\t newMin: %d\n", i, maxLen, min);
        }
    }

    return 0;
}

int divisorSigma(int n){
    int sum = 0;
    for(int i = 1; i < n; i++){
        if(n % i == 0){
            sum += i;
        }
    }
    return sum;
}

chainResult chain(int n){
    chainResult result;
    int i = 0, curr = n, min = n, tempcurr;

    do{
        // printf("%d\t",curr);
        curr = divisorSigma(curr);
        i++;
    }while(curr != n && curr != 0 && i < 100 && curr < 1000000);
    // printf("%d\t",curr);
    if(curr != n){
        // printf("Not looping\n");
        result.len = 0;
        result.min = 0;
    }else{
        // printf("Looping: length = %d, min = %d\n", i, min);
        result.len = i;
        result.min = min;
    }

    return result;
}

