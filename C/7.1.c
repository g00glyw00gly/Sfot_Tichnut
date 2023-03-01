# include <stdio.h>
# include <ctype.h>
# include <string.h>
# define LOWER "7.1.exe"
# define UPPER "7.1.EXE"

/*
Name: 7.1.c
Written by: Ori P
Date: 28/02/23

This code prints text with putchar() in lower/upper case.
It changes accroding to the suffix that is saved in argv[0] (exe/EXE).
*/

int main(int argc, char *argv[]) {
	printf("Run as '%s' / '%s' to print chars in upper/lower case.\nEnter ^Z to exit\n\n", UPPER, LOWER);
	int c;
	
	printf("Enter text --> ");
	
	while (( c = getchar()) != EOF){
		if(c == '\n'){
			putchar(c);
			printf("Enter text --> ");
		}
		else if(strcmp(argv[0], LOWER) == 0){
			putchar(tolower(c));
		}
		else if( strcmp(argv[0], UPPER) == 0){
			putchar(toupper(c));
		}
	}
	return 0;
}