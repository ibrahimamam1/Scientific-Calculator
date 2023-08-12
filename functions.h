#pragma once
#include <stddef.h>
#include <stdio.h>

#define MAX_OPERATION 100
#define MAX_OPERAND 15
#define MAXVAL 100
#define NUMBER '0'

int precedence(char c);
void push(char c[] , char stack[][MAX_OPERAND] , size_t *nElementsInStack);
char* pop(char stack[][MAX_OPERAND] , size_t *nElementsinStack);
void lowerCase(char*);
void clearScreen();
void scanMatrix(double **matrix  ,size_t rows ,size_t cols);
void displayHelp(); 
