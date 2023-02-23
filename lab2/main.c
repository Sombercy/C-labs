#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif
#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif
#define size(x) (sizeof((x)) / sizeof((x)[0]))

typedef void (*handler_function)(void);
typedef struct {
    int key;
    handler_function func;
} handler_t;

handler_function get_handler_func();
// get_handler_function returns handler function

int random_number(int min_num, int max_num);
void array_2();
void string();
void help();
void display(); 
void t_choise();
bool cmd_handler();
enum op {
    FRST_OP = 1,
    SCND_OP = 2,
    THRD_OP = 3,
    FRTH_OP = 4,
    FFTH_OP = 5,
    SXTH_OP = 6,
    SVN_OP = 7
} cmd;

enum task {
    ARR1_TASK = 1,
    ARR2_TASK = 2,
    STR_TASK = 3
};

void cmd_1(void);
void cmd_2(void);
void cmd_3(void);
void cmd_4(void);
void cmd_5(void);
void cmd_6(void);
void cmd_7(void);



// handler_t *arr_ptr = &arr;

typedef struct {
    char s_cmd[5];
    char *cptr;
    int *ptr;
    int state;
    int input;
    int cur_arr_size;
    handler_t *cmd_arr;
    int cmd_arr_size;
} global_context_t;

typedef struct min_max {
        int min_val;
        int max_val;
        int min_pos;
        int max_pos;
    };

global_context_t gctxt;


void wrong_input() {
    printf("Wrong input.");
}


int random_number(int min_num, int max_num)
{
    int result = 0, low_num = 0, hi_num = 0;
    low_num = min_num;
    hi_num = max_num + 1; // include max_num in output
    srand(time(NULL));
    result = (rand() % (hi_num - low_num)) + low_num;
    return result;
}
   


void display() {
    switch (gctxt.state)
    {
        case ARR1_TASK: {
            for (int i = 0; i < gctxt.cur_arr_size; i++) {
                printf("%d ", *(gctxt.ptr + i));
            }
            printf("\n");
            break;
        }
        case ARR2_TASK: {
            for (int i = 0; i < gctxt.cur_arr_size; i++) {
                for (int j = 0; j < gctxt.cur_arr_size; j++) {
                    printf("%d ", *(gctxt.ptr + i * sizeof(int) + j * sizeof(int)));
                }
                printf("\n");
            }
            break;
        }    
        case STR_TASK: {
            printf("String Output: ");
            puts(gctxt.cptr);
            printf(" %d\n", strlen(gctxt.cptr));        
            break;    
        }
    }
}    

void help() {
    switch (gctxt.state)
    {
    case ARR1_TASK: {
        printf("Choose one of operations by number:\n"
               "1) Fill the array with random numbers from L to H;\n"
               "2) Make all elements zero;\n"
               "3) Find min element and it's index;\n"
               "4) Find the sum of all elements;\n"
               "5) Find the produc of all negative valued elements;\n"
               "6) Swap min and max elements;\n"
               "7) Decrease all elements by intended number.\n");
        break;
    }
    case ARR2_TASK: {
        printf("Choose one of operations by number:\n"
               "1) Fill the array with random numbers from L to H;\n"
               "2) Make all elements zero;\n"
               "3) Find max element and it's indices;\n"
               "4) Find the sum of side diagonal elements;\n"
               "5) Find the sum of the given column elements;\n"
               "6) Swap min and max elements;\n"
               "7) Change the given indices (i, j) element value on the input.\n");
        break;       
    }   
    case STR_TASK: {
        printf("Choose one of operations by number:\n"
                "1) Fill the string with input;\n"
                "2) Clear the string;\n"
                "3) Print the substring starting from the given position of the given length;\n"
                "4) Print a list of substrings delimited with a given character;\n"
                "5) Print out the shortest word (non-empty sequence of literals);\n"
                "6) Find and print out all fractional numbers;\n"
                "7) Find and print out the product of all integers within the string.\n");
        break;   
    }
    default:
        break;
    }
        
}

bool cmd_handler() {
    if (strcmp(gctxt.s_cmd, "help") == 0) help();
    else if (gctxt.s_cmd[1] == 0) {
        gctxt.input = gctxt.s_cmd[0] - '0';
        if (gctxt.input < 8 && gctxt.input > 0) return true; 
        }
    else wrong_input();   
    return false;   
}

handler_function get_handler_func() {
    for (int i = 0; i < gctxt.cmd_arr_size; i++) {
        if (gctxt.cmd_arr[i].key == gctxt.input) return gctxt.cmd_arr[i].func; 
    }
    return NULL;
}

int *rand_range(){
    static int range[2];
    printf("Indicate a range of random numbers:");
    while (true) {
        scanf("%d%d", range, range + 1);
        if (range[0] < range[1]) break;
        else wrong_input();
    }    
    return range;
}

void cmd_1() {
    switch (gctxt.state)
    {
        case ARR1_TASK: {
            int *range = rand_range();
            for (int i = 0; i < gctxt.cur_arr_size; i++) {
                *(gctxt.ptr + i) = random_number(*range, *(range + 1));
            }
            break;
        }
        case ARR2_TASK: {
            int *range = rand_range();
            for (int i = 0; i < gctxt.cur_arr_size; i++){
                for (int j = 0; j < gctxt.cur_arr_size; j++){
                    *(gctxt.ptr + i * sizeof(int) + j * sizeof(int)) = random_number(*range, *(range + 1));
                }
            }
            break;            
        }
        case STR_TASK: {
            printf("Provide your input for the string:");
            fgets(gctxt.cptr, sizeof(gctxt.cur_arr_size), stdin);
            break;        
            }
        default:
            break;
    }
}

void cmd_2() {
    switch (gctxt.state)
    {
        case ARR1_TASK: {
            memset(gctxt.ptr, 0, gctxt.cur_arr_size * sizeof(int));
            break;
        }
        case ARR2_TASK: {
            memset(gctxt.ptr, 0, gctxt.cur_arr_size * gctxt.cur_arr_size * sizeof(int));
            break;
        }
        case STR_TASK: {
            *(gctxt.cptr) = "/0";
            break;
        }
        default:
            break;
    }

}


void cmd_3() {
    switch (gctxt.state)
    {
        case ARR1_TASK: {
            int value = *(gctxt.ptr);
            int index = 0;
            for (int i = (gctxt.cur_arr_size % 2) ? 1 : 0; i < gctxt.cur_arr_size - 1; i += 2) { 
                if (min(*(gctxt.ptr + i), *(gctxt.ptr + i + 1)) < value) {
                    if (*(gctxt.ptr + i) < *(gctxt.ptr + i + 1)) {
                        value = *(gctxt.ptr + i);
                        index = i;
                    }
                    else {
                        value = *(gctxt.ptr + i + 1);
                        index = i + 1;
                    }
                }
            }
            printf("Minimal value %d has %d element\n", value, index);
            break;
        }
        case ARR2_TASK: {
            int value = *(gctxt.ptr);
            int index[2] = {0, 0};
            for (int i = (gctxt.cur_arr_size % 2) ? 1 : 0; i < gctxt.cur_arr_size * gctxt.cur_arr_size - 1; i += 2) {
                if (max(*(gctxt.ptr + i), *(gctxt.ptr + i + 1)) > value) {  
                    if (*(gctxt.ptr + i) > *(gctxt.ptr + i + 1)) {
                        value = *(gctxt.ptr + i);
                        index[0] = i / gctxt.cur_arr_size;
                        index[1] = i % gctxt.cur_arr_size;
                    }
                    else {
                        value = *(gctxt.ptr + i + 1);
                        index[0] = (i + 1) / gctxt.cur_arr_size;
                        index[1] = (i + 1) % gctxt.cur_arr_size;
                    }           
                }
            }
            printf("Maximum value %d has (%d, %d) element\n", value, index[0], index[1]);
        }      
        case STR_TASK: {
            int pos, len;
            char *str;
            printf("Indicate position and length of the sub-string to substract:");
            scanf("%d%d", &pos, &len);
            str = (char*) malloc(len * sizeof(char));
            memcpy(str,gctxt.cptr + pos, len);
            printf("Substring is: %s", str);
            free(str);
        }  
        default:
            break;
    }

}

void cmd_4() {
    switch (gctxt.state)
    {
        case ARR1_TASK: {
            int sum = 0;
            for (int i = 0; i < gctxt.cur_arr_size; i++) { 
                sum += *(gctxt.ptr + i);
            }
            printf("The sum of the array elements: %d\n", sum);
            break;
        }
        case ARR2_TASK: {
            int sum = 0;
            for (int i = 0; i < gctxt.cur_arr_size; i++) {
                sum += *((gctxt.ptr + i * gctxt.cur_arr_size) + (gctxt.cur_arr_size - 1 - i));
            }
            printf("The sum of the array elements: %d\n", sum);
            break;
        }
        case STR_TASK: {
            char *copy, del, *substring;
            printf("Provide the delimeter to cut the string:");
            scanf("%d", &del);
            copy = (char *) malloc(gctxt.cur_arr_size * sizeof(char));
            strcpy(copy, gctxt.cptr);
            substring = strtok(copy, &del);
            puts(substring);
            do {
                substring = strtok(NULL, &del);
                if (substring) printf("%s\n", substring);
            } while (substring);
        }
        default:
            break;
    }
}

void cmd_5() {
    switch (gctxt.state)
    {
        case ARR1_TASK: {
            int dot = 0;
            for (int i = 0; i < gctxt.cur_arr_size; i++) { 
                if (*(gctxt.ptr + i) < 0) dot += *(gctxt.ptr + i);
            }
            printf("The product of negative elements of the array: %d\n", dot);
            break;
        }
        case ARR2_TASK: {
            int col, sum = 0;
            scanf("%d", &col);
            for (int i = 0; i < gctxt.cur_arr_size; i++) {
                sum += *(gctxt.ptr + i * gctxt.cur_arr_size + col);
            }
            printf("The sum of the %d column is %d\n", col, sum);
            break;
        }
        case STR_TASK: {
            char *str;
            char *copy = (char *) malloc(gctxt.cur_arr_size * sizeof(char));
            strcpy(copy, gctxt.cptr);
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
            str = strtok(copy, del);
            int min_len = strlen(str);
            char **strarr; //array of char pointers
            strarr = malloc(strlen(copy) * sizeof(char *));
            counter = 0;
            int word_len;
            strarr[counter] = (char *) malloc((min_len) * sizeof(char)); // strarr[counter] = *(strarr + counter)
            strcpy(strarr[counter], str);
            do {
                str = strtok(NULL, del);
                if (str) {
                    word_len = strlen(str);
                    if (word_len < min_len) min_len = word_len;
                    strarr[counter] = malloc((word_len) * sizeof(char));
                    strcpy(strarr[counter], str);
                    counter ++;
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
        }
        default:
            break;
    }
}

struct min_max find_extremum(int arr_size) {
    struct min_max arr;
    arr.max_pos = 0;
    arr.min_pos = 0;
    arr.max_val = *gctxt.ptr;
    arr.min_val = *gctxt.ptr;
    for (int i = 1; i < arr_size; i++) { 
        if (*(gctxt.ptr + i) < arr.min_val) {
            arr.min_pos = i;
            arr.min_val = *(gctxt.ptr + i);
        }      
        else if (*(gctxt.ptr + i) > arr.max_val) {
            arr.max_pos = i;
            arr.max_val = *(gctxt.ptr + i);
        }      
    }
    return arr;
}

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
    } while (i < strlen(ptr));
    if (del && denom) printf("%.*s\n", i, ptr);
    return i;
}

int *if_int(char *ptr) {
    static int r[2];
    int i = 0;
    do {
        if (is_number(ptr + i)) {
            continue;       
            i ++;
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


void cmd_6() {
    switch (gctxt.state)
    {
        case ARR1_TASK: {
            struct min_max arr1 = find_extremum(gctxt.cur_arr_size);
            *(gctxt.ptr + arr1.max_pos) ^= *(gctxt.ptr + arr1.min_pos) ^= *(gctxt.ptr + arr1.max_pos) ^= *(gctxt.ptr + arr1.min_pos);
            break;
        }
        case ARR2_TASK: {
            struct min_max arr2 = find_extremum(gctxt.cur_arr_size * gctxt.cur_arr_size);
            // int index_max [2] = {arr2.max_pos / gctxt.cur_arr_size, arr2.max_pos % gctxt.cur_arr_size};
            // int index_min [2] = {arr2.min_pos / gctxt.cur_arr_size, arr2.min_pos % gctxt.cur_arr_size};
            *(gctxt.ptr + arr2.max_pos) ^= *(gctxt.ptr + arr2.min_pos) ^= *(gctxt.ptr + arr2.max_pos) ^= *(gctxt.ptr + arr2.min_pos);
            break;
        }
        case STR_TASK: {
            char *str;
            char *copy = (char *) malloc(gctxt.cur_arr_size * sizeof(char));
            strcpy(copy, gctxt.cptr);
            char del[] = "0123456789"; // ASCII numerical characters
            // puts(del);
            char *str = strtok(copy, del);
            int shift = if_frac(strstr(gctxt.cptr, str) + strlen(str));
            int pos = strlen(str) + shift;
            do {
                str = strtok(copy + pos, del);
                if (str) {
                    shift = if_frac(strstr(gctxt.cptr + pos, str) + strlen(str));
                    pos += strlen(str) + shift;
                }
            } while (str);

            free(str);
            free(copy);
        }
        default:
            break;
    }    
}

void cmd_7() {
    switch (gctxt.state)
    {
        case ARR1_TASK: {
            int n;
            printf("Write down the value to minus from all the elements:");
            scanf("%d", &n);
            for (int i = 0; i < gctxt.cur_arr_size; i++) {
                *(gctxt.ptr + i) -= n;
            }
            break;
        }
        case ARR2_TASK: {
            printf("Provide positions of the elements to swap in format"
                    "row_1 col_1 row_2 col_2, counting from 0: ");
            int swap_index [4];
            scanf("%d%d%d%d", swap_index, swap_index + 1, swap_index + 2, swap_index + 3);  
            int pos [2] = {swap_index[0] * gctxt.cur_arr_size + swap_index[1], swap_index[2] * gctxt.cur_arr_size + swap_index[3]};
            *(gctxt.ptr + pos[0]) ^= *(gctxt.ptr + pos[1]) ^= *(gctxt.ptr + pos[0]) ^= *(gctxt.ptr + pos[1]);      
        }
        case STR_TASK: {
            char *str;
            char *copy = (char *) malloc(gctxt.cur_arr_size * sizeof(char));
            strcpy(copy, gctxt.cptr);
            char del[] = "0123456789"; // ASCII numerical characters
            char *str = strtok(copy, del);
            int *shift_val; 
            shift_val = if_int(strstr(gctxt.cptr, str) + strlen(str));
            int pos = strlen(str) + shift_val[0];
            int prod = shift_val[1];
            do {
                str = strtok(copy + pos, del);
                if (str) {
                    shift_val = if_int(strstr(gctxt.cptr + pos, str) + strlen(str));
                    pos += strlen(str) + shift_val[0];
                    prod *= shift_val[1];
                }
            } while (str);

            free(str);
            free(copy);

        }
        default:
            break;
    }
}
int arr_len() {
    int len;
    printf("Write down linear size of an array:");
    scanf("%d", &len);
    // how to handle errors, like char insted of int
    return len;
}

void array_1(){
    display();
    printf("You're in 1-D array manipulation.\n");
    gctxt.cur_arr_size = arr_len();
    gctxt.ptr = (int*) calloc(gctxt.cur_arr_size, sizeof(int));
    while (true) {
        display();
        scanf("%s", gctxt.s_cmd);
        if (strcmp(gctxt.s_cmd,"out") == 0) break;
        else if (cmd_handler()) get_handler_func()();

    }
    free(gctxt.ptr);     
    
}

void array_2(){
    display();
    printf("You're in 2-D array manipulation.\n");
    gctxt.cur_arr_size = arr_len();
    gctxt.ptr = (int*) calloc(gctxt.cur_arr_size * gctxt.cur_arr_size, sizeof(int)); //init array with zeroes
    while (true) {
        display();
        scanf("%s", gctxt.s_cmd);
        if (strcmp(gctxt.s_cmd,"out") == 0) break;
        else if (cmd_handler()) get_handler_func()();

    }
    free(gctxt.ptr);     
}

void rand_init() {
    for (int i = 0; i < gctxt.cur_arr_size; i++) {
    *(gctxt.cptr + i) = random_number(32, 127);
    }   
}
void string(){
    printf("You're in string manipulation.\n");
    gctxt.cur_arr_size = arr_len();
    gctxt.cptr = (char*) malloc(gctxt.cur_arr_size * sizeof(char));
    rand_init();
    while (true) {
        display();
        scanf("%s", gctxt.s_cmd);
        if (strcmp(gctxt.s_cmd,"out") == 0) break;
        else if (cmd_handler()) get_handler_func()();

    }
    free(gctxt.ptr);
} 

void t_choise() {
    printf("Choose one of the tasks:\n 1) 1-D array\n"
           "2) 2-D array\n 3) String\nUse \"help\" for help\n");
    scanf("%d", &gctxt.state);
    switch (gctxt.state)
    {
        case ARR1_TASK:
            array_1();
            break;
        case ARR2_TASK:
            array_2();
            break;
        case STR_TASK: 
            string();
            break;
        default:
            wrong_input();
            break;
    }
}


int main()
{   handler_t arr[] = {
        {FRST_OP, cmd_1},
        {SCND_OP, cmd_2},
        {THRD_OP, cmd_3}, 
        {FRTH_OP, cmd_4},
        {FFTH_OP, cmd_5},
        {SXTH_OP, cmd_6},
        {SVN_OP, cmd_7}
    };
    memset(&gctxt, 0, sizeof(global_context_t));
    gctxt.cmd_arr = &arr;
    gctxt.cmd_arr_size = size(arr);
    while (true) t_choise();
    return 0;
}
