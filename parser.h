#include<stdio.h>
#include<iostream>
#include<vector>
#include"token.h"
#ifndef PARSER_H
#define PARSER_H

using namespace std;

//Struct delcaractions.
struct node_t {
string label;
Token token1;
Token token2;
Token child;
};

//Function prototypes.
node_t* parser(vector<Token>);
node_t* program(vector<Token>);
node_t* vars(vector<Token>);
node_t* block(vector<Token>);
node_t* expr(vector<Token>);
node_t* A(vector<Token>);
node_t* N(vector<Token>);
node_t* M(vector<Token>);
node_t* R(vector<Token>);
node_t* stats(vector<Token>);
node_t* mStat(vector<Token>);
node_t* stat(vector<Token>);
node_t* in(vector<Token>);
node_t* out(vector<Token>);
node_t* if_tk(vector<Token>);
node_t* loop(vector<Token>);
node_t* assign(vector<Token>);
node_t* RO(vector<Token>);
node_t* getNode(string);

#endif
