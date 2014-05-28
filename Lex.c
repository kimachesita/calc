/*
Lexical Analyzer for simple arithmetic expressions
Kim Chesed Paller, BSEC5
MSUIIT - SCS Department
CSC153 Lab03
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Lex.h"

char binOP[] = {'+','-','*','/','\0'};
char otherOP[] = {'(',')','\0'};
char delim[] = {' ','\n','\t','\0'};
char digit[] = {'0','1','2','3','4','5','6','7','8','9','\0'};

// TOKEN NOTATION
// (0,0) -> Sentinel
// (5,5) -> END
// (1,0) -> +
// (1,1) -> -
// (1,2) -> *
// (1,3) -> /
// (2,0) -> (
// (2,1) -> )
// (3,0) -> delim
// (4,NUM) -> Number

int isInList(char *source,char c){
	int i = 0;
	int is_found = 0;
	for(i=0;i<strlen(source);i++){
		if(source[i] == c)
			is_found = 1;
	}
	return is_found;
}



nptr initLex(char *expr){

	nptr t = NULL;
	TOKEN tok;
	char *e = expr;
	int index = 0;
	char buffer[20];
	add_node(&t,makeToken(0,0));
	while(e[index] != '\0'){
		if(isInList(binOP,e[index]) == 1){
			switch(e[index]){
				case '+':
					tok = makeToken(1,0);
					break;
				case '-':
					tok = makeToken(1,1);
					break;
				case '*':
					tok = makeToken(1,2);
					break;
				case '/':
					tok = makeToken(1,3);
					break;

			}
			index++;

		}else if(isInList(otherOP,e[index]) == 1){
			switch(e[index]){
				case '(':
					tok = makeToken(2,0);
					break;
				case ')':
					tok = makeToken(2,1);
					break;
			}
			index++;

		}else if(isInList(delim,e[index]) == 1){

			tok = makeToken(3,0);
			index++;

		}else if(isInList(digit,e[index]) == 1){

			int base_index = index;
			memset(buffer,'\0',20);
			do{
				index++;

			}while(isInList(digit,e[index]) == 1);
			strncpy(buffer,e + base_index,(index - base_index));
			tok = makeToken(4,atoi(buffer));

		}else{
			printf("\n'%c' not found.Syntax Error!\n",expr[index]);
			exit(-1);
		}

	add_node(&t,tok);

	}
	add_node(&t,makeToken(5,5));
	return t;

}

TOKEN makeToken(int t,int v){

	TOKEN *ptr = (TOKEN*)malloc(sizeof(TOKEN));
	ptr->type = t;
	ptr->value = v;
	return *ptr;
}

void add_node(nptr *S,TOKEN elem){

	nptr temp = *S;
	nptr p = (nptr)malloc(sizeof(lnode));
	p->element = elem;
	if(*S == NULL){
		p->next = *S;
		*S = p;
	}else{
		while(temp->next != NULL){
			temp = temp->next;
		}
		p->next = temp->next;
		temp->next = p;
	}
}

void displayToken(TOKEN t){
		switch(t.type){
			case 0:
				printf("\n%s","SENTINEL");
				break;
			case 1:
				printf("(%s,%c)","BOP",binOP[t.value]);
				break;
			case 2:
				printf("(%s,%c)","OOP",otherOP[t.value]);
				break;
			case 3:
				printf("(%s,%c)","DEL",'_');
				break;
			case 4:
				printf("(%s,%d)","NUM",t.value);
				break;
			case 5:
				printf("%s","END");
				break;
		}
}

void displayChar(TOKEN t){
		switch(t.type){
			case 0:
				printf("\n%s ","SENTINEL");
				break;
			case 1:
				printf("%c ",binOP[t.value]);
				break;
			case 2:
				printf("%c ",otherOP[t.value]);
				break;
			case 3:
				printf("%c ",'_');
				break;
			case 4:
				printf("%d ",t.value);
				break;
			case 5:
				printf("%s ","END");
				break;
		}
}

void displayList(nptr S) {
	nptr temp = S;


	while(next(temp).type != 5 ) {
		displayToken(temp->element);
		printf("-->");
		consume(&temp);
	}
	displayToken(temp->element);
	printf("-->");
	displayToken(next(temp));
	printf("\n\n");
}


TOKEN consume(nptr *t){
	(*t) = (*t)->next;
	if((*t)->element.type == 3)
		return consume(t);
	else
		return (*t)->element;
}

TOKEN next(nptr t){
	if(t->next->element.type == 3)
		return t->next->next->element;
	else
		return t->next->element;
}

/*
int main(){
	nptr t;
	char expr[] = "(1+3)*5";
	printf("\nExpression:%s",expr);
	t = initLex(expr);
	displayList(t);
	exit(-1);

}
*/


