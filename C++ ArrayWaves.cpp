#include <iostream>
#include <omp.h>
using namespace std;

int main()
{
    cout << "Input a size of array: ";
    int ARRAY_SIZE = 0;
    cin >> ARRAY_SIZE;
    int* arr = new int[ARRAY_SIZE];
    int thread;
    int sum = 0;
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        arr[i] = i;
    }

    while (ARRAY_SIZE > 1) {
        int num_thread = ARRAY_SIZE / 2;
        #pragma omp parallel for num_threads(num_thread)
        for (int i = 0; i < num_thread; ++i) {
            thread = omp_get_thread_num();
            arr[i] = arr[i] + arr[ARRAY_SIZE - 1 - i];
            printf("\n Thread %d: arr[%d] = %d", thread, i, arr[i]);
        }
        if (ARRAY_SIZE % 2 == 1) {
            ARRAY_SIZE = ARRAY_SIZE / 2 + 1;
        }
        else {
            ARRAY_SIZE /= 2;
        }
        printf("\n -------------");
    }

    printf("\n -------------");
    printf("\n total sum = %d", arr[0]);
    return 0;
}