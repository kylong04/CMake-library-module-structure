#include <stdio.h>
#include "appLib.h"
#include <string.h>
#include <stdint.h>
    
uint32_t testcase_pass=0;
uint32_t testcase_fail=0;
static char original_data[] = "Hello World ";


void testcase_test_helloworld_normal() {
    char expected[30] = "Hello World kylong" ;
    char test_data[30];
    char username[] = "kylong";
    strcpy(test_data, original_data);
    test_hello_world(test_data, username);
    if (!strcmp(expected, test_data)) {
        printf("Test passed:%s\n", __func__);
        testcase_pass++;
    }
    else {
        printf("Test failed:%s, expected '%s'\t, actual: '%s'\n", __func__, expected, test_data);
        testcase_fail++;
    }
}

void testcase_test_helloworld_null_input_str() {
    char expected[30] = "Hello World kylong" ;
    char test_data[30];
    char username[] = "kylong";
    strcpy(test_data, original_data);
    test_hello_world(NULL, username);
    if (!strcmp(expected, test_data)) {
        printf("Test passed:%s\n", __func__);
        testcase_pass++;
    }
    else {
        printf("Test failed:%s, expected '%s'\t, actual: '%s'\n", __func__, expected, test_data);
        testcase_fail++;
    }
}

void testcase_test_helloworld_null_username() {
    char expected[30] = "Hello World kylong" ;
    char test_data[30];
    strcpy(test_data, original_data);
    test_hello_world(test_data, NULL);
    if (!strcmp(expected, test_data)) {
        printf("Test passed:%s\n", __func__);
        testcase_pass++;
    }
    else {
        printf("Test failed:%s, expected '%s'\t, actual: '%s'\n", __func__, expected, test_data);
        testcase_fail++;
    }
}

void testcase_test_helloworld_strncpy_test_data() {
    char expected[30] = "Hello World kylong" ;
    char test_data[5] = {0};
    char username[] = "kylong";
    strncpy(test_data, original_data, sizeof(test_data));
    test_data[4] = '\0';
    test_hello_world(test_data, username);
    if (!strcmp(expected, test_data)) {
        printf("Test passed:%s\n", __func__);
        testcase_pass++;
    }
    else {
        printf("Test failed:%s, expected '%s'\t, actual: '%s'\n", __func__, expected, test_data);
        testcase_fail++;
    }
}

int main() {
    testcase_test_helloworld_normal();
    testcase_test_helloworld_null_input_str();
    testcase_test_helloworld_null_username();
    testcase_test_helloworld_strncpy_test_data();
    printf("Total tests case: %d\n", testcase_pass + testcase_fail);
    printf("Test passed: %d\n", testcase_pass);
    printf("Test fail: %d\n", testcase_fail);
    return 0;
}
