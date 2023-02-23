
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define size(x) (sizeof((x)) / sizeof((x)[0]))
#include <stdbool.h>

bool is_number(char *ch) {    
    for (int i = 48; i < 58; i ++) {
        if (*ch == i) return true; 
    }
    return false;
}
int if_frac(char *ptr) {
    bool del = false, denom = false;
    int i = 0;
    do {
        if (ptr[i] == '.' || ptr[i] == '/' || ptr[i] == ',') {
            if (del) break;
            else del = true;
        }
        else if (is_number(ptr + i)) {
            if (del) denom = true; 
        }        
        else break;
        i ++;
        // ptr[i] = (is_number(ptr + i)) ? 1 : 0;
    } while (i < strlen(ptr));
    if (del && denom) printf("%.*s\n", i, ptr);
    // ptr[i] = 0;
    return i;
}

int main() {
    char string[] = "The summer 658/89. soldier86.8906,6048,0 the s5436unshi3674ne pa96847/13t33.6545riot";
    char *copy = (char *) malloc(100 * sizeof(char));
    // printf("%d",strlen(string));
    strcpy(copy, string);
    char del[] = "0123456789"; // ASCII numerical characters
    // puts(del);
    char *str = strtok(copy, del);
    int shift = if_frac(strstr(string, str) + strlen(str));
    puts(copy);
    int pos = strlen(str) + shift;
    // *(copy + pos) = '\0';
    puts(copy + pos);
    // puts(str);
    do {
        str = strtok(copy + pos, del);
        if (str) {
            shift = if_frac(strstr(string + pos, str) + strlen(str));
            // if (str) shift = if_frac(copy + pos + strlen(str) + 1); /0 on the delimeter position (lost of 1 number)
            pos += strlen(str) + shift;
            puts(copy + pos);
            // *(copy + pos) = '\0';
        }
    } while (str);

    free(str);
    free(copy);
    return 0;
}
