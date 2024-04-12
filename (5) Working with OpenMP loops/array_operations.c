#include <stdio.h>
#include <omp.h>

#define N 5  // Розмір масивів

int main() {
    double A[N], B[N], C[N], D[N];
    double product = 1.0;

    // Ініціалізуємо масиви A, B та C
    A[0] = 1; B[0] = 2; C[0] = 3;
    A[1] = 4; B[1] = 5; C[1] = 6;
    A[2] = 7; B[2] = 8; C[2] = 9;
    A[3] = 10; B[3] = 11; C[3] = 12;
    A[4] = 13; B[4] = 14; C[4] = 15;

    // Обчислюємо масив за формулою: D[i] = A[i] + B[i] * C[i]
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        D[i] = A[i] + B[i] * C[i];
    }

    // масиви A, B, C та D
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

    // добуток елементів масиву D за допомогою директиви reduction
    #pragma omp parallel for reduction(*:product)
    for (int i = 0; i < N; i++) {
        product *= D[i];
    }

    // результат добутку
    printf("Product of elements in array D: %.0f\n", product);

    return 0;
}
