#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main(){
    int peterRolls[36], colinRolls[36];
    float peterProb[36], colinProb[36];
    float peterWinProb = 0;
    for(int i = 0; i < 36; i++){
        peterRolls[i] = 0;
        peterProb[i] = 0;
        colinRolls[i] = 0;
        colinProb[i] = 0;
    }

    for(int p1 = 1; p1 < 5; p1++){
     for(int p2 = 1; p2 < 5; p2++){
      for(int p3 = 1; p3 < 5; p3++){
       for(int p4 = 1; p4 < 5; p4++){
        for(int p5 = 1; p5 < 5; p5++){
         for(int p6 = 1; p6 < 5; p6++){
          for(int p7 = 1; p7 < 5; p7++){
           for(int p8 = 1; p8 < 5; p8++){
            for(int p9 = 1; p9 < 5; p9++){
             peterRolls[p1 + p2 + p3 + p4 + p5 + p6 + p7 + p8 + p9 - 1]++;
            }
           }
          }
         }
        }
       }
      }
     }
    }

    for(int c1 = 1; c1 < 7; c1++){
     for(int c2 = 1; c2 < 7; c2++){
      for(int c3 = 1; c3 < 7; c3++){
       for(int c4 = 1; c4 < 7; c4++){
        for(int c5 = 1; c5 < 7; c5++){
         for(int c6 = 1; c6 < 7; c6++){
          colinRolls[c1 + c2 + c3 + c4 + c5 + c6 - 1]++;
         }
        }
       }
      }
     }
    }

    for(int i = 0; i < 36; i++){
        peterProb[i] = (float) peterRolls[i] / 262144;
        colinProb[i] = (float) colinRolls[i] / 46656;
        printf("%d: colin: %.7f peter: %.7f\n", i + 1, colinProb[i], peterProb[i]);
    }

    for(int i = 0; i < 36; i++){
        for(int j = 0; j < i; j++){
            peterWinProb += peterProb[i] * colinProb[j];
        }
    }

    printf("\n\nProbability: %.8f\n", peterWinProb);

    return 0;
}
