#include <stdio.h>

/**
 * Recursive function to solve Tower of Hanoi puzzle
 * @param n: Number of disks
 * @param from_rod: The rod where disks are currently located
 * @param to_rod: The rod where we want to move disks
 * @param aux_rod: The temporary rod used as a buffer
 */
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    // Base Case: If only 1 disk, move it directly
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }

    // Step 1: Move n-1 disks from 'from' to 'aux' using 'to' as buffer
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);

    // Step 2: Move the nth (largest) disk from 'from' to 'to'
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);

    // Step 3: Move the n-1 disks from 'aux' to 'to' using 'from' as buffer
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int n;
    
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Names of rods are A, B and C
    printf("The moves to solve the Tower of Hanoi with %d disks:\n", n);
    towerOfHanoi(n, 'A', 'C', 'B'); 

    return 0;
}