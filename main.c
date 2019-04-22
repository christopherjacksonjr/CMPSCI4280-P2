#include<stdio.h>
#include<string.h>
#include<iostream>
#include<string>
#include<fstream>
#include"token.h"
#include"scanner.h"
#include"parser.h"

int main(int argc, char* argv[])
{
	//Setting variables.
	FILE *fp;
	int c;
	string buffer;
	node_t* node;

	vector<Token> tokens;

	//Error if the user invokes with more than 2 command line arguments.
	if(argc > 2)
	{
		perror("Error: too many arguments.\n");	
	}
	
	//Set up keyboard processing so that below the input is not relevant.
	if(argc < 2)
	{	
		//Setting fp for stdin keyboard entry.
		fp = stdin;
		
		do {
		c = getc(fp);
		buffer.append(1, c);
		} while (c != EOF);
		
		//Calling scanner function then parse function.
		tokens = scanner(buffer);
		node = parser(tokens);

		fclose(fp);
	}

	//Process command line arguments and make sure file is readable, error otherwise.
	if(argc == 2)
	{
		//Setting variables.
		char* filename = argv[1];

		//Opening file & error checking.
		fp = fopen(filename, "r");

		if(fp == NULL)
		{
			printf("Program error file %s not found.\n", filename);
			return 1;
		}
		else
		{
			do {
			c = getc(fp);
			buffer.append(1, c);
			} while (c != EOF);

			//Calling scanner function then parse function.
			tokens = scanner(buffer);
			node = parser(tokens);

			fclose(fp);
		}
	}

	return 0;
}

