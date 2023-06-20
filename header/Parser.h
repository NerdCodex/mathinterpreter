#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>



// Function declaration

double expression(const struct Tokens **);

double factor(const struct Tokens **ptr){
	double result;
	int sign = 1;
	if (*(*ptr)->token_value == '-'){
		sign = -1;
		*(*ptr)++;
	}

	if (*(*ptr)->token_value == '('){
		*(*ptr)++;
		result = expression(ptr);
		if (*(*ptr)->token_value == ')') {
			*(*ptr)++;
		}
		else {
			printf("Error: Missing closing parenthesis");
			exit(1);
		}
	}

	else if (isdigit(*(*ptr)->token_value)){
		char temp[100];
		strcpy(temp, (*ptr)->token_value);
		result = atof(temp);
		*(*ptr)++;
	} else {
		printf("Error: Invalid Expression (%s)", (*ptr)->token_value);
		exit(1);	
    }
    return sign * result;
}

double term(const struct Tokens **ptr){
	double result = factor(ptr);
	while (*(*ptr)->token_value == '*' || *(*ptr)->token_value == '/'){
		char op = *(*ptr)->token_value;
		*(*ptr)++;

		double operand = factor(ptr);

		if (op == '*'){
			result *= operand;
		} else {
			if (operand != 0){
				result /= operand;
			} else {
				printf("Error:");
				exit(1);
			}
		}
	}
	return result;

}


double expression(const struct Tokens **ptr) {
	double result = term(ptr);

	while (*(*ptr)->token_value == '+' || *(*ptr)->token_value == '-') {
		char op =  *(*ptr)->token_value;
		*(*ptr)++;

		double operand = term(ptr);

		if (op == '+'){
			result += operand;
		} else {
			result -= operand;
		}
	}

	return result;
}

void parse(){	
	const struct Tokens *ptr1 = tok;
	double result = expression(&ptr1);

	printf("%.2lf\n", result);


}
