#include <cstdio>
#include <cstdlib>

#define FIBONACCI_UPPER 4000000

int fibonacci_array(int n);

int main()
{
    int sum = 0, temp = 0, n = 0 ;
    do
    {
        sum += temp;
        n+=2;
        temp = fibonacci_array(n);
        printf("%d\n",temp);
    }
    while(temp < FIBONACCI_UPPER);

    printf("%d",sum);

    return 0;
}

int fibonacci_array(int n)
{
    int temp;
    int * array = (int *)malloc(sizeof(int)*(n+1));
    array[0] = 1;
    array[1] = 1;
    for(int i = 2; i <= n; i++)
        array[i] = array[i-1] + array[i-2];
    temp = array[n];
    delete(array);
    return temp;
}
