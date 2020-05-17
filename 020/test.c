#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024
#define bool  int
#define true 1
#define false 0

typedef struct tag_stack_st
{
	char data[MAX_LENGTH];
	int length;
	int pos;
} stack_st;

void init_stack(stack_st* stack)
{
	memset(stack->data,0,MAX_LENGTH);
	stack->length = MAX_LENGTH;
	stack->pos = 0;
}

void push(stack_st* stack, char c)
{
	stack->data[stack->pos] = c;
	stack->pos++;
} 

char pop(stack_st* stack)
{	
	if(stack->pos <= 0) return 0xff;
	return stack->data[--stack->pos];
}

bool compare(char a, char b)
{
	bool ret = true;
	switch(a)
	{
		case '{':
			ret = (b == '}');
			break;
		case '[':
			ret = (b == ']');
			break;
		case '(':
			ret = (b == ')');
			break;
		default:
			ret = false;
			break;
	}
	return ret;
}

bool isempty(stack_st* stack)
{
	return stack->pos == 0;
}

bool isValid(char * s){
	
	stack_st *pstack = malloc(sizeof(stack_st));
	int ret = true;
	char pop_char;
	init_stack(pstack);
	while((*s != '\0') && (ret == true))
	{
		switch(*s)
		{
			case '{':
			case '(':
			case '[':
				push(pstack, *s);
				break;
			case ')':
			case '}':
			case ']':
				pop_char = pop(pstack);
				ret = compare(pop_char, *s);
				break;
		}
		s++;
	}
	if(!isempty(pstack))
		ret = false;
	free(pstack);
	return ret;
}

int main(int argc, char *argv[])
{
	if(isValid(argv[1]))
	{
		printf("true\n");
	}
	else
	{
		printf("false\n");
	}
	return 0;
}