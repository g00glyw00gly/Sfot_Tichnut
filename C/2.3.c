# include <stdio.h>
# define MAXSIZE 100
# define LOWER_DIFF 87
# define UPPER_DIFF 55
# define NUM_DIFF '0'
# define FIRST_CHAR  0
# define SECOND_CHAR  1

/*
Written by: Ori P
Date: 19/02/23

This code recives a string which represents a hexadecimal number,
 then it converts it to decimal integer and prints the result.
*/

int htoi(char s[]);
void getline(char line[], int maxline);

int main()
{
    char s[MAXSIZE];
	
	printf("Enter hexadecimal number --> ");
	getline(s, MAXSIZE);
    printf("decimal value is --> %d", htoi(s));
}

int htoi(char s[]) {
    // This function converts a string that represents a hex number to dec int.
	int i, n;
    n = 0;
	
	// This loop goes over every char in the string and converts it to decimal numbers.
	// The long condtion part of the loop makes sure that the chars are in hexadecimal: a-f/A-F/0-9. 
    for (i = 0; (s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'f') || (s[i] >= 'A' && s[i] <= 'F'); ++i)
		
		// Checks for the prefix "0X/0x" so the function won't convert the first char to decimal.
		if(s[i] == '0' && i == FIRST_CHAR){
			++i;
		}
		
		// Checks for the prefix "0X/0x" so the function won't convert the second char to decimal.
		else if((s[i] == 'x' || s[i] == 'X') && i == SECOND_CHAR){
			++i;
		}
		
		// Seperates between the types of hex chars: numbers/lowercase/uppercase.
		else if (s[i] >= '0' && s[i] <= '9') {
            n = 16 * n + (s[i] - NUM_DIFF);
        }
        else if (s[i] >= 'a' && s[i] <= 'f') {
            n = 16 * n + (s[i] - LOWER_DIFF);
        }
        else if (s[i] >= 'A' && s[i] <= 'F') {
            n = 16 * n + (s[i] - UPPER_DIFF);
        }
		return n;
    }
	

void getline(char s[], int maxsize){
	// This function reads a line of characters and converts it to string.
	int c, i;
	
	//
	for (i = 0; i<maxsize-1 && (c = getchar()) != EOF && c != '\n'; ++i){
		s[i] = c;
	}
	
	//
	if (c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';
}
