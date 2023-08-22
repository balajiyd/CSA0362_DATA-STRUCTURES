#include <stdio.h>

int main() {
    int arr1[] = {1, 2, 3};
    int arr2[] = {4, 5, 6};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int resultSize = n1 + n2;
    int result[resultSize];

    for (int i = 0; i < n1; i++) {
        result[i] = arr1[i];
    }
    for (int i = 0; i < n2; i++) {
        result[n1 + i] = arr2[i];
    }

    printf("Concatenated array: ");
    for (int i = 0; i < resultSize; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}
