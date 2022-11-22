#include "include/lexer.h"
#include "include/string.h"

struct LEXER* createLexer(char* src){

	struct LEXER* lexer = calloc(1, sizeof(struct LEXER));
	lexer->src = src;
	lexer->i = 0;
	lexer->current = src[lexer->i];
	return lexer;
}

void advance(struct LEXER* lexer){
	lexer->i++;
	lexer->current = lexer->src[lexer->i];
}

void n_advance(struct LEXER* lexer, int n){
	for(int i = 0; i < n; i++){
		lexer->i++;
	}
	lexer->current = lexer->src[lexer->i];
}

void skip(struct LEXER* lexer){
	while(lexer->current == ' ' || lexer->current == '\t' || lexer->current == '\n'){
		advance(lexer);
	}

	if(lexer->current == ';'){
		while(lexer->current != '\n'){
			advance(lexer);
		}
		advance(lexer);
	}
}


struct TOKEN* parseString(struct LEXER* lexer){
	advance(lexer);
	char* content = calloc(0, sizeof(char));
	unsigned int i = 0;
	while(lexer->current != '\"'){
		if(lexer->current != '\"'){
			content = realloc(content, i+1);
			content[i] = lexer->current;
			i++;
		}
		advance(lexer);
	}
	advance(lexer);
	return createToken(content, TOKEN_TYPE_STRING);
}

struct TOKEN* parseInteger(struct LEXER* lexer){
	char* number = calloc(1, sizeof(char));
	unsigned int i = 0;
	while(c_decnum(lexer->current) == TRUE){
		number = realloc(number, i+1);
		number[i] = lexer->current;
		advance(lexer);
		i++;
	}
	return createToken(number, TOKEN_TYPE_INTEGER);
}

struct TOKEN* parseIdentifier(struct LEXER* lexer){
	char* identifier = calloc(1, sizeof(char));
	unsigned int i = 0;
	while(c_alnum(lexer->current) == TRUE || lexer->current == '_'){
		identifier = realloc(identifier, i+1);
		identifier[i] = lexer->current;
		advance(lexer);
		i++;
	}
	return createToken(identifier, TOKEN_TYPE_IDENTIFIER);
}

struct TOKEN* nextToken(struct LEXER* lexer){
	skip(lexer);
	if(str_cmp(peek(lexer->src, lexer->i, 4), "byte") == TRUE){
		n_advance(lexer, 4);
		return createToken("byte", TOKEN_TYPE_BYTE);
	}
	if(str_cmp(peek(lexer->src, lexer->i, 5), "qword") == TRUE){
		n_advance(lexer, 5);
		return createToken("qword", TOKEN_TYPE_QWORD);
	}
	if(str_cmp(peek(lexer->src, lexer->i, 5), "dword") == TRUE){
		n_advance(lexer, 5);
		return createToken("dword", TOKEN_TYPE_DWORD);
	}
	if(str_cmp(peek(lexer->src, lexer->i, 4), "word") == TRUE){
		n_advance(lexer, 4);
		return createToken("word", TOKEN_TYPE_WORD);
	}

	if(str_cmp(peek(lexer->src, lexer->i, 4), "func") == TRUE){
		n_advance(lexer, 4);
		return createToken("func", TOKEN_TYPE_FUNC);
	}
	if(str_cmp(peek(lexer->src, lexer->i, 7), "endfunc") == TRUE){
		n_advance(lexer, 7);
		return createToken("endfunc", TOKEN_TYPE_ENDFUNC);
	}

	if(str_cmp(peek(lexer->src, lexer->i, 2), "if") == TRUE){
		n_advance(lexer, 2);
		return createToken("if", TOKEN_TYPE_IF);
	}
	if(str_cmp(peek(lexer->src, lexer->i, 4), "else") == TRUE){
		n_advance(lexer, 4);
		return createToken("else", TOKEN_TYPE_ELSE);
	}
	if(str_cmp(peek(lexer->src, lexer->i, 5), "endif") == TRUE){
		n_advance(lexer, 5);
		return createToken("endif", TOKEN_TYPE_ENDIF);
	}

	if(str_cmp(peek(lexer->src, lexer->i, 5), "while") == TRUE){
		n_advance(lexer, 5);
		return createToken("while", TOKEN_TYPE_WHILE);
	}
	if(str_cmp(peek(lexer->src, lexer->i, 8), "endwhile") == TRUE){
		n_advance(lexer, 8);
		return createToken("endwhile", TOKEN_TYPE_ENDWHILE);
	}

	switch(lexer->current){
		case('+'):{if(str_cmp(peek(lexer->src, lexer->i, 2), "++") == TRUE){n_advance(lexer, 2);return createToken("++", TOKEN_TYPE_INCREMENT);}if(str_cmp(peek(lexer->src, lexer->i, 2), "+=") == TRUE){n_advance(lexer, 2);return createToken("+=", TOKEN_TYPE_PLUSEQU);}advance(lexer);return createToken("+", TOKEN_TYPE_PLUS);}
		case('-'):{if(str_cmp(peek(lexer->src, lexer->i, 2), "--") == TRUE){n_advance(lexer, 2);return createToken("--", TOKEN_TYPE_DECREMENT);}if(str_cmp(peek(lexer->src, lexer->i, 2), "-=") == TRUE){n_advance(lexer, 2);return createToken("-=", TOKEN_TYPE_MINUSEQU);}advance(lexer);return createToken("-", TOKEN_TYPE_MINUS);}
		case('*'):{if(str_cmp(peek(lexer->src, lexer->i, 2), "**") == TRUE){n_advance(lexer, 2);return createToken("**", TOKEN_TYPE_SQUARED);}if(str_cmp(peek(lexer->src, lexer->i, 2), "*=") == TRUE){n_advance(lexer, 2);return createToken("*=", TOKEN_TYPE_MULTIPLYEQU);}advance(lexer);return createToken("*", TOKEN_TYPE_MULTIPLY);}
		case('/'):{if(str_cmp(peek(lexer->src, lexer->i, 2), "//") == TRUE){n_advance(lexer, 2);return createToken("//", TOKEN_TYPE_SQUAREROOT);}if(str_cmp(peek(lexer->src, lexer->i, 2), "/=") == TRUE){n_advance(lexer, 2);return createToken("/=", TOKEN_TYPE_DIVIDEEQU);}advance(lexer);return createToken("/", TOKEN_TYPE_DIVIDE);}
		case('='):{if(str_cmp(peek(lexer->src, lexer->i, 2), "==") == TRUE){n_advance(lexer, 2);return createToken("==", TOKEN_TYPE_CONDEQU);}advance(lexer);return createToken("=", TOKEN_TYPE_EQUALS);}
		case('<'):{if(str_cmp(peek(lexer->src, lexer->i, 2), "<=") == TRUE){n_advance(lexer, 2);return createToken("<=", TOKEN_TYPE_LESSEQU);}if(str_cmp(peek(lexer->src, lexer->i, 2), "<<") == TRUE){n_advance(lexer, 2);return createToken("<<", TOKEN_TYPE_LBITSHIFT);}advance(lexer);return createToken("<", TOKEN_TYPE_LESS);}
		case('>'):{if(str_cmp(peek(lexer->src, lexer->i, 2), ">=") == TRUE){n_advance(lexer, 2);return createToken(">=", TOKEN_TYPE_MOREEQU);}if(str_cmp(peek(lexer->src, lexer->i, 2), ">>") == TRUE){n_advance(lexer, 2);return createToken(">>", TOKEN_TYPE_RBITSHIFT);}advance(lexer);return createToken(">", TOKEN_TYPE_MORE);}
		case('!'):{if(str_cmp(peek(lexer->src, lexer->i, 2), "!=") == TRUE){n_advance(lexer, 2);return createToken("!=", TOKEN_TYPE_NEQUALS);}advance(lexer);return createToken("!", TOKEN_TYPE_NOT);}
		case('~'):{if(str_cmp(peek(lexer->src, lexer->i, 2), "~=") == TRUE){n_advance(lexer, 2);return createToken("~=", TOKEN_TYPE_BITNOTEQU);}advance(lexer);return createToken("~", TOKEN_TYPE_BITNOT);}
		case('&'):{if(str_cmp(peek(lexer->src, lexer->i, 2), "&=") == TRUE){n_advance(lexer, 2);return createToken("&=", TOKEN_TYPE_ANDEQU);}if(str_cmp(peek(lexer->src, lexer->i, 2), "&&") == TRUE){n_advance(lexer, 2);return createToken("&&", TOKEN_TYPE_AND);}advance(lexer);return createToken("&", TOKEN_TYPE_BITAND);}
		case('|'):{if(str_cmp(peek(lexer->src, lexer->i, 2), "|=") == TRUE){n_advance(lexer, 2);return createToken("|=", TOKEN_TYPE_OREQU);}if(str_cmp(peek(lexer->src, lexer->i, 2), "||") == TRUE){n_advance(lexer, 2);return createToken("||", TOKEN_TYPE_OR);}advance(lexer);return createToken("|", TOKEN_TYPE_BITOR);}

		case('('):{advance(lexer);return createToken("(", TOKEN_TYPE_LBRACE);}
		case(')'):{advance(lexer);return createToken(")", TOKEN_TYPE_RBRACE);}
		case('['):{advance(lexer);return createToken("[", TOKEN_TYPE_LSBRACE);}
		case(']'):{advance(lexer);return createToken("]", TOKEN_TYPE_RSBRACE);}
		case('{'):{advance(lexer);return createToken("{", TOKEN_TYPE_LCBRACE);}
		case('}'):{advance(lexer);return createToken("}", TOKEN_TYPE_RCBRACE);}
		case(','):{advance(lexer);return createToken(",", TOKEN_TYPE_KOMMA);}

	}

	if(lexer->current == '\"'){
		return parseString(lexer);
	}

	if(c_decnum(lexer->current) == TRUE){
		return parseInteger(lexer);
	}

	if(c_alnum(lexer->current) == TRUE || lexer->current == '_'){
		return parseIdentifier(lexer);
	}

	if(lexer->current == '\0'){
		return createToken("eof", TOKEN_TYPE_EOF);
	}
	advance(lexer);
	return createToken("undefined", TOKEN_TYPE_UNKNOWN);
}

struct ARRAY_LIST* lex(struct LEXER* lexer){

	struct ARRAY_LIST* list = createArrayList(sizeof(struct TOKEN));
	struct TOKEN* token = createToken("undefined", TOKEN_TYPE_UNKNOWN);
	unsigned int i = 0;
	while(token->type != TOKEN_TYPE_EOF){
		i++;
		token = nextToken(lexer);
		addItem(list, token);
		tok_to_str(token);
	}
	printf("--------------------------------\n%u : Tokens found\n\n", i);

	return list;
}
