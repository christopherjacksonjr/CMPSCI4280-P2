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
		return NULL;
	}
	else
	{
		error("Error: Expected EOF token.");
		return NULL;
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
				return NULL;
			}
			else
			{
				error("Error: Expected NUMBER token.");
			}
		}
		else
		{
			error("Error: Expected IDENTIFIER token.");
		}
	}
	else //predicts empty
	{
		return NULL;
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
			return NULL;
		}
		else
		{
			error("Error: Expected END token.");
		}

	}
	else
	{
		error("Error: Expected BEGIN token.");
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
		return NULL;
	}
	else if(token.id == SUBTRACTION_tk)
	{
		i++;
		token = tokens[i];
		expr(tokens);
		return NULL;
	}
	else
	{
		return NULL;
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
		return NULL;
	}
	else
	{
		return NULL;
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
		return NULL;
	}
	else
	{
		return NULL;
	}
}

node_t* M(vector<Token> tokens)
{
	if(token.id == SUBTRACTION_tk)
	{
		i++;
		token = tokens[i];
		M(tokens);
		return NULL;
	}	
	else
	{
		R(tokens);
		return NULL;
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
			return NULL;
		}
		else
		{
			error("Error: Expected CLOSE BRACKET token.");
		}
	}
	else if(token.id == IDENT_tk)
	{
		i++;
		token = tokens[i];
		return NULL;
	}
	else if(token.id == NUM_tk)
	{	
		i++;
		token = tokens[i];
		return NULL;
	}
	else
	{
		error("Error: Expected OPEN BRACKET, IDENTIFIER, or NUMBER token");
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
		return NULL;
	}
	else
	{
		error("Error: Expected COLON token.");
	}
}

node_t* mStat(vector<Token> tokens)
{
	if(token.id == END_tk)
	{
		return NULL;
	}
	
	stat(tokens);

        if(token.id == COLON_tk)
        {
                i++;
                token = tokens[i];
                mStat(tokens);
                return NULL;
        }
        else //process empty
        {
		
        }
}

node_t* stat(vector<Token> tokens)
{
	/*in(tokens);
        out(tokens);
        block(tokens);
        if_tk(tokens);
        loop(tokens);
        assign(tokens);*/

	switch(token.id)
	{
		case READ_tk:
			i++;
			token = tokens[i];
			in(tokens);
			break;
		case OUTPUT_tk:
			i++;
                        token = tokens[i];
                        out(tokens);
                        break;
		case BEGIN_tk:
			i++;
                        token = tokens[i];
                        block(tokens);
                        break;
		case IFF_tk:
			i++;
                        token = tokens[i];
                        if_tk(tokens);
                        break;
		case LOOP_tk:
			i++;
                        token = tokens[i];
                        loop(tokens);
                        break;
		case IDENT_tk:
			i++;
                        token = tokens[i];
                        assign(tokens);
                        break;
		default:
			error("Error: Expected READ, OUTPUT, BLOCK, IFF, LOOP, or IDENTIFIER token.");
			break;
	}
}

node_t* in(vector<Token> tokens)
{
	/*if(token.id == READ_tk)
	{
		i++;
		token = tokens[i];*/

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
					return NULL;
				}
				else
				{
					error("Error: Expected CLOSE BRACKET token.");
				}
			}
			else
			{
				error("Error: Expected IDENTIFIER token.");
			}
		}
		else
		{
			error("Error: Expected OPEN BRACKET token.");
		}
}

node_t* out(vector<Token> tokens)
{
	/*if(token.id == OUTPUT_tk)
	{
		i++;
		token = tokens[i];*/		

		if(token.id == OPEN_BRACKET_tk)
		{
			i++;
			token = tokens[i];
			expr(tokens);	

			if(token.id == CLOSE_BRACKET_tk)
			{
				i++;
				token = tokens[i];
				return NULL;
			}
			else
			{
				error("Error: Expected CLOSE BRACKET token.");
			}
		}
		else
		{
			error("Error: Expected OPEN BRACKET token.");
		}	
}

node_t* if_tk(vector<Token> tokens)
{
	/*if(token.id == IFF_tk)
	{
		i++;
		token = tokens[i];*/
		
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
				return NULL;
			}
			else
			{
				error("Error: Expected CLOSE BRACKET token.");
			}
		}
		else
		{
			error("Error: Expected OPEN BRACKET token.");
		}
}

node_t* loop(vector<Token> tokens)
{
	/*if(token.id == LOOP_tk)
	{
		i++;
		token = tokens[i];*/

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
				return NULL;
			}
			else
			{
				error("Error: Expected CLOSE BRACKET token.");
			}
		}
		else
		{
			error("Error: Expected OPEN BRACKET token.");
		}
}

node_t* assign(vector<Token> tokens)
{
	/*if(token.id == IDENT_tk)
	{
		i++;
		token = tokens[i];*/

		if(token.id == EQUAL_tk)
		{
			i++;
			token = tokens[i];
			expr(tokens);
			return NULL;
		}
		else 
		{
			error("Error: Expected EQUAL token.");
		}
}

node_t* RO(vector<Token> tokens)
{
	if(token.id == LESS_tk)
	{
		return NULL;
	}
	else if(token.id == EQUAL_tk)
	{
		i++;
		token = tokens[i];

		if(token.id == LESS_tk)
		{
			i++;
			token = tokens[i];
			return NULL;
		}
		else if(token.id == GREATER_tk)
		{
			i++;
			token = tokens[i];
			return NULL;
		}
		else if(token.id == EQUAL_tk)
		{
			i++;
			token = tokens[i];
			return NULL;
		}
	}
	else if(token.id == GREATER_tk)
	{
		i++;
		token = tokens[i];
		return NULL;
	}
	else
	{
		error("Error: Expected LESS THAN, EQUAL, or GREATER THAN token.");
	}
}

void error(string message)
{
	cout << message << endl;
	exit(1);
}
