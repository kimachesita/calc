#ifndef Parser_H
#define Parser_H

void error(void);				//Prints parsing error
void expect(TOKEN tok);			//Compares a given token with the curren token
int compareToken(TOKEN a,TOKEN b); //function used by expect()
Tree P(void);  				//grammar routine, returns partial AST
Tree T(void);					//grammar routine, returns partial AST 
Tree E(void);					//grammar routine, returns partial AST
Tree Eparser(void);				//Interface to the grammar routine, returns final AST

#endif
