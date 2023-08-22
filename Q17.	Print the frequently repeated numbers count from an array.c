#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 2, 4, 2, 4}; // Example array
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > 1) {
            printf("Number %d is repeated %d times.\n", arr[i], count);
        }
    }

    return 0;
}
