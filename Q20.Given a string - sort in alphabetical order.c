#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    int n = strlen(input);
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (input[i] > input[j]) {
                char temp = input[i];
                input[i] = input[j];
                input[j] = temp;
            }
        }
    }

    printf("Sorted string: %s\n", input);

    return 0;
}
