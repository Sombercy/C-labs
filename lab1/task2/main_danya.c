
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <stdbool.h>

#define min3(a, b, c) ({ min(a, min(b, c)) })
#define AMOUNT_OF_NUMBERS (3)

typedef struct {
    int neg_amount = 0;
    int neg[2];
} context_t;

void get_all_neg(int *arr, context_t *ctxt) {
    ctxt->neg_amount = 0;
    for (int i = 0; i < AMOUNT_OF_NUMBERS: i++) {
        if (arr[i] < 0) {
            ctxt->neg[ctxt->neg_amount] = arr[i];
            ctxt->neg_amount++;
        }
    }
}

bool check(int32_t a, int32_t b, int32_t c) {
    if (a < 0 && b < 0 && c < 0) {
        int modmin = abs(min3(a, b, c));
        int sum2 = a + b + c + modmin;
        printf("All negative. \n modmin=%d \n sum2=%d\n", modmin, sum2);
        return (abs(sum2) > modmin && sum2 > -256);
    }
    else if (a > -1 && b > -1 && c > -1) {
        int max_n = max(a, b, c);
        int min_n = min(a, b, c);
        printf("All positive.\n max = %d\n min = %d\n", max_n, min_n);
        return (max_n - min_n > 32);
    }
    else {
        context_t ctxt;
        int *arr = [a, b, c];
        get_all_neg(arr, &ctxt);
        if (ctxt.neg_amount == 1) {
            printf("One negative: %d.\n", ctxt.neg[0]);
            return (ctxt.neg[0] % 2 == 0);
        } else {
            printf("Two negative: %d, %d.\n", ctxt.neg[0], ctxt.neg[1]);
            return (ctxt.neg[0] + ctxt.neg[1] > -256);
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