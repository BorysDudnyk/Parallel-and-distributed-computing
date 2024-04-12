#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 5  

double A[N] = {1, 4, 7, 10, 13};
double B[N] = {2, 5, 8, 11, 14};
double C[N] = {3, 6, 9, 12, 15};
double D[N];
double product = 1.0;

pthread_mutex_t product_mutex = PTHREAD_MUTEX_INITIALIZER;

void *compute_D_and_product(void *arg) {
    int i = *(int *)arg;
    
    D[i] = A[i] + B[i] * C[i];
    
    pthread_mutex_lock(&product_mutex);
    product *= D[i];
    pthread_mutex_unlock(&product_mutex);
    
    return NULL;
}

int main() {
    pthread_t threads[N]; 
    int indices[N];  

    for (int i = 0; i < N; i++) {
        indices[i] = i;
        pthread_create(&threads[i], NULL, compute_D_and_product, &indices[i]);
    }

    for (int i = 0; i < N; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Array A: ");
    for (int i = 0; i < N; i++) {
        printf("%.0f ", A[i]);
    }
    printf("\n");

    printf("Array B: ");
    for (int i = 0; i < N; i++) {
        printf("%.0f ", B[i]);
    }
    printf("\n");

    printf("Array C: ");
    for (int i = 0; i < N; i++) {
        printf("%.0f ", C[i]);
    }
    printf("\n");

    printf("Array D: ");
    for (int i = 0; i < N; i++) {
        printf("%.0f ", D[i]);
    }
    printf("\n");

    printf("Product of elements in array D: %.0f\n", product);

    pthread_mutex_destroy(&product_mutex);

    return 0;
}
