# Makefile for calc

#*****************************

CC = gcc
CFLAGS = -Wall -g

#*****************************

calc: Parser.c Parser.h Ast.o Lex.o
	$(CC) $(CFLAGS) -o calc Parser.c Ast.o Lex.o

Ast.o: Ast.c Ast.h Lex.o
	$(CC) $(CFLAGS) -c Ast.c

Lex.o: Lex.c Lex.h
	$(CC) $(CFLAGS) -c Lex.c
