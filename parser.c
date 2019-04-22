#include<stdio.h>
#include<iostream>
#include"parser.h"
#include"scanner.h"
#include"token.h"

using namespace std;

int i;
Token token;

node_t* parser(vector<Token> tokens)
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

node_t* program(vector<Token> tokens)
{
	vars(tokens);
	block(tokens);
}

node_t* vars(vector<Token> tokens)
{
	if(token.id == INT_tk)
	{
		i++;
		token = tokens[i];

		if(token.id == IDENT_tk)
		{
			i++;
			token = tokens[i];

			if(token.id == NUM_tk)
			{
				i++;
				token = tokens[i];
				vars(tokens);
				return;
			}
			else
			{

			}
		}
		else
		{

		}
	}
	else //predicts empty
	{
		return;
	}
}

node_t* block(vector<Token> tokens)
{
	if(token.id == BEGIN_tk)
	{
		i++;
		token = tokens[i];
		vars(tokens);
		stats(tokens);

		if(token.id = END_tk)
		{
			i++;
			token = tokens[i];
			return;
		}

	}
	else
	{

	}
}

node_t* expr(vector<Token> tokens)
{
	A(tokens);
	if(token.id == ADDITION_tk)
	{
		i++;
		token = tokens[i];
		expr(tokens);
		return;
	}
	else if(token.id == SUBTRACTION_tk)
	{
		i++;
		token = tokens[i];
		expr(tokens);
		return;
	}
	else
	{

	}
}

node_t* A(vector<Token> tokens)
{
	N(tokens);
	if(token.id == MULTIPLY_tk)
	{
		i++;
		token = tokens[i];
		A(tokens);
		return;
	}
	else
	{

	}
}

node_t* N(vector<Token> tokens)
{
	M(tokens);
	if(token.id == DIVIDE_tk)
	{
		i++;
		token = tokens[i];
		N(tokens);
		return;
	}
	else
	{

	}
}

node_t* M(vector<Token> tokens)
{
	if(token.id == SUBTRACTION_tk)
	{
		i++;
		token = tokens[i];
		M(tokens);
		return;
	}	
	else
	{
		R(tokens);
		return;
	}
}

node_t* R(vector<Token> tokens)
{
	if(token.id == OPEN_BRACKET_tk)
	{
		i++;
		token = tokens[i];
		expr(tokens);
		
		if(token.id == CLOSE_BRACKET_tk)
		{
			i++;
			token = tokens[i];
			return;
		}
	}
	else if(token.id == IDENT_tk)
	{
		return;
	}
	else if(token.id == NUM_tk)
	{	
		return;
	}
	else
	{
	
	}	
}

node_t* stats(vector<Token> tokens)
{
	stat(tokens);

	if(token.id == COLON_tk)
	{
		i++;
		token = tokens[i];
		mStat(tokens);
		return;
	}
	else
	{

	}
}

node_t* mStat(vector<Token> tokens)
{
	stat(tokens);

        if(token.id == COLON_tk)
        {
                i++;
                token = tokens[i];
                mStat(tokens);
                return;
        }
        else //process empty
        {

        }
}

node_t* stat(vector<Token> tokens)
{
	in(tokens);
        out(tokens);
        block(tokens);
        if_tk(tokens);
        loop(tokens);
        assign(tokens);
}

node_t* in(vector<Token> tokens)
{
	if(token.id == READ_tk)
	{
		i++;
		token = tokens[i];

		if(token.id == OPEN_BRACKET_tk)
		{
			i++;
			token = tokens[i];

			if(token.id == IDENT_tk)
			{
				i++;
				token = tokens[i];

				if(token.id == CLOSE_BRACKET_tk)
				{
					i++;
					token = tokens[i];
					return;
				}
			}
		}
	}
	else
	{

	}
}

node_t* out(vector<Token> tokens)
{
	if(token.id == OUTPUT_tk)
	{
		i++;
		token = tokens[i];		

		if(token.id == OPEN_BRACKET_tk)
		{
			i++;
			token = tokens[i];
			expr(tokens);
	
			if(token.id == CLOSE_BRACKET_tk)
			{
				return;
			}
		}	
	}
	else
	{

	}
}

node_t* if_tk(vector<Token> tokens)
{
	if(token.id == IFF_tk)
	{
		i++;
		token = tokens[i];
		
		if(token.id == OPEN_BRACKET_tk)
		{
			i++;
			token = tokens[i];
			expr(tokens);
			RO(tokens);
			expr(tokens);
		
			if(token.id == CLOSE_BRACKET_tk)
			{
				stat(tokens);
				return;
			}
		}
	}
	else
	{

	}
}

node_t* loop(vector<Token> tokens)
{
	if(token.id == LOOP_tk)
	{
		i++;
		token = tokens[i];

		if(token.id == OPEN_BRACKET_tk)
		{
			expr(tokens);
			RO(tokens);
			expr(tokens);

			if(token.id == CLOSE_BRACKET_tk)
			{
				i++;
				token = tokens[i];
				stat(tokens);
				return;
			}
		}
	}	
	else
	{

	}
}

node_t* assign(vector<Token> tokens)
{
	if(token.id == IDENT_tk)
	{
		i++;
		token = tokens[i];

		if(token.id == EQUAL_tk)
		{
			i++;
			token = tokens[i];
			expr(tokens);
			return;
		}
	}
	else
	{

	}
}

node_t* RO(vector<Token> tokens)
{
	if(token.id == LESS_tk)
	{
		return;
	}
	else if(token.id == EQUAL_tk)
	{
		i++;
		token = tokens[i];

		if(token.id == LESS_tk)
		{

		}
		else if(token.id == GREATER_tk)
		{

		}
		else if(token.id == EQUAL_tk)
		{

		}
		else
		{

		}
	}
	else if(token.id == GREATER_tk)
	{
		
	}
	else
	{

	}
}
