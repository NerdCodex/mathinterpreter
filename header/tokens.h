#include<stdio.h>


struct Tokens {
	char token_type[31];
	char token_value[31];
};

static struct Tokens tok[31];
