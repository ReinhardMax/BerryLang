#include "include/token.h"
#include "include/string.h"

struct TOKEN* createToken(char* value, unsigned char type){
	struct TOKEN* tok = calloc(1, sizeof(struct TOKEN));
	tok->value = value;
	tok->type = type;
	return tok;
}

char* tok_to_str(struct TOKEN* token){
	char* prefix;
	switch(token->type){
		case TOKEN_TYPE_BYTE : {prefix="BYTE";break;}
		case TOKEN_TYPE_WORD : {prefix="WORD";break;}
		case TOKEN_TYPE_DWORD : {prefix="DWORD";break;}
		case TOKEN_TYPE_QWORD : {prefix="QWORD";break;}
		case TOKEN_TYPE_INTEGER : {prefix="INTEGER";break;}
		case TOKEN_TYPE_FLOAT : {prefix="FLOAT";break;}
		case TOKEN_TYPE_STRING : {prefix="STRING";break;}
		case TOKEN_TYPE_OBJECT : {prefix="OBJECT";break;}
		case TOKEN_TYPE_IDENTIFIER : {prefix="IDENTIFIER";break;}
		case TOKEN_TYPE_IF : {prefix="IF";break;}
		case TOKEN_TYPE_ELSE : {prefix="ELSE";break;}
		case TOKEN_TYPE_ENDIF : {prefix="ENDIF";break;}
		case TOKEN_TYPE_WHILE : {prefix="WHILE";break;}
		case TOKEN_TYPE_ENDWHILE : {prefix="ENDWHILE";break;}
		case TOKEN_TYPE_FUNC : {prefix="FUNC";break;}
		case TOKEN_TYPE_ENDFUNC : {prefix="ENDFUNC";break;}
		case TOKEN_TYPE_RETURN : {prefix="RETURN";break;}
		case TOKEN_TYPE_LBRACE : {prefix="LBRACE";break;}
		case TOKEN_TYPE_RBRACE : {prefix="RBRACE";break;}
		case TOKEN_TYPE_LCBRACE : {prefix="LCBRACE";break;}
		case TOKEN_TYPE_RCBRACE : {prefix="RCBRACE";break;}
		case TOKEN_TYPE_LSBRACE : {prefix="LSBRACE";break;}
		case TOKEN_TYPE_RSBRACE : {prefix="RSBRACE";break;}
		case TOKEN_TYPE_EQUALS : {prefix="EQUALS";break;}
		case TOKEN_TYPE_CONDEQU : {prefix="EQUCOND";break;}
		case TOKEN_TYPE_NEQUALS : {prefix="NEQU";break;}
		case TOKEN_TYPE_LESSEQU : {prefix="LESSEQU";break;}
		case TOKEN_TYPE_MOREEQU : {prefix="MOREEQU";break;}
		case TOKEN_TYPE_NOT : {prefix="NOT";break;}
		case TOKEN_TYPE_AND : {prefix="AND";break;}
		case TOKEN_TYPE_OR : {prefix="OR";break;}
		case TOKEN_TYPE_BITAND : {prefix="BITAND";break;}
		case TOKEN_TYPE_ANDEQU : {prefix="ANDEQU";break;}
		case TOKEN_TYPE_BITOR : {prefix="BITOR";break;}
		case TOKEN_TYPE_OREQU : {prefix="OREQU";break;}
		case TOKEN_TYPE_LBITSHIFT : {prefix="LBITSHIFT";break;}
		case TOKEN_TYPE_RBITSHIFT : {prefix="RBITSHIFT";break;}
		case TOKEN_TYPE_EOF : {prefix="EOF";break;}
		case TOKEN_TYPE_PLUS : {prefix="PLUS";break;}
		case TOKEN_TYPE_MINUS : {prefix="MINUS";break;}
		case TOKEN_TYPE_MULTIPLY : {prefix="MULTIPLY";break;}
		case TOKEN_TYPE_DIVIDE : {prefix="DIVIDE";break;}
		case TOKEN_TYPE_PLUSEQU : {prefix="PLUSEQU";break;}
		case TOKEN_TYPE_MINUSEQU : {prefix="MINUSEQU";break;}
		case TOKEN_TYPE_MULTIPLYEQU : {prefix="MULTIPLYEQU";break;}
		case TOKEN_TYPE_DIVIDEEQU : {prefix="DIVIDEEQU";break;}
		case TOKEN_TYPE_KOMMA : {prefix="KOMMA";break;}
		case TOKEN_TYPE_INCREMENT : {prefix="INCREMENT";break;}
		case TOKEN_TYPE_DECREMENT : {prefix="DECREMENT";break;}
		case TOKEN_TYPE_SQUARED : {prefix="SQRD";break;}
		case TOKEN_TYPE_SQUAREROOT : {prefix="SQRT";break;}
		case TOKEN_TYPE_LESS : {prefix="LESS";break;}
		case TOKEN_TYPE_MORE : {prefix="MORE";break;}
		case TOKEN_TYPE_BITNOT : {prefix="BITNOT";break;}
		case TOKEN_TYPE_BITNOTEQU : {prefix="BITNOTEQU";break;}
		default:{prefix="UNKNOWN";break;}
	}
		printf("<token:%s> : <value:'%s'>\n", prefix, token->value);
}
