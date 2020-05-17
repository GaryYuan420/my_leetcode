#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>


typedef struct {
	int *stack;
	int *min_stack;
	int top;   
	int mintop;
} MinStack;
#define MAXSIZE 1600
/** initialize your data structure here. */

MinStack* minStackCreate() {
	MinStack *obj = malloc(sizeof(MinStack));
	obj->stack = malloc(MAXSIZE * sizeof(int));
	obj->min_stack = malloc(MAXSIZE * sizeof(int));
	obj->top = -1;
	obj->mintop = -1;
	return obj;
}

void minStackPush(MinStack* obj, int x) {
	if(obj->top < 0)
	{
		*(obj->stack) = x;
		obj->top = 0;
	}
	else
	{
		obj->top++;
		*(obj->stack + obj->top) = x;
	}
	if((obj->mintop < 0) || (x <= *(obj->min_stack + obj->mintop)))
	{
		obj->mintop++;		
		*(obj->min_stack + obj->mintop) = x;
	}
}

void minStackPop(MinStack* obj) {
	if( obj->top < 0)
		return;
	if( *(obj->stack + obj->top) == *(obj->min_stack + obj->mintop) )
		obj->mintop--;
	obj->top--;
	return;
}

int minStackTop(MinStack* obj) {
	if(obj->top < 0)
		return 0;
	return *(obj->stack + obj->top);
}

int minStackGetMin(MinStack* obj) {
	if( obj->mintop < 0)
		return 0;
	return *(obj->min_stack + obj->mintop);
}

void minStackFree(MinStack* obj) {
    free(obj->stack);
	free(obj->min_stack);
	free(obj);
	return;
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/

int main(void)
{

	MinStack* obj = minStackCreate();
	minStackPush(obj, 5);
	minStackPush(obj, 3);
	minStackPop(obj);
	
	int param_3 = minStackTop(obj);
	
	int param_4 = minStackGetMin(obj);
    printf("%d %d\n", param_3, param_4);
	minStackFree(obj);
	
    return 0;
}