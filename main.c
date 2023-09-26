#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *collectUserInput(const char *prompt) {
    char *userinput = malloc(1); // Starting with an empty string to avoid core dump
    if (userinput == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    userinput[0] = '\0'; // Null-terminating the string to avoid core dump

    size_t buffersize = 128; // generous starting buffer size
    size_t length = 0;

    printf("%s:\n", prompt);
    while (1) {
        int c = getchar();  //collects user characters 1 at a time
        if (c == EOF || c == '\n') {
            break; // Exits the loop when Enter is pressed
        }

        if (length == buffersize - 1) { //allocates more memory if the user input is larger than current allocated memory
            buffersize *= 2;
            char *temp = realloc(userinput, buffersize);  //reallocates userinput to the buffer size
            if (temp == NULL) {  // returns error for failed allocation and frees memroy
                printf("Memory allocation failed\n");
                free(userinput);
                return NULL;
            }
            userinput = temp;
        }
        userinput[length++] = c;  //setting each part of userinput to the current typed character
        userinput[length] = '\0'; // Null-terminate after each character
    }

    return userinput;
}
