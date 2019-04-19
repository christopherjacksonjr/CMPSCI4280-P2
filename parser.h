#include<stdio.h>
#include<iostream>
#include<vector>
#include"token.h"
#ifndef PARSER_H
#define PARSER_H

using namespace std;

void parser(vector<Token>);
void program(vector<Token>);
void vars(vector<Token>);
void block(vector<Token>);
void expr();
void A();
void N();
void M();
void R();
void stats();
void mStat();
void stat();
void in();
void out();
void if_tk();
void loop();
void assign();
void RO();

#endif
