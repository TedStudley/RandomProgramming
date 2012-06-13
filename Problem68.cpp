#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){
    for(int a = 1; a < 11; a++){
     for(int b = 1; b < 10; b++){
      if(b != a){
       for(int c = 1; c < 11; c++){
        if(c != a && c != b){
         for(int d = 1; d < 10; d++){
          if(d != 1 && d != b && d != c){
           for(int e = 1; e < 11; e++){
            if(e != a && e != b && e != c && e != d){
             for(int f = 1; f < 10; f++){
              if(f != a && f != b && f != c && f != d && f != e){
               for(int g = 1; g < 11; g++){
                if(g != a && g != b && g != c && g != d && g != e && g != f){
                 for(int h = 1; h < 10; h++){
                  if(h != a && h != b && h != c && h != d && h != e && h != f && h != g){
                   for(int i = 1; i < 11; i++){
                    if(i != a && i != b && i != c && i != d && i != e && i != f && i != g && i != h){
                     for(int j = 1; j < 10; j++){
                      if(j != a && j != b && j != c && j != d && j != e && j != f && j != g && j != h && j != i){
                       if(a + j == c + d && c + b == e + f && e + d == g + h && g + f == i + j && a + c + e + g + i == 40){
                        printf("%d %d %d\n%d %d %d\n%d %d %d\n%d %d %d\n%d %d %d\n\n",a,j,b,c,b,d,e,d,f,g,f,h,i,h,j);
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

}
