#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define size(x) (sizeof((x)) / sizeof((x)[0]))
int main() {
    char string[100] = "The summer soldier, the sunshine patriot";
    char *str;
    char *copy = (char *) malloc(100 * sizeof(char));
    strcpy(copy, string);
    int range[] = {32, 64, 91, 96, 123, 127}; // ASCII non literal characters
    int char_num = 0, counter = 0;
    for (int i = 0; i < size(range); i += 2) char_num += range[i + 1] - range[i] + 1;
    char *del = (char *) malloc(char_num * sizeof(char));
    for (int i = 0; i < size(range); i += 2) {
        for (int j = range[i]; j < range[i + 1] + 1; j++) {
            *(del + counter) = j;
            counter ++;
        }
    }
    puts(del);
    str = strtok(copy, del);
    int min_len = strlen(str);
    printf("%d ", min_len);
    char **strarr;
    strarr = malloc(strlen(copy) * sizeof(char *));
    counter = 0;
    int word_len;
    strarr[counter] = malloc((min_len) * sizeof(char));
    strcpy(strarr[counter], str);
    puts(str);
    do {
        str = strtok(NULL, del);
        if (str) {
            word_len = strlen(str);
            if (word_len < min_len) min_len = word_len;
            strarr[counter] = malloc((word_len) * sizeof(char));
            strcpy(strarr[counter], str);
            counter ++;
            printf("%d  ", word_len);            
            printf("%s\n", str);
        }
    } while (str);

    for (int i = 0; i < counter; i++) {
        if (strlen(strarr[i]) == min_len) {
            printf("The shortest word is \"%s\" of %d letters.", strarr[i], min_len);
            break;
        }
    }
    free(str);
    free(copy);
    free(strarr);
    return 0;
}
