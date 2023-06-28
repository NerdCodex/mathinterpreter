#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "read.h"
#include "tokens.h"
#include "Parser.h"


// Function Declaration

void parse();

void Tokenizer(char *data){
	int length = len(data);
	int x;
	for (x=0;x<length;x++) {
		if(*data=='+'){
			strcpy(tok[x].token_type, "PLUS");
            		strcpy(tok[x].token_value, "+");
            		data++;
		}
		else if(*data=='-'){
			strcpy(tok[x].token_type, "MINUS");
            		strcpy(tok[x].token_value, "-");
            		data++;
		}

		else if (*data=='*'){
			strcpy(tok[x].token_type, "MUL");
			strcpy(tok[x].token_value, "*");
			data++;
		}

		else if(*data=='/'){
			strcpy(tok[x].token_type, "DIV");
			strcpy(tok[x].token_value, "/");
			data++;
		}

		else if ((*data=='1')||(*data=='2')||(*data=='3')||(*data=='4')||(*data=='5')||(*data=='6')||(*data=='7')||(*data=='8')||(*data=='9')||(*data=='0')){
			int dot = 0;
			char number[31] = "";

			while ((*data=='1')||(*data=='2')||(*data=='3')||(*data=='4')||(*data=='5')||(*data=='6')||(*data=='7')||(*data=='8')||(*data=='9')||(*data=='0')||(*data=='.')){
				if (*data=='.'){
					strcat(number, ".");
					dot+=1;
				}

				else {
					strncat(number, data, 1);				
				}
				data++;
			
			}

			if (dot == 0){
				strcpy(tok[x].token_value, number);
				strcpy(tok[x].token_type, "INT");
			}
			else if(dot == 1){
				strcpy(tok[x].token_value, number);
				strcpy(tok[x].token_type, "FLOAT");
			}

			else {
				printf("Illegal Charater %c", *data);
				data++;
			}

		}

		else if(*data==' '){
			data++;
            		strcpy(tok[x].token_type, "");
            		strcpy(tok[x].token_value, "");
		}

		else if(*data == '('){
			strcpy(tok[x].token_type, "LPAREN");
			strcpy(tok[x].token_value, "(");
			data++;
		}

		else if(*data == ')'){
			strcpy(tok[x].token_type, "RPAREN");
			strcpy(tok[x].token_value, ")");
			data++;
		}		


		else {
            data++;
		}
		
    }
    
    parse();

}


