#include "stack.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int RPN(char* exp, float* tot)
{
    if(exp == NULL) {return -1;}

    float* one = malloc(sizeof(float));
    float* two = malloc(sizeof(float));
    *one = 0;
    *two = 0;

    int index = 0;
    struct stackNode **top = malloc(sizeof(struct stackNode*));
    *top = NULL;

    while(exp[index] != '\n')
    {
        char temp = exp[index];

        if(temp == ' ') {index++;continue;}

        if(temp == '*' || temp == '/' || temp == '+' || temp == '-')
        {
            if(Pop(top, one)){return -1;}
            if(Pop(top, two)){return-1;}
        }

        if(temp == '*')
        {
            Push(top, (*two * *one));
        }
        else if(temp == '/')
        {
            Push(top, (*two / *one));
        }
        else if(temp == '+')
        {
            Push(top, (*two + *one));
        }
        else if(temp == '-')
        {
            Push(top, (*two - *one));
        }
        else
        {
            Push(top, (float)atof(&temp));
        }

        index++;
    }

    if((*top)->next != NULL) {return -1;}

    *tot = (*top)->data;

    free(one);
    free(two);

    while(*top != NULL)
    {
        Pop(top, tot);
    }

    free(top);

    return 0;
}

int main(void)
{
    float *total = malloc(sizeof(float));
    char *exp = malloc(1);

    printf("Expression: ");

    unsigned int index = 0;
    exp[index] = (char)getchar();
    while(exp[index] != '\n')
    {
        index++;
        exp = realloc(exp, (index + 1));
        exp[index] = (char)getchar();
    }
    
    if(RPN(exp, total))
    {
        printf("Invalid Expression\n");
    }
    else
    {
        printf("Result: %d\n", (int)*total);
    }

    free(exp);
    free(total);
}
