#include <stdio.h>
#include <stdlib.h>

int * rpermute(int n);

int main()
{
    int * permutelist;
    int n, swap, sum;
    int max = 0;



	int matrix[15][15] = {{  7, 53,183,439,863,497,383,563, 79,973,287, 63,343,169,583},
                          {627,343,773,959,943,767,473,103,699,303,957,703,583,639,913},
                          {447,283,463, 29, 23,487,463,993,119,883,327,493,423,159,743},
                          {217,623,  3,399,853,407,103,983, 89,463,290,516,212,462,350},
                          {960,376,682,962,300,780,486,502,912,800,250,346,172,812,350},
                          {870,456,192,162,593,473,915, 45,989,873,823,965,425,329,803},
                          {973,965,905,919,133,673,665,235,509,613,673,815,165,992,326},
                          {322,148,972,962,286,255,941,541,265,323,925,281,601, 95,973},
                          {445,721, 11,525,473, 65,511,164,138,672, 18,428,154,448,848},
                          {414,456,310,312,798,104,566,520,302,248,694,976,430,392,198},
                          {184,829,373,181,631,101,969,613,840,740,778,458,284,760,390},
                          {821,461,843,513, 17,901,711,993,293,157,274, 94,192,156,574},
                          { 34,124,  4,878,450,476,712,914,838,669,875,299,823,329,699},
                          {815,559,813,459,522,788,168,586,966,232,308,833,251,631,107},
                          {813,883,451,509,615, 77,281,613,459,205,380,274,302, 35,805}};


	for(int j = 0; j < 1000; j++){
        permutelist = rpermute(15);
        for(int i = 0; i < 15; i++){
            n = i+1;
            while(n<15){
                if(matrix[i][permutelist[i]] + matrix[n][permutelist[n]] < matrix[i][permutelist[n]] + matrix[n][permutelist[i]]){
                    swap = permutelist[i];
                    permutelist[i] = permutelist[n];
                    permutelist[n] = swap;
                    n = i+1;
                } else {
                    n++;
                }
            }
            sum = 0;
        }
        sum = 0;
        for(int n = 0; n < 15; n++){
            sum += matrix[n][permutelist[n]];
            printf("%d ", permutelist[n]);
        }
        printf("\t%d\n",sum);
        if(sum > max){
            max = sum;
        }
        free(permutelist);
	}

	printf("\t\tmaximum: %d\n\n", max);
    return 0;
}

// It returns a random permutation of 0..n-1
int * rpermute(int n) {
    int *a = (int *) malloc(n*sizeof(int));
    int k;
    for (k = 0; k < n; k++)
	a[k] = k;
    for (k = n-1; k > 0; k--) {
	int j = rand() % (k+1);
	int temp = a[j];
	a[j] = a[k];
	a[k] = temp;
    }
    return a;
}
