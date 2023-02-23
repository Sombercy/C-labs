
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <stdbool.h>

bool check(int32_t a, int32_t b, int32_t c) {
    if (a < 0 && b < 0 && c < 0) {
        int32_t sum2, modmin;
        switch (a < b) {
            case false:
                if (b < c) {
                    sum2 = a + c;
                    modmin = abs(b);
                }
                else {
                    sum2 = a + b;
                    modmin = abs(c);
                }
                printf("All negative. \n modmin=%d \n sum2=%d\n", modmin, sum2);
                return (abs(sum2) > modmin && sum2 > -256);
            case true:
                if (a < c) {
                    sum2 = b + c;
                    modmin = abs(a);
                }
                else {
                    sum2 = a + b;
                    modmin = abs(c);
                }
                printf("All negative. \n modmin=%d \n sum2=%d\n", modmin, sum2);
                return (abs(sum2) > modmin && sum2 > -256);
        }    
    }
    else if (a > -1 && b > -1 && c > -1) {
        int32_t max_n, min_n;
        switch (a > b){
            case 0:
                if (b > c) max_n = b;
                min_n = (a > c) ? c : a;
                break;
            default:
                if (a > c) max_n = a;
                min_n = (b > c) ? c : b;       
        }
        printf("All positive.\n max = %d\n min = %d\n", max_n, min_n);
        return (max_n - min_n > 32);
    }
    else {
        if (a < 0 || b < 0) {
            if (a < 0){
                if (b < 0) {
                    printf("Two negative: %d, %d.\n", a, b);
                    return (a + b > -256);
                }
                else if (c < 0) {
                    printf("Two negative: %d, %d.\n", a, c);
                    return (a + c > -256);
                }
                else {
                    printf("One negative: %d.\n", a);
                    return (a % 2 == 0);
                }
            }
            else {
                if (c < 0) {
                    printf("Two negative: %d, %d.\n", b, c);
                    return (b + c > -256);
                }
                else {
                    printf("One negative: %d.\n", b);
                    return (b % 2 == 0);
                }
            }
            
        }
        else {
            printf("One negative: %d.\n", c);
            return (c % 2 == 0);    
        }
    }
}

int main()
{
    // printf("%i", (int)'2');
    int32_t a, b ,c;
    printf("Put values of a, b, and c variables:\n");
    scanf("%i%i%i", &a, &b, &c);
    printf("Result:%s", check (a, b, c) ? "True" : "False");
    return 0;
}