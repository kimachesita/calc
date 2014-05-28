#ifndef LEX_H
#define LEX_H

typedef struct TOKEN{
	int type;                       //contains type of token see Lex.c for reference
	int value;                      //contains value/index of token match into the symbol table (see Lex.c)
}TOKEN;

                                    // Singly Linklist Data Structure for listing token
typedef struct lnode{
	TOKEN element;	                 //contains a TOKEN as an element
	struct lnode *next;              //pointer to another node
}lnode;

typedef lnode *nptr;                 //pointer to a list of nodes

void add_node(nptr *S,TOKEN elem);	 //adds a node to token list
nptr initLex(char *expr);		     //initialize lexical analyzer given arithmetic exp, returns a token list
TOKEN makeToken(int type,int value); //make a token
void displayList(nptr S);            //display a given token list
void displayToken(TOKEN t);		     //display a token
void displayChar(TOKEN t); 		     //display the value of a token
TOKEN next(nptr t);				     //returns the next token of input or special token "END" to represent
                                     //that there are no more inputs;next does not alter the input stream
TOKEN consume(nptr *t);			     //Reads one token, When "next=end" , consume is still allowed but has no effect

#endif
