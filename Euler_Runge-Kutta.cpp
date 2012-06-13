#include <cstdio>
#include <cmath>

using namespace std;

struct butcher_tableau{
    int order;
    double ** tableau;
};


double RKF45(double (*y_prime)(double, double), double initial_y0, double lower_bound, double upper_bound, int partitions);
double RK4(double (*y_prime)(double, double), double initial_y0, double lower_bound, double upper_bound, int partitions);
double euler(double (*y_prime)(double, double), double initial_y0, double lower_bound, double upper_bound, int partitions);
double f(double x, double y);
double g(double x, double y);
void define_RK4(butcher_tableau * runge_kutta);

int main(){

    butcher_tableau runge_kutta;
    define_RK4(&runge_kutta);

    for(int i = 1; i < 65536; i*=2){
        printf("n = %d\n\
               \te \t= %.16f\n\
               \tEuler\t= %.16f\tError\t= %.16f\n\
               \tRK4  \t= %.16f\tError\t= %.16f\n\
               \tRKF45\t= %.16f\tError\t= %.16f\n\n"
               ,i
               ,M_E
               ,euler(f,1,0,1,i),euler(f,1,0,1,i) - M_E
               ,RK4(f,1,0,1,i), RK4(f,1,0,1,i) - M_E
               ,RKF45(f,1,0,1,i), RKF45(f,1,0,1,i) - M_E);
    }

    return 0;
}

void define_RK4(butcher_tableau * runge_kutta){
    runge_kutta->order = 4;
    return;
}

// butcher tableu:
//  0 |
//  -----
//    | 1
double euler(double (*y_prime)(double, double), double y_0, double a, double b, int n){
    double y = y_0;
    double x = a;
    double delta_x = (b-a)/n;
    for(int i = 0; i < n; i++){
        y+=delta_x * (*y_prime)(x,y);
        x+=delta_x;
    }
    return y;
}

// butcher tableu:
//  0   |
//  1/2 |   1/2
//  1/2 |   0   1/2
//  1   |   0   0   1
//  -----------------------
//      |   1/6 1/3 1/3 1/6
double RK4(double (*y_prime)(double,double), double y_0, double a, double b, int n){
    double k_1, k_2, k_3, k_4;
    double y = y_0;
    double x = a;
    double delta_x = (b-a)/n;
    for(int i = 0; i < n; i++){
        k_1 = delta_x * (*y_prime)(x,y);
        k_2 = delta_x * (*y_prime)(x + delta_x / 2, y + k_1 / 2);
        k_3 = delta_x * (*y_prime)(x + delta_x / 2, y + k_2 / 2);
        k_4 = delta_x * (*y_prime)(x + delta_x, y + k_3);
        y += (k_1 + 2 * k_2 + 2 * k_3 + k_4) / 6;
        x += delta_x;
    }
    return y;
}

// butcher tableu:
//	0
//	1/4     |   1/4
//	3/8     |   3/32 	    9/32
//	12/13   |   1932/2197   −7200/2197  7296/2197
//	1       |   439/216 	−8          3680/513 	−845/4104
//	1/2     |   -8/27 	    2           −3544/2565 	1859/4104 	    −11/40
//  ----------------------------------------------------------------------------
//          |   25/216      0           1408/2565 	2197/4104 	    −1/5 	0
//          |   16/135      0           6656/12825 	28561/56430 	−9/50 	2/55
double RKF45(double (*y_prime)(double,double), double y_0, double a, double b, int n){
    double k_1, k_2, k_3, k_4, k_5, k_6;
    double y = y_0;
    double x = a;
    double delta_x = (b-a)/n;
    for(int i = 0; i < n; i++){
        k_1 = delta_x * (*y_prime)(x,y);
        k_2 = delta_x * (*y_prime)(x + delta_x / 4, y + k_1 / 4);
        k_3 = delta_x * (*y_prime)(x + 3 * delta_x / 8, y + (3 * k_1 + 9 * k_2) / 32 );
        k_4 = delta_x * (*y_prime)(x + 12 * delta_x / 13, y + ((1932 * k_1) - (7200 * k_2) + (7296 * k_3)) / 2197);
        k_5 = delta_x * (*y_prime)(x + delta_x, y + (439 * k_1 / 216) - (8 * k_2) + (3680 * k_3 / 513) - (845 * k_4 / 4104));
        k_6 = delta_x * (*y_prime)(x + delta_x / 2, y - (8 * k_1 / 27) + (2 * k_2) - (3544 * k_3 / 2565) + (1859 * k_4 / 4104) - (11 * k_5 / 40));
        y += ((16 * k_1 / 135) + (6656 * k_3 / 12825) + (28561 * k_4 / 56430) - (9 * k_5 / 50) + (2 * k_6 / 55));
        x += delta_x;
    }
    return y;
}

double f(double x, double y){
    return y;
}
