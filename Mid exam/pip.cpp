

// #include <iostream>
// #include <unistd.h>
// #include <cstring>

// using namespace std;

// int main() {
//     int fd[2];
//     char message[] = "Hello, child process!";
//     char buffer[100];

//     if (pipe(fd) == -1) {
//         perror("pipe failed");
//         return 1;
//     }

//     pid_t pid = fork();


//     if (pid == 0) { 
//         close(fd[1]); 
//         int nbytes = read(fd[0], buffer, sizeof(buffer));
//         cout << "Child process received message: " << buffer << endl;
//         close(fd[0]);
//     } else { 
//         close(fd[0]); 
//         int nbytes = write(fd[1], message, strlen(message)+1);
//         cout << "Parent process sent message: " << message << endl;
//         close(fd[1]);
//     }

//     return 0;
// }