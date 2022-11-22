#include "include/string.h"

unsigned long long str_len(char* str){
	unsigned long long len = 0;
	while(str[len] != '\0'){
		len++;
	}
	return len;
}

char str_cmp(char* str1, char* str2){
	if(str_len(str1) != str_len(str2)){
		return 1;
	}
	unsigned long long len = str_len(str1);
	unsigned long long i = 0;
	while (i < len){
		if(str1[i] != str2[i]){
			return 1;
		}
		i++;
	}
	return 0;
}

char* peek(char* src, unsigned int start, unsigned int n){
	char* result = calloc(n, sizeof(char));
	for (int i = 0; i < n; i++){
		result[i] = src[start + i];
	}
	return result;
}

//experimental

char c_alnum(char c){

	for(int i = 0; i < 62; i++){
		if(c == alnumchars[i]){
			return TRUE;
		}
	}
	return FALSE;
}

char c_decnum(char c){

	for(int i = 0; i < 10; i++){
		if(c == numchars[i]){
			return TRUE;
		}
	}
	return FALSE;
}
