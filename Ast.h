#ifndef AST_H
#define AST_H

#include "Lex.h"

typedef struct node{
	struct node *left,*right;					        //contains the pointer to left and right tree respectively
	TOKEN data;								           //holds the TOKEN
}Node;


typedef Node *Tree;

Tree makeLeaf(TOKEN tok);						         //converts a token match by digit/number into a tree
Tree makeNode(TOKEN tok, Tree l_pointer,Tree r_pointer); //takes an operatorand one and two trees and return a tree
void showTree(Tree T,int space);					     //display the AST in tree form
void preorder(Tree T);							         //display a given tree in prefix notation
void postorder(Tree T);							         //display a given tree in postfix notation
void inorder(Tree T);							         //display a given tree in infix notation

#endif
