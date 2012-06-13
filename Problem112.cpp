#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

bool isBouncy(unsigned long int);

int main(){
    cout << isBouncy(538) << "    " << isBouncy(21780) << endl;
    system("pause");
    int total = 0;
    float percent = 0;
    for(unsigned long int n = 1; n < 1000000000; n++){
        if(isBouncy(n)){
            total++;
            percent = float(total) / n;
            cout << n << " is bouncy:: " << total << "/" << n << " = " << percent << endl;
            if(percent == .990000){
                system("pause");
            }
        }
    }
    cout << total;
    return 0;
}

bool isBouncy(unsigned long int n){
    bool bouncy = false, inc, allsame = true, same;
    unsigned long int tempN = n;
    int temp = tempN % 10;
    tempN /= 10;
    if(tempN % 10 > temp){
        inc = true;
    }else if(tempN % 10 < temp){
        inc = false;
    }else{
        same = true;
    }
    do{
        if(tempN % 10 > temp){
            allsame = false;
            if(inc || same){
                temp = tempN % 10;
                tempN /= 10;
                same = false;
            }else{
                bouncy = true;
            }
        }else if(tempN % 10 < temp){
            allsame = false;
            if(!inc || same){
                temp = tempN % 10;
                tempN /= 10;
                same = false;
            }else{
                bouncy = true;
            }
        }else{
            temp = tempN % 10;
            tempN /= 10;
        }
    }while(tempN > 0 && !bouncy);
    if(allsame){
        bouncy = false;
    }
    return bouncy;
}
