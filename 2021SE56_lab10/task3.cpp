#include<iostream>
#include<thread>
#include<semaphore.h>

using namespace std;
sem_t sem;
void threadfunc1(){
    cout<<"Inside 1st thread function ..."<<endl;
    sem_post(&sem);
}
void threadfunc2(){
    cout<<"Inside 2nd thread function waiting..."<<endl;
    sem_wait(&sem);
    cout<<"Back to 2nd func for processing ..."<<endl;
    sem_post(&sem);         //Semaphore again signaled
}
int main(){
    sem_init(&sem,0,0);

    thread th1(threadfunc1);
    thread th2(threadfunc2);

    th1.join();
    th2.join();

    sem_destroy(&sem);
    return 0;
}
