#include <stdio.h>
#include <omp.h>

int main(void) {
    int max_threads = omp_get_max_threads();
    omp_set_num_threads(4);
    
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num(); 
        
        if (thread_id % 2 == 0)
            printf("Name: Thread ID %d\n", thread_id);
        else
            printf("Surname: Thread ID %d\n", thread_id);
    }
    
    printf("Maximum number of threads: %d\n", max_threads);
    
    return 0;
}