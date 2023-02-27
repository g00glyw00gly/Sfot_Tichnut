# include <stdio.h>
# include <string.h>
# include <ctype.h>
# define MAXSIZE 1000
# define INT "int"
# define swap(t,x,y) {t temp; temp = x; x = y; y = temp;}


/*
Name: 4.14.c
Written by: Ori P
Date: 26/02/23

This code takes a data type and two variables as input, 
then interchange their values using macro and prints the result.  
*/

int getline(char s[], int maxsize);
int atoi_book(char s[]);
double atof_book(char s[]);

int main() {
	char str_dtype[MAXSIZE],str_arg1[MAXSIZE], str_arg2[MAXSIZE];

	printf("Enter data type --> ");
	getline(str_dtype, MAXSIZE);
	printf("Enter value of 1st argument --> ");
	getline(str_arg1, MAXSIZE);
	printf("Enter value of 2nd argument --> ");
	getline(str_arg2, MAXSIZE);
	
	printf("\n~~~Values Have Been Interchanged~~~\n\n");
	
	// Checks which data type the user entered to send the proper arguments to swap().
	if (!strcmp(str_dtype, "int")) { 
		int arg1 = atoi_book(str_arg1);
		int arg2 = atoi_book(str_arg2);
		swap(int, arg1, arg2);
		printf("Value of 1st argument --> %d\n", arg1);
		printf("Value of 2nd argument --> %d", arg2);

	}	
	else if (!strcmp(str_dtype, "float")) {
		float arg1 = atof_book(str_arg1);
		float arg2 = atof_book(str_arg2);
		swap(float, arg1, arg2);
		printf("Value of 1st argument --> %f\n", arg1);
		printf("Value of 2nd argument --> %f", arg2);
		
	}
	else if (!strcmp(str_dtype, "char")) {
		char arg1 = str_arg1[0];
		char arg2 = str_arg2[0];
		swap(char, arg1, arg2);
		printf("Value of 1st argument --> %c\n", arg1);
		printf("Value of 2nd argument --> %c", arg2);
	}
	else if (!strcmp(str_dtype, "double")) {
		double arg1 = atof_book(str_arg1);
		double arg2 = atof_book(str_arg2);
		swap(double, arg1, arg2);
		printf("Value of 1st argument --> %f\n", arg1);
		printf("Value of 2nd argument --> %f", arg2);
	}
	
	else {
		printf("Data type doesn't exists");
		return 0;
	}
}

int getline(char s[], int lim){
	/* This function reads a line of input from user, 
	 saves it as string, and returns it's length. */
    int c, i;
	
	// Addes each char to the string with getchar().
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
	// Omitting the '\n' thats happening when the user presses ENTER.
    if (c == '\n') {
         s[i] = '\0';
    }   
    return i;
}

int atoi_book(char s[]) {
	// This function converts string s to integer and returns it.

	int i, n;

	n = 0;
	
	// Calculate the number digit by digit with formula.
	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i) {
		n = 10 * n + (s[i] - '0');
	}
	return n;
}

double atof_book(char s[]){
	// This function Converts string s to double and returns it.
	
	double val, power;
	int i, sign;
	
	// skip white space
	for( i = 0; isspace(s[i]); i++){
		;
	}
	
	// Check if number is positive/negetive.
	sign  = (s[i] == '-') ? -1 : 1;
	if(s[i] == '+' || s[i] == '-'){
		i++;
	}
	
	// Calculate the number digit by digit with formula until there is a '.'
	for(val = 0.0; isdigit(s[i]); i++){
		val = 10.0 * val + (s[i] - '0' );
	}
	
	// Doesn't Calculate the decimal point 
	if(s[i] == '.'){
		i++;
	}
	
	// Calculate the number digit by digit with formula.
	for(power = 1.0; isdigit(s[i]); i++){
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	return sign * val / power;
}