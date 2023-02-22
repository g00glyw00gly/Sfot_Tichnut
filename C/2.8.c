# include <stdio.h>
# define MAXSIZE 1000

/*
Name: 2.8.c
Written by: Ori P
Date: 22/02/23

This code recives input of two numbers as an input (x and n). 
Then it converts them to integers and rotates the
integer x's bits to the right by n positions. 


*/
void getline(char s[], int maxsize);
int atoi(char s[]);
int rightrot(int x, int n);

int main(){
	
	char num[MAXSIZE];
	char bit_positions[MAXSIZE];
	printf("Enter a number: ");
	getline(num, MAXSIZE);
	printf("Enter a number of bit positions: ");
	getline(bit_positions, MAXSIZE);
	
	int x, n;
	x = atoi(num);
	n = atoi(bit_positions);
	
	printf("the result of rotating %d by %d positions to the right --> %d ", x, n, rightrot(x, n));

}

void getline(char s[], int maxsize){
	// This function reads a line of characters and converts it to string.
	int c, i;
	
	// The said loop. takes chars as input until '\n' or EOF are inputted.
	for (i = 0; i<maxsize-1 && (c = getchar()) != EOF && c != '\n'; ++i){
		s[i] = c;
	}
	
	// A check to verify that the line has ended.
	if (c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';
}

int atoi(char s[]){
	// Convert string s to integer and returns it.
	
	int i, n;
	
	n = 0;
	for(i = 0; s[i] >= '0' && s[i] <= '9'; ++i){
		n = 10 * n + (s[i] - '0');
	}
	return n;
}

int rightrot(int x, int n){
	// Rotates x's bits to the right by n positions.
	return x >> n;
}