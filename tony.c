#include<stdio.h>
#include "header/Lexer.h"


void main(){
	char *ptr;
	while (1){
		ptr=input("interpreter>  ");
		Tokenizer(ptr);
	}
}

