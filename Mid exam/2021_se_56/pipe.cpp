#include<iostream>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;
int main()
{
    int fd1[2];
    char buffer[100];
    char array[] = "";
    pid_t p;
    cout<<"Enter the message you want print: ";
    cin>>array;
    if (pipe(fd1) == -1) {
        fprintf(stderr, "Pipe Failed");
        return 1;
    }
    p = fork();
 
    if (p < 0) {
        fprintf(stderr, "fork Failed");
        return 1;
    }
    else {
        if(p==0){
            close(fd1[1]);
            int characters =read(fd1[0],buffer,sizeof(buffer));
            cout<<"Message recieved in child: "<<buffer<<endl;
            close(fd1[0]);
        }
        if(p>0){
            close(fd1[0]);
            write(fd1[1],array,sizeof(array));
            cout<<"Message written for parent:"<<array<<endl;
            close(fd1[1]);
        }
        
    }
    return 0;
    
}