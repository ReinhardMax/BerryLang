#include "include/compile.h"

void compile(char* src){

	struct LEXER* lexer = createLexer(src);
	struct ARRAY_LIST* tokens = lex(lexer);
//	struct* AST parse(tokens);
}
