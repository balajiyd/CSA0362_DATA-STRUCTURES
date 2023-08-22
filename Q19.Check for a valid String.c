#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    if (strlen(input) > 0) {
        printf("Valid string.\n");
    } else {
        printf("Not a valid string.\n");
    }

    return 0;
}
