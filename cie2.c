//  write an open mp program to transform each element with A[i]=3*A[i]+2 use #pragma opm parallel for Schedule(dynamic , 2) then switch to (static ,2) int A2[6]={1,2,3,4,5,6,};//dynamic,2   int A2[6]={1,2,3,4,5,6,};//static ,2   

#include <stdio.h>
#include <omp.h>
int main() {
    int A2[6] = {1, 2, 3, 4, 5, 6};
    printf("Dynamic scheduling (chunk size = 2):\n");
    #pragma omp parallel for schedule(dynamic, 2)
    for (int i = 0; i < 6; i++) {
        A2[i] = 3 * A2[i] + 2;
        printf("Thread %d processed index %d: A2[%d] = %d\n", omp_get_thread_num(), i, i, A2[i]);
    }
    int A2_reset[6] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 6; i++) {
        A2[i] = A2_reset[i];
    }
    printf("\nStatic scheduling (chunk size = 2):\n");
    #pragma omp parallel for schedule(static, 2)
    for (int i = 0; i < 6; i++) {
        A2[i] = 3 * A2[i] + 2;
        printf("Thread %d processed index %d: A2[%d] = %d\n", omp_get_thread_num(), i, i, A2[i]);
    }
    return 0;
}
