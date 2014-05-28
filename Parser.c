/*
Parser for Simple Arithmetic Expression
Kim Chesed Paller , BSEC5
MSUIIT-SCS | CS Department
CSC153 Lab03
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "Ast.h"
#include "Lex.h"
#include "Parser.h"

Tree t = NULL;	//containts the Abstract Syntax Tree
nptr e = NULL;	//contains List of Tokens

void error(){
	printf("Cannot Parse Expression...\n");
	exit(-1);
}

int compareToken(TOKEN a,TOKEN b){
	if((a.type == b.type) && (a.value == b.value))
		return 1;
	else
		return 0;
}

void expect(TOKEN k){
	if(compareToken(next(e),k) == 1){
		consume(&e);
	}else{
		error();
	}
}

Tree P(void){
	Tree temp;
	TOKEN open_paran = {2,0};
	TOKEN close_paran = {2,1};

	if(next(e).type == 4){
		temp = makeLeaf(next(e));
		consume(&e);
	}else if(compareToken(next(e),open_paran) == 1){
		consume(&e);
		temp = E();
		expect(close_paran);
	}else{
		error();
	}
	return temp;

}

Tree T(void){
	Tree temp,temp1;
	temp = P();
	TOKEN times = {1,2};  // "*"
	TOKEN divide = {1,3}; // "/"
	while(compareToken(next(e),times) == 1 ||
		 compareToken(next(e),divide) == 1)
	{
		TOKEN op = next(e);
		consume(&e);
		temp1 = P();
		temp = makeNode(op,temp,temp1);
	}
	return temp;
}

Tree E(void){
	Tree temp,temp1;
	temp = T();
	TOKEN plus = {1,0};  // "+"
	TOKEN minus = {1,1}; // "-"
	while(compareToken(next(e),plus) == 1 ||
		 compareToken(next(e),minus) == 1)
	{
		TOKEN op = next(e);
		consume(&e);
		temp1 = T();
		temp = makeNode(op,temp,temp1);
	}
	return temp;

}

Tree Eparser(void){
	Tree temp;
	TOKEN end = {5,5};
	temp = E();
	expect(end);
	return temp;
}

int main(int argc, char *argv[]){

	if(argc != 2){
		printf("Sorry , Argument Invalid!\n");
		exit(-1);
	}

	char *expr = argv[1];
	printf("\nExpression:%s",expr);
	e = initLex(expr);
	displayList(e);
	t = Eparser();
	printf("ABSTRACT SYNTAX TREE :");
	showTree(t,0);
	printf("PRE-ORDER :\n");
	preorder(t);
	printf("\n\n");
	printf("POST-ORDER :\n");
	postorder(t);
	printf("\n\n");
	printf("IN-ORDER :\n");
	inorder(t);
	printf("\n\n");
	return 0;

}
