#include <stddef.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "functions.h"



int precedence(char c)
{
    if(isalpha(c))  return 3;
    if(c == '*' || c == '/' || c == '%') return 2;
    if(c == '-' || c == '+') return 1;
    return 0;
}

void push(char c[] , char stack[][MAX_OPERAND] , size_t *nElementsInStack)
{
    if(*nElementsInStack < MAXVAL) strcpy( stack[(*nElementsInStack)++] , c) ;
    else printf("error : Stack Full can't Push %s\n" , c);
}

char* pop(char stack[][MAX_OPERAND] , size_t *nElementsInStack)
{
    if (*nElementsInStack > 0) return stack[--*nElementsInStack];
    else
    {
        printf("error: stack empty\n");
        return NULL;
    }
}

void lowerCase(char* str)
{
    for(int i=0; i<strlen(str); i++)
    {
        if(isalpha(str[i])) str[i] = tolower(str[i]);
    }
}

void clearScreen() {
    printf("\033[2J\033[H");
}

void scanMatrix(double **matrix ,size_t rows ,size_t cols) {

    for(int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            scanf("%lf" , &matrix[i][j]);
        }
    }

}

void displayHelp() {
    printf("Available commands:\n\n\n");
    printf("equation / eqn - Solve two-variable or three-variable equations.\n\n\n");
    printf("base / base conversion - Convert a number between different bases.\n\n\n");
    printf("matrix - Perform matrix operations (addition, subtraction, multiplication, division).\n\n\n");
    printf("vector - Perform vector operations (not implemented in this version).\n\n\n");
    printf("log<value> - Calculate the natural logarithm of a value.\n\n\n");
    printf("sin<angle> - Calculate the sine of an angle (in degrees or radians).\n\n\n");
    printf("cos<angle> - Calculate the cosine of an angle (in degrees or radians).\n\n\n");
    printf("sqrt<value> - Calculate the square root of a value.\n\n\n");
    printf("exp<value> - Calculate the exponential of a value.\n\n\n");
    printf("<x>+<y> , <x>sint , etc - Evaluate expression.\n\n\n");
}

