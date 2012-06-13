#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(){
    long int a, b, c, p = 0;
    for(int m = 1; m < 18257; m++){
        for(int n = 1; n < 18257 && m > n; n++){
            a = m * m - n * n;
            b = 2 * m * n;
            c = m * m + n * n;
            if(c == 2 * a + 1 || c == 2 * a - 1){
                cout << c << "-" << c << "-" << 2 * a << " (area = "
                     << a * b << ", perimeter = " << 2 * a + 2 * c << ")\n";
                p += 2 * a + 2 * c;
            }else if(c == 2 * b + 1 || c == 2 * b - 1){
                cout << c << "-" << c << "-" << 2 * b << " (area = "
                     << a * b << ", perimeter = " << 2 * b + 2 * c << ")\n";
                p += 2 * b + 2 * c;
            }
        }
    }
    cout << "total perimeter is " << p << endl;

    return 0;
}
