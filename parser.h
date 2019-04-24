#include<stdio.h>
#include<iostream>
#include<vector>
#include"token.h"
#ifndef PARSER_H
#define PARSER_H

using namespace std;

//Struct delcaractions.
enum NodeLabel {Program, Block, Vars, Expr, PlusExpr, MinusExpr, ALabel, MultiplicationA, NLabel, DivisionN, MLabel, SubtractionM, RLabel, Stats, MStat, Stat, In, Out, If, Loop, Assign, ROLabel};

struct Node_t {
NodeLabel label;
Token token;
Token token2;
Node_t* left_child;
Node_t* right_child;
};

//Function prototypes.
Node_t* parser(vector<Token>);
Node_t* program(vector<Token>);
Node_t* vars(vector<Token>);
Node_t* block(vector<Token>);
Node_t* expr(vector<Token>);
Node_t* A(vector<Token>);
Node_t* N(vector<Token>);
Node_t* M(vector<Token>);
Node_t* R(vector<Token>);
Node_t* stats(vector<Token>);
Node_t* mStat(vector<Token>);
Node_t* stat(vector<Token>);
Node_t* in(vector<Token>);
Node_t* out(vector<Token>);
Node_t* if_tk(vector<Token>);
Node_t* loop(vector<Token>);
Node_t* assign(vector<Token>);
Node_t* RO(vector<Token>);
Node_t* getNode(NodeLabel);
void error(string);
struct Node_t* buildTree(FILE *fp);
struct Node_t* newNode(string label);
struct Node_t* insert(struct Node_t* node, string label);

#endif
