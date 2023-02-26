# include <stdio.h>
# define MAXLINE 1000
# define STR_SUFFIX 2

/*
Name: 4.13.c
Written by: Ori P
Date: 19/02/23

This code takes the function reverse and executes it recursivly. 
*/

int getline(char line[], int maxline);
void reverse(char to[], char from[], int len, int index);

int main()
{
    int len;
	int index = 0;
    char line[MAXLINE];
    char reversed[MAXLINE];
	
	
	printf("Enter a string (to exit enter ctrl + Z)--> ");
    while ((len = getline(line, MAXLINE)) > 0) {
        reverse(reversed, line, len, index);
		printf("Enter a string (to exit enter ctrl + Z)--> ");
    }
    
    return 0;
}

int getline(char s[], int lim){
	/* This function reads a line of input from user, 
	 saves it as string, and returns it's length. */
    int c, i;
	
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
         s[++i] = '\0';
    }   
    return i;
}

void reverse(char to[], char from[], int len, int index){
	// This function copies the string in reverse.
	
	//Checks if the function went over the whole string to stop the recursion.
	if(index >= len - 1){
		to[index] = '\0';
		printf("reversed string --> %s\n", to);
	}
	else {
		to[index] = from[len - STR_SUFFIX - index];
		reverse(to, from, len, ++index);
	}
	
}