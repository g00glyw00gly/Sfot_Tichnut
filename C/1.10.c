#include <stdio.h>
#define SPACE 32

/*
Written by: Ori P
Date: 19/02/23

This script recives input of string, replaces 
tabs/backspaces/backslash with their escape sequences, 
and pastes the new string. 
*/

int main()
{
    int input = getchar();

    // Go over all chars/strings until EOF is inputted.
    while (input != EOF) {

        // Check if string contains a tab
        if (input == '\t') {
            printf("\\t");
        }

        // Check if there is a space, because \b prints as space
        else if (input == SPACE || input == '\b') {
            printf("\\b");
        }

        // Check if there is a backslash
        else if (input == '\\') {
            printf("\\\\");
        }

        // Prints all other chars noramlly 
        else {
            putchar(input);
        }
        
        input = getchar();
    }
}