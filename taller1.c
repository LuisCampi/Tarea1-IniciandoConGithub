#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXLINE 1000
#define IN 1
#define OUT 0

/* maximum input line length */
int getline2(char line[], int maxline);
void copy(char to[], char from[]);

/* counting words number */
void contadorPalabras(char longest[]);
/* counting digits number */
void contadorNumeros(char longest[]);

// print the longest input
int main()
{
	int len, max, op;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while ((len = getline2(line, MAXLINE)) > 0)
	{
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}

	if (max > 0) /* there was a line */
		printf("La cadena mas larga de todas las cadenas ingresadas es: %s", longest);
	
	printf("SELECCIONE UNA OPCION: \n1)CONTADOR DE PALABRAS DE LA CADENA MAS LARGA.\n");
	printf("2)CONTADOR DE DIGITOS DE LA CADENA MAS LARGA.\n3)SALIR.");
	fflush(stdout);
	scanf("%d", &op);
	switch(op)
	{
		case 1:
			contadorPalabras(longest);
			break;
		case 2:
			if (max > 0) /* there was a line */
			contadorNumeros(longest);
			break;
		case 3:
			printf("PROGRAMA FINALIZADO!");
			break;
	}
		
	return 0;
	
}

//getline: read a line into s, return length
int getline2(char s[],int lim)
{
	int c, i;
	for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}

void contadorPalabras(char longest[])
{
	int c, nw, state, i;
	state = OUT;
	nw = i = 0;
	for(i=0;i<strlen(longest);i++)
	{
		c = longest[i];
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT) {
			state = IN;
			++nw;
		}
	}
	printf("Numero de palabras en la cadena evaluada: %d\n", nw);	
}

void contadorNumeros(char longest[])
{
	int c, digits, state, i;
	state = OUT;
	digits = i = 0;
	for(i=0;i<strlen(longest);i++)
	{
		c = longest[i];
		if (isdigit(c))
			digits++;
	}
	printf("Numero de digitos en la cadena evaluada: %d\n", digits);	
}


