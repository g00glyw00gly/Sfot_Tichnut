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
	printf("%s", s);
	//printf("The string is: %s. It's length is (including '\\0'): %d.", s, count);
}

int getline(char s[], int maxsize){
	// This function reads a line of characters and converts it to string.
	int c, i;
	
	// The said loop. takes chars as input until '\n' or EOF are inputted.
	for (i = 0; (c = getchar()) != '\n'; ++i){
		//printf("%c - %c\n", c, s[i]);
		//
		if(i < maxsize-1){
			
			//
			if(c != EOF){
				s[i] = c;
				printf("%c - %c\n", c, s[i]);
			}
		}	
	}
	++i;
	s[i] = '\0';
	printf("%d\n",s[i]);
	return i;
}