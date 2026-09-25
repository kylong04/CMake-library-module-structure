#include "appLib.h"
#include <string.h>
#include <stdio.h>

char* test_hello_world(char *input_str, char *username) {
    strcat(input_str, username);
    //printf("In: %s\t, input_str: %s\t, username: %s\n", __func__, input_str, username);
    return input_str; 
}