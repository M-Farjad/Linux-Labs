#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 100
char buffer[BUFFER_SIZE];
pthread_mutex_t buf_mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t message_available = PTHREAD_COND_INITIALIZER;
void* sender(void* arg)
{
    pthread_mutex_lock(&buf_mtx);
    snprintf(buffer, BUFFER_SIZE, "Hello from the sender thread");
    pthread_cond_signal(&message_available);
    pthread_mutex_unlock(&buf_mtx);
    pthread_exit(NULL);
}
void* receiver(void* arg)
{
    pthread_mutex_lock(&buf_mtx);
    while (buffer[0] == '\0') {
        pthread_cond_wait(&message_available, &buf_mtx);
    }
    printf("Message received: %s\n", buffer);
    pthread_mutex_unlock(&buf_mtx);
    pthread_exit(NULL);
}

int main()
{
    pthread_t sender_t, receiver_t;
    pthread_create(&sender_t, NULL, sender, NULL);
    pthread_create(&receiver_t, NULL, receiver, NULL);
    
    pthread_join(sender_t, NULL);
    pthread_join(receiver_t, NULL);
    
    return 0;
}
