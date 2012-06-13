#include <cstdio>
#include <cstdlib>

using namespace std;

bool oddDigitsQ(int);
int reverseNumber(int);

int main(){
    int hits = 0, temp;
    for(int n = 1; n <= 1000000000; n++){
        if(n % 10 != 0){
            temp = n + reverseNumber(n);
            if(oddDigitsQ(temp)){
                //printf("%d ", n);
                hits++;
            }
        }
    }
    printf("\n%d\n", hits);
    return 0;
}

bool oddDigitsQ(int n){
    bool allOdd = true;
    do{
        if(n % 10 % 2 == 0){
            allOdd = false;
        }
        n /= 10;
    }while(n > 0 && allOdd);
    return allOdd;
}

int reverseNumber(int n){
    int m = 0;
    for(int i = 0;n > 0;i++){
        m *= 10;
        m += n % 10;
        n /= 10;
    }
    return m;
}
