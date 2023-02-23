#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool is_number(char *ch) {    
    for (int i = 48; i < 58; i ++) {
        if (*ch == i) return true; 
    }
    return false;
}

int *if_int(char *ptr) {
    static int r[2];
    int i = 0;
    do {
        if (is_number(ptr + i)) {
            i ++;
            continue;  
        }
        else break;
    } while (i < strlen(ptr));
    if (i > 0) {
        char subbuff[i + 1];
        memcpy(subbuff, ptr, i + 1);
        r[1] = atoi(subbuff);
    } 
    else r[1] = 1;
    r[0] = i; 
    return r;
}

int main()
{
    char string[] = "The summer 658/89. soldier86.8906,6048,0 the s5436unshi3674ne pa96847/13t33.6545riot";
    char *copy = (char *) malloc(100 * sizeof(char));
    // printf("%d",strlen(string));
    strcpy(copy, string);
    char del[] = "0123456789"; // ASCII numerical characters
    char *str = strtok(copy, del);
    int *shift_val; 
    shift_val = if_int(strstr(string, str) + strlen(str));
    int pos = strlen(str) + shift_val[0];
    int prod = shift_val[1];
    do {
        str = strtok(copy + pos, del);
        if (str) {
            shift_val = if_int(strstr(string + pos, str) + strlen(str));
            pos += strlen(str) + shift_val[0];
            prod *= shift_val[1];
        }
    } while (str);

    free(str);
    free(copy);
}
