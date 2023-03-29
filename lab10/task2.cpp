#include <iostream>
#include <thread>
#include <mutex>

// global variables
std::mutex mtx;  // mutex lock to synchronize access to the account balance
int balance = 100;  // initial account balance

// function to deposit money into the account
void deposit(int amount) {
    // lock the mutex to ensure that only one thread updates the balance at a time
    std::unique_lock<std::mutex> lock(mtx);

    // update the account balance
    int oldBalance = balance;
    int newBalance = oldBalance + amount;
    balance = newBalance;
}

int main() {
    // create three threads for dad, brother, and cousin
    std::thread dad(deposit, 10000);
    std::thread brother(deposit, 5000);
    std::thread cousin(deposit, 5500);

    // join the threads to wait for them to complete
    dad.join();
    brother.join();
    cousin.join();

    // display the final account balance
    std::cout << "Final account balance: " << balance << std::endl;

    return 0;
}
