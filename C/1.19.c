#include <stdio.h>
#define MAXLINE 1000 //

int getline(char line[], int maxline);
int reverse(char to[], char from[], int len);

main()
{
    int len;
    char line[MAXLINE];
    char reversed[MAXLINE];
	
	printf("Enter a string (to exit enter ctrl + Z):\n");
	
    while ((len = getline(line, MAXLINE)) > 0) {
            reverse(reversed, line, len);
    }
    
    return 0;
}

int getline(char s[], int lim)
{
    int c, i;

	
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i+1] = '\0';
    return i;
}

// Copies the string in reverse
int reverse(char to[], char from[], int len)
{
    
    int i = 0;
	int og_len = len;
	
	/* copy the last char (excluding '\0') to the first char of the new string,
	repeat for the length of the string */
    while ((to[i] = from[len-1]) && i <= og_len) {
        ++i;
        --len;
    }
    ++i;
    to[i] = '\0';
	
	printf("reversed string --> %s\n", to);
}