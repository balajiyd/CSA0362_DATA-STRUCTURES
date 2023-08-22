#include <stdio.h>

int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid; // Element found at index mid
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Element not found
}

int main() {
    int arr[] = {10, 25, 30, 45, 50, 65}; // Example sorted array
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 45;

    int index = binarySearch(arr, 0, n - 1, target);
    if (index != -1) {
        printf("Element %d found at index %d.\n", target, index);
    } else {
        printf("Element %d not found.\n", target);
    }

    return 0;
}
