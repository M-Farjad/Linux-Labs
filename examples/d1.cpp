#include <iostream>
#include <pthread.h>
#include <cstdlib>

void *addition(void *args);
void *subtraction(void *args);
void *multiplication(void *args);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        std::cout << "Usage: " << argv[0] << " num1 num2 command\n";
        std::cout << "command: A=addition, S=subtraction, M=multiplication\n";
        return 1;
    }

    int num1 = std::atoi(argv[1]);
    int num2 = std::atoi(argv[2]);

    pthread_t thread;
    if (argv[3][0] == 'A') {
        pthread_create(&thread, NULL, addition, (void *) (long) (num1 + num2));
    }
    else if (argv[3][0] == 'S') {
        pthread_create(&thread, NULL, subtraction, (void *) (long) (num1 - num2));
    }
    else if (argv[3][0] == 'M') {
        pthread_create(&thread, NULL, multiplication, (void *) (long) (num1 * num2));
    }
    else {
        std::cout << "Invalid command: " << argv[3][0] << std::endl;
        return 1;
    }

    void *result;
    pthread_join(thread, &result);
    std::cout << "Result: " << (long) result << std::endl;

    return 0;
}

void *addition(void *args) {
    long result = (long) args;
    return (void *) result;
}

void *subtraction(void *args) {
    long result = (long) args;
    return (void *) result;
}

void *multiplication(void *args) {
    long result = (long) args;
    return (void *) result;
}
