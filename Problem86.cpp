#include <cstdio>
#include <cstdlib>
#include <cmath>

#define SOLUTION_GOAL 1000000

using namespace std;

bool squareQ(int);
int min(int, int, int);

int main(){
    int x, y, z;
    int solutions = 0;
    for(x = 1; solutions <= SOLUTION_GOAL; x++){
        for(y = 1; y <= x; y++){
            for(z = 1; z <= y; z++){
                if(squareQ(min((x + y) * (x + y) + z * z, (y + z) * (y + z) + x * x, (x + z) * (x + z) + y * y))){
                    solutions++;
                }
            }
        }
    }

    printf("\tM = %d with %d solutions.\n\n", --x, solutions);

    return 0;
}

bool squareQ(int n){
    int x = sqrt(n);
    return x * x == n;
}

int min(int n1, int n2, int n3){
    int temp;
    if(n1 <= n2){
        if(n1 <= n3){
            temp = n1;
        }else{
            temp = n3;
        }
    }else{
        if(n2 <= n3){
            temp = n2;
        }else{
            temp = n3;
        }
    }
    return temp;
}
