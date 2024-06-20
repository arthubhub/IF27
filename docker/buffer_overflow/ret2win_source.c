#include <stdio.h>

// The function that we want to execute
void win() {
    printf("You have successfully executed the win function!\n");
}

// A vulnerable function
void vulnerable() {
    char buffer[64];
    printf("Enter some text: ");
    gets(buffer);  // This function is unsafe and allows for buffer overflow
}

int main() {
    printf("Welcome to the ret2win challenge!\n");
    vulnerable();
    printf("Goodbye!\n");
    return 0;
}

