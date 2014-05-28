/*
Abstract Syntax Tree Implementation of
Simple Arithmetic Expression
Kim Chesed Paller , BSEC5
MSUIIT-SCS | CS Department
CSC153 Lab03
*/

#include<stdio.h>
#include<stdlib.h>
#include "Ast.h"


Tree makeNode(TOKEN tok, Tree l_pointer,Tree r_pointer){
	Tree temp = (Tree)malloc(sizeof(Node));
	if(temp == NULL){
		exit(-1);
	}
	temp->left = l_pointer;
	temp->right = r_pointer;
	temp->data = tok;
	return temp;
}

Tree makeLeaf(TOKEN tok){
	Tree temp = (Tree)malloc(sizeof(Node));
	if(temp == NULL){
		exit(-1);
	}
	temp->data = tok;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void showTree(Tree T,int space){
	int i;
	Tree temp = T;
	if(temp!=NULL){
		showTree(temp->right,space + 6);
		for(i=0;i<space;i++){
			printf(".");
		}
		displayToken(temp->data);
		showTree(temp->left,space + 6);
	}
	printf("\n");
}

void preorder(Tree T){
	Tree temp = T;
	if(temp != NULL){
		displayChar(temp->data);
		preorder(temp->left);
		preorder(temp->right);
	}
}

void postorder(Tree T){
	Tree temp = T;
	if(temp != NULL){
		postorder(temp->left);
		postorder(temp->right);
		displayChar(temp->data);
	}
}


void inorder(Tree T){
	Tree temp = T;
	if(temp != NULL){
		inorder(temp->left);
		displayChar(temp->data);
		inorder(temp->right);
	}
}

/*
void main(){
	TOKEN t1={4,12};
	TOKEN t2={4,37};
	TOKEN t3={1,2};
	TOKEN t4={1,3};
	TOKEN t5={4,190};
	Tree tL = makeLeaf(t1);
	Tree tR = makeLeaf(t2);
	Tree tH = makeNode(t3,tL,tR);
	Tree tR1 = makeLeaf(t5);
	Tree tH1 = makeNode(t4,tH,tR1);
	showTree(tH1,0);

}
*/

