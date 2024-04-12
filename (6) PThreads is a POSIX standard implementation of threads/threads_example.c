#include <stdio.h>
#include <pthread.h>

#define MAX_THREADS 4

const char *first_name = "Borys";
const char *last_name = "Dudnyk";

void *thread_function(void *arg) {
    int thread_id = *((int *)arg);
    if (thread_id % 2 == 0) {
        printf("First name: %s\n", first_name);
    } else {
        printf("Last name: %s\n", last_name);
    }
    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    int thread_ids[MAX_THREADS];
    int i;

    for (i = 0; i < MAX_THREADS; i++) {
        thread_ids[i] = i;
        if (pthread_create(&threads[i], NULL, thread_function, &thread_ids[i])) {
            printf("Error creating thread %d\n", i);
            return 1;
        }
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
