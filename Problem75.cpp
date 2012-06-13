#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <bitset>

#define P 1500000 + 1
#define isOne 1
#define isMany 2

using namespace std;

struct triple
{
    int a;
    int b;
    int c;
};

void tripleLoop(triple, char *);

int main()
{
    char countArray[P] = {0};
    triple initial = {3, 4, 5};
    int count = 0;

    tripleLoop(initial, countArray);

    for(int i = 0; i < P; i++)
        if(countArray[i] == 1)
            count++;
    printf("%d", count);

    return 0;
}

void tripleLoop(triple t, char * countArray)
{
    int tempPerim = t.a + t.b + t.c;
    if(tempPerim < P)
    {
        tripleLoop((triple){t.a - 2 * t.b + 2 * t.c, 2 * t.a - t.b + 2 * t.c, 2 * t.a - 2 * t.b + 3 * t.c}, countArray);
        tripleLoop((triple){t.a + 2 * t.b + 2 * t.c, 2 * t.a + t.b + 2 * t.c, 2 * t.a + 2 * t.b + 3 * t.c}, countArray);
        tripleLoop((triple){-t.a + 2 * t.b + 2 * t.c, -2 * t.a + t.b + 2 * t.c, -2 * t.a + 2 * t.b + 3 * t.c}, countArray);
        for(int i = 1; i * tempPerim < P; i++)
        {
            if((countArray[tempPerim * i] & isOne))
                countArray[tempPerim * i] |= isMany;
            else
                countArray[tempPerim * i] |= isOne;
        }
    }


    return;
}
