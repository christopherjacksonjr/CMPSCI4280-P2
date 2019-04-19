#include<stdio.h>
#include<iostream>
#include"parser.h"
#include"scanner.h"
#include"token.h"

using namespace std;

int i;
Token token;

void parser(vector<Token> tokens)
{
	i = 0;

	token = tokens[i];
	//cout << token.instance << endl;	
	
	program(tokens);
	
	if(token.id == EOF_tk)
	{
		//Not sure what to do here.
	}
	else
	{
		//Should this be an error function or print to screen?
		//error();
		return;
	}
}

void program(vector<Token> tokens)
{
	vars(tokens);
	block(tokens);
}

void vars(vector<Token> tokens)
{

}

void block(vector<Token> tokens)
{

}

void expr()
{

}

void A()
{

}

void N()
{

}

void M()
{

}

void R()
{

}

void stats()
{

}

void mStat()
{

}

void stat()
{

}

void in()
{

}

void out()
{

}

void if_tk()
{

}

void loop()
{

}

void assign()
{

}

void RO()
{

}
