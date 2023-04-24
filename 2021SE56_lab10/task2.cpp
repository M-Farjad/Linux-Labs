#include <iostream>
#include <thread>
#include <semaphore.h>

using namespace std;
sem_t sem;
int balance = 100;

void deposit(int amount){
    sem_wait(&sem);
    int old_balance = balance;
    int new_balance = old_balance + amount;
    balance = new_balance;
    sem_post(&sem);
}
int main(){
    sem_init(&sem,0,1);
    thread dad(deposit,10000);
    thread brother(deposit,5000);
    thread cousin(deposit,5500);

    dad.join();
    brother.join();
    cousin.join();
    sem_destroy(&sem);

    cout<<"Final Amount in your Account is:"<<balance<<endl;
    return 0;
}