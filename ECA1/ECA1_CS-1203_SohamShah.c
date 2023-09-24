#include <stdio.h>

// Function to swap two elements in an array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to reverse an array from start to end
void reverse(int arr[], int start, int end) {
    while (start < end) {
        swap(&arr[start], &arr[end]);
        start++;
        end--;
    }
}

// Function to generate the next permutation
int nextPermutation(int arr[], int n) {
    int i = n - 2;
    
    // Find the first element (i) that is less than the element to its right (i+1)
    while (i >= 0 && arr[i] >= arr[i + 1]) {
        i--;
    }
    
    if (i < 0) {
        // If no such element is found, the array is in descending order, and it's the last permutation.
        return 0;
    }
    
    // Find the smallest element to the right of i and greater than arr[i]
    int j = n - 1;
    while (arr[j] <= arr[i]) {
        j--;
    }
    
    // Swap arr[i] and arr[j]
    swap(&arr[i], &arr[j]);
    
    // Reverse the elements to the right of i
    reverse(arr, i + 1, n - 1);
    
    return 1;
}

int main() {
    int number;
    printf("Enter an integer (<= 8): ");
    scanf("%d", &number);
    
    if (number <= 0 || number > 8) {
        printf("Invalid input. Please enter a valid value of n.\n");
        return 1;
    }
    
    int arr[number];
    for (int i = 0; i < number; i++) {
        arr[i] = i + 1; // Initialize the array with 1 to n
    }
    
    do {
        // Print the current permutation
        for (int i = 0; i < number; i++) {
            printf("%d", arr[i]);
            if (i < number - 1) {
                printf(",");
            }
        }
        printf("\n");
    } while (nextPermutation(arr, number));
    
    return 0;
}
