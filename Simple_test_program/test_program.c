#include <stdio.h>
#include "appLib.h"
#include <string.h>
#include <stdint.h>
    
uint32_t testcase_pass=0;

void testcase_compare_HelloWorld() {
    char original_data[] = "Hello World ";
    char test_data[30];
    char username[] = "kylong";
    strcpy(test_data, original_data);   
    test_hello_world(NULL, username);
    if (!strcmp(original_data, test_data)) {
        printf("Test passed\n");
        testcase_pass++;
    }
    else {
        printf("Test failed, expected '%s'\t, actual: '%s'\n", original_data, test_data);
    }
}

int main() {
    testcase_compare_HelloWorld();
    printf("Total tests passed: %d\n", testcase_pass);
    return 0;
}