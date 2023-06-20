#include<stdio.h>
#include<stdlib.h>


//char *input(char);
int len(char *ptr);

char *input(char str[]){
	static char in[31]; 
	printf("%s", str);
	fgets(in, 31, stdin);
	return in;
}

int len(char *ptr){
	int Len=-1;
	while(*ptr != '\0') {
            Len++;
            ptr++;
        }
        //printf("%d", Len);
	return Len;
}

