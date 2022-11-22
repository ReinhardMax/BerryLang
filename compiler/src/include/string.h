#ifndef STRING_H
#define STRING_H

#define TRUE 0
#define FALSE 1

#include <stdlib.h>

static char* alnumchars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
static char* numchars = "0123456789";

	unsigned long long str_len(char* str);
	char str_cmp(char* str1, char* str2);
	char* peek(char* src, unsigned int start, unsigned int n);
	char c_alnum(char c);
	char c_decnum(char c);

#endif
