#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Merge Sort: Merges the two subarrays. 
// The first subarray is l to m and the second subarray is m+1 to r.
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; // Calculating the sizes of the two subarrays
    int n2 = right - mid;

    int Left_arr[n1], Right_arr[n2]; // Creating temporary arrays to hold the data of the two subarrays

    for (int i = 0; i < n1; i++) // Copying data from arr[] to the two subarrays
        Left_arr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        Right_arr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {  // Merging the two subarrays back
        if (Left_arr[i] <= Right_arr[j]) {
            arr[k] = Left_arr[i];
            i++;
        } else {
            arr[k] = Right_arr[j];
            j++;
        }
        k++;
    }

    while (i < n1) { // Copy the remaining elements of Left_arr[], if there are any
        arr[k] = Left_arr[i];
        i++;
        k++;
    }

    while (j < n2) { // Copy the remaining elements of Right_arr[], if there are any
        arr[k] = Right_arr[j];
        j++;
        k++;
    }
}

// The main merge sort function that recursively divides arrays into their subarrays and merges them.
void mergeSort(int arr[], int left, int right) { 
    if (left < right) {
        
        int mid = left + (right - left) / 2;  // Calculating the middle point to divide the two arrays.
        mergeSort(arr, left, mid);  // Recursively sorting the first and second halves.
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right); // Merging the sorted halves.
    }
}



// Quick Sort
// Function swaps two elements in the array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int partition(int arr[], int low, int high) {
    // Choosing the rightmost element as the pivot
    int pivot = arr[high];
    
    // Initializing the index of the smaller element
    int i = (low - 1);

    // Iterating through the array
    for (int j = low; j <= high - 1; j++) {
        // Checking if current element is smaller or equal to the pivot
        if (arr[j] <= pivot) {
            // Then, swapping arr[i] and arr[j]
            swap(&arr[i], &arr[j]);
            i++;
        }
    }

    // Swaping arr[i + 1] and arr[high]. This puts the pivot in its correct position.
    swap(&arr[i + 1], &arr[high]);

    // Returning the index of the pivot
    return (i + 1);
}

// The main quick sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Finding the pivot element.
        // Elements smaller than the pivot are on the left and elements greater than the pivot are on the right
        int pivot = partition(arr, low, high);

        // Recursively sorting elements before and after the pivot
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}


// Heap Sort
// Heapify a subtree with root node i and n being the size of the array
void heapify(int arr[], int n, int i) {
    int largest = i;  // Initialize the largest element as the root
    int left = 2 * i + 1;  // Index of the left child
    int right = 2 * i + 2;  // Index of the right child

    if (left < n && arr[left] > arr[largest]) // If the left child is larger than the root
        largest = left;

    if (right < n && arr[right] > arr[largest]) // If the right child is larger than the largest so far
        largest = right;
    
    if (largest != i) { // If the largest element is not the root
        // Swapping the largest element with the root
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Function to perform the Heap Sort
void heapSort(int arr[], int n) {
    // Building a max-heap from the array
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extracting elements one by one from the heap
    for (int i = n - 1; i > 0; i--) {
        // Swaping the current root with the last element in the heap
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Calling heapify on the reduced heap (exclude the sorted elements)
        heapify(arr, i, 0);
    }
}


int main() {
    int n = 50000;
    int arr1[n], arr2[n], arr3[n];

    for (int i = 0; i < n; i++) {
        int val = rand() % n;
        arr1[i] = val;
        arr2[i] = val;
        arr3[i] = val;
    }

    clock_t start, end;
    double timetaken;

    // Merge Sort
    start = clock();
    mergeSort(arr1, 0, n - 1);
    end = clock();
    timetaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Merge sort was executed in %f seconds\n", timetaken);

    // Quick Sort
    start = clock();
    quickSort(arr2, 0, n - 1);
    end = clock();
    timetaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Quick sort was executed in %f seconds\n", timetaken);

    // Heap Sort
    start = clock();
    heapSort(arr3, n);
    end = clock();
    timetaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Heap sort was executed in %f seconds", timetaken);

    return 0;
}
