# include <stdio.h>
# include <ctype.h>
# define BUFSIZE 100

/*
Name: 5.2.c
Written by: Ori P
Date: 27/02/23

This code gets input from user as an int (with getchar()),
and converts it to floating-point using getfloat() function.
*/

// Function Declerations
float getfloat(double* pn);
int getch(void);
void ungetch(int c);

// External varaibles
char buf[BUFSIZE];
int bufp = 0;

int main() {
	double num;
	double* pn;
	pn = &num;
	
	printf("Enter a number --> ");
	getfloat(pn);
	printf("float is --> %f", num);
}

float getfloat(double* pn) {
	//get next floating-point number from input into *pn	
	float power;
	float c, sign;
	
	// Skips white spaces
	while (isspace(c = getch())) { 
		;
	}
	
	// Exit function if input is not a number.
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c); 
		return 0;
	}
	sign = (c == '-') ? -1.0 : 1.0;
	
	// Skips the minus/plus sign. 
	if (c == '+' || c == '-') {
		c = getch();
	}
	
	// Calculate the number digit by digit with formula. 
	for (*pn = 0.0; isdigit(c); c = getchar()) {
		*pn = 10.0 * *pn + (c - '0');
	}
	
	// Checks for decimal point to omit it from calculation.
	if (c == '.'){
		power = 1.0;
		c = getchar();
		
		// Continues the calculation with formula.
		while(isdigit(c)){
			*pn = 10.0 * *pn + (c - '0');
			power *= 10.0;
			c = getchar();
		}
		*pn = sign * *pn / power;
	}
	
	// Omits EOF from the buffer
	if (c != EOF) {
		ungetch(c);
	}
	return c;
}
int getch() {
	// Gets a char from the buffer (buf[]) or a new one with getchar().
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
	// Pops out a char from the buffer.
	if (bufp >= BUFSIZE) {
		printf("ungetch: too many characters\n");
	}
	else {
		buf[bufp++] = c;
	}
}
