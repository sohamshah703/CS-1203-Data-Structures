#include <stdio.h>
#include <stdbool.h>

// Recusrive function that moves a disk from source pole to destination pole
void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    towerOfHanoi(n - 1, source, destination, auxiliary);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n); // Input the number of disks

    towerOfHanoi(n, 'A', 'B', 'C'); // A, B, and C are the names of the poles
    return 0;
}
