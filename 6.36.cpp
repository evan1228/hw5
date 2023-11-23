#include <stdio.h>

// Function prototype
void stringReverse(char str[], int index);

int main() {
    char inputString[100]; // Assuming maximum string length is 100 characters

    // Get user input
    printf("Enter a string: ");
    fgets(inputString, sizeof(inputString), stdin);

    // Remove the newline character from fgets
    int length = 0;
    while (inputString[length] != '\0' && inputString[length] != '\n') {
        length++;
    }
    inputString[length] = '\0';

    // Call the recursive function to print the string backward
    printf("String in reverse: ");
    stringReverse(inputString, 0);

    return 0;
}

// Recursive function to print string backward
void stringReverse(char str[], int index) {
    // Base case: stop when the null character is encountered
    if (str[index] == '\0') {
        return;
    }

    // Recursive call to print the rest of the string backward
    stringReverse(str, index + 1);

    // Print the current character
    printf("%c", str[index]);
}
