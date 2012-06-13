#include <cstdio>
#include <cmath>

using namespace std;

struct coord {
    double x;
    double y;
};

coord modEuler(double (*x_prime)(double, double),
             double (*y_prime)(double, double),
             double initial_x0,
             double initial_y0,
             double partition
             );
double f(double x, double y);
double g(double x, double y);

int main(){
    coord p;
    p = modEuler(f, g, 2.0, 2.0, (0.25));
    return 0;
}

coord modEuler(double (*x_prime)(double, double),
                double (*y_prime)(double, double),
                double x_0, double y_0, double n){
    coord p;
    p.y = y_0;
    p.x = x_0;
    double delta_x = x_prime(p.x, p.y) * n;
    double delta_y = y_prime(p.x, p.y) * n;
    while(p.x>0.0000000000000001){
        printf("(%.16f,%.16f)\n",p.x, p.y);
        p.y += delta_y;
        p.x += delta_x;
        delta_x = x_prime(p.x, p.y) * n;
        delta_y = y_prime(p.x, p.y) * n;
    }
    return p;
}

double f(double x, double y){
    return (-x/2);
}

double g(double x, double y){
    return (-y/2);
}
