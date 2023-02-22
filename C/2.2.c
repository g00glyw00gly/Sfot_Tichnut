# include <stdio.h>
# define MAXSIZE 1000

/*
Name: 2.2.c
Written by: Ori P
Date: 19/02/23

This code takes a loop from the book and does the
same thing without "&&" and "||". 

Said loop: i < lim - 1 && (c = getchar()) != '\n' && c != EOF 

*/

int getline(char line[], int maxline);


int main(){
	char s[MAXSIZE];
	int count = getline(s, MAXSIZE);
	printf("The string is: %s. It's length is: %d.", s, count);
}

int getline(char s[], int maxsize){
	// This function reads a line of characters and converts it to string.
	int c, i;
	
	// The said loop. takes chars as input until '\n' or EOF are inputted.
	for (i = 0; (c = getchar()) != '\n'; ++i){
		
		// Checks if the current number of chars are less than the max size allowed.
		if(i < maxsize-1){
			
			// Checks if the user isn't stopping the run of the function with EOF.
			if(c != EOF){
				s[i] = c;
			}
		}	
	}
	s[i + 1] = '\0';
	return i;
}