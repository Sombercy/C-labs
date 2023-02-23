#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <stdbool.h>

float find_x(int32_t n, int32_t m){
    float sum1 = 0, sum2 = 0;
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            sum2 += 1 / (i + j) + i * j;
            printf("i = %d, j = %d: sum1 = %f, sum2 = %f\n", i, j, sum1, sum2);
        }
        sum1 += sum2;
        sum2 = 0;
    }
    return sum1;
}
int main()
{
    int32_t n, m;
    printf("Put values of n, m variables:\n");
    scanf("%i%i", &n, &m);
    printf("n = %d\nm = %d\n", n, m);
    printf("x = %f", find_x(n, m));
    return 0;
}