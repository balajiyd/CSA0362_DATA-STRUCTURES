#include <stdio.h>

int main() {
    int matrix[3][3] = {
        {5, 12, 9},
        {7, 15, 4},
        {8, 3, 11}
    }; // Example 2D matrix
    int rows = 3;
    int cols = 3;
    int largest = matrix[0][0];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] > largest) {
                largest = matrix[i][j];
            }
        }

    }

    printf("The largest element is: %d\n", largest);

    return 0;
}
