#ifndef LEXER_H
#define LEXER_H

#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

#include "token.h"
#include "list.h"

struct LEXER{
	char* src;
	char current;
	unsigned int i;
};

struct LEXER* createLexer(char* src);
void advance(struct LEXER* lexer);
void n_advance(struct LEXER* lexer, int n);
void skip(struct LEXER* lexer);
struct TOKEN* parseString(struct LEXER* lexer);
struct TOKEN* parseInteger(struct LEXER* lexer);
struct TOKEN* parseIdentifier(struct LEXER* lexer);
struct TOKEN* nextToken(struct LEXER* lexer);
struct ARRAY_LIST* lex(struct LEXER* lexer);

#endif
