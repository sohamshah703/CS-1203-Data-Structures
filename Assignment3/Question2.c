#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Insertion Sort
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        // Comparing and shifting elements to make space for the key
        while (key < arr[j] && j >= 0) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swapping elements if they are in the wrong order
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


int main() {
    int n = 10000; // Initializing the size of the array
    int arr1[n], arr2[n];
    for (int i = 0; i < n; i++) {
        int val = rand() % n;
        arr1[i] = val;
        arr2[i] = val;
    }

    clock_t start, end; // Using a timer
    double timetaken;

    // Measure the time taken by the Insertion Sort
    start = clock();
    insertionSort(arr1, n);
    end = clock();
    timetaken = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Insertion sort took %f seconds to execute\n", timetaken);

    // Measure the time taken by Bubble Sort
    start = clock();
    bubbleSort(arr2, n);
    end = clock();
    timetaken = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Bubble sort took %f seconds to execute\n", timetaken);

    return 0;
}
