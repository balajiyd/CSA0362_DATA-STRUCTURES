#include <stdio.h>

int main() {
    int arr[] = {3, 7, 2, 8, 5}; // Example unsorted array
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 0;
    
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    
    int expectedSum = (n + 1) * (n + 2) / 2;
    int missingElement = expectedSum - sum;

    printf("The missing element is: %d\n", missingElement);

    return 0;
}
