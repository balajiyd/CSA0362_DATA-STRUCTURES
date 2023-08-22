#include <stdio.h>
#include <string.h>

int main() {
    char input[] = "programming"; // Example string
    int n = strlen(input);

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (i != j && input[i] == input[j]) {
                count++;
            }
        }
        if (count > 0) {
            printf("Character '%c' is repeated at index %d.\n", input[i], i);
        }
    }

    return 0;
}
