#include <cstdio>

#define UPPER_BOUND 99999

int naive_solution();
int summation_solution();

int main()
{
    printf("%d\n",summation_solution());

    return 0;
}

int naive_solution()
{
        int sum = 0;
    for(int i = 0; i <= UPPER_BOUND; i++)
        if(i % 3 == 0 || i % 5 == 0)
            sum += i;

    return sum;
}

int summation_solution()
{
    return UPPER_BOUND * (UPPER_BOUND / 3 - 1) / 2 +
           UPPER_BOUND * (UPPER_BOUND / 5 - 1) / 2 -
           UPPER_BOUND * (UPPER_BOUND / 15 - 1) / 2;
}
