#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <pthread.h>
#include<string.h>

using namespace std;
void *highestAndLowest(void *args);

int main(int argc, char *argv[]) {
    string name = argv[1];
    string rollNum = argv[2];
    char* cgpa = argv[3];
    int age = atoi(argv[4]);


    pthread_t thread;
    pthread_create(&thread, NULL, highestAndLowest, (void *) argv);
    int gpa = atoi(cgpa);
 
    void *result;
    pthread_join(thread, &result);
    printf("Result: %ld\n", (long) result);

    return 0;
}

void *highestAndLowest(void *args) {
    long result = (long) args;
    return (void *) result;
}

