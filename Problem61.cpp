#include <iostream>
#include <cstdlib>

using namespace std;

int triangle(int);
int square(int);
int pentagon(int);
int hexagon(int);
int heptagon(int);
int octagon(int);

int main(){
    int tri[96], squ[68], pent[56], hex[48], hept[43], oct[40];
    int size[6] = {68, 56, 48, 43, 40};
    int * figurate[6] = {squ, pent, hex, hept, oct};

    for(int i = 0; i < 96; i++){
        tri[i] = triangle(i + 45);
    }
    for(int i = 0; i < 68; i++){
        squ[i] = square(i + 32);
    }
    for(int i = 0; i < 56; i++){
        pent[i] = pentagon(i + 26);
    }
    for(int i = 0; i < 48; i++){
        hex[i] = hexagon(i + 23);
    }
    for(int i = 0; i < 43; i++){
        hept[i] = heptagon(i + 21);
    }
    for(int i = 0; i < 40; i++){
        oct[i] = octagon(i + 19);
    }

    for(int i = 0; i < 96; i++){
        for(int a = 0; a < 5; a++){
            for(int a1 = 0; a1 < size[a]; a1++){
                if(figurate[a][a1] / 100 == tri[i] % 100){
                    for(int b = 0; b < 5; b++){
                        if(b != a){
                            for(int b1 = 0; b1 < size[b]; b1++){
                                if(figurate[b][b1] / 100 == figurate[a][a1] % 100){
                                    for(int c = 0; c < 5; c++){
                                        if( c != a && c != b){
                                            for(int c1 = 0; c1 < size[c]; c1++){
                                                if(figurate[c][c1] / 100 == figurate[b][b1] % 100){
                                                    for(int d = 0; d < 5; d++){
                                                        if(d != a && d != b && d != c){
                                                            for(int d1 = 0; d1 < size[d]; d1++){
                                                                if(figurate[d][d1] / 100 == figurate[c][c1] % 100){
                                                                    for(int e = 0; e < 5; e++){
                                                                        if(e != a && e != b && e != c && e != d){
                                                                            for(int e1 = 0; e1 < size[e]; e1++){
                                                                                if(figurate[e][e1] / 100 == figurate[d][d1] % 100 && tri[i] / 100 == figurate[e][e1] % 100){
                                                                                     cout << tri[i] << "    " << figurate[a][a1] << "    " << figurate[b][b1] << "    " << figurate[c][c1] << "    " << figurate[d][d1] << "    " << figurate[e][e1] << endl;
                                                                                     cout << tri[i] + figurate[a][a1] + figurate[b][b1] + figurate[c][c1] + figurate[d][d1] + figurate[e][e1] << endl;
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int triangle(int n){
    return n * (n + 1) / 2;
}

int square(int n){
    return n * n;
}

int pentagon(int n){
    return n * (3 * n - 1) / 2;
}

int hexagon(int n){
    return n * (2 * n - 1);
}

int heptagon(int n){
    return n * (5 * n - 3) / 2;
}

int octagon(int n){
    return n * (3 * n - 2);
}
