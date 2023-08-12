#pragma once
#include <stdio.h>

void infixToPostfix(char *str);
double evaluatePostfix();
void solveTwoVarEquation();
void solveThreeVarEquation();
int baseConv(int base, int target, int number);
void matrixAddition(size_t rows , size_t cols ,double **matrix1 , double **matrix2, double **res);
void matrixSubtraction(size_t rows , size_t cols ,double **matrix1 , double **matrix2, double **res);
void matrixMultiplication(size_t *rows , size_t *cols ,double **matrix1 , double **matrix2, double **res);
void matrixDivision(size_t *rows , size_t *cols ,double **matrix1 , double **matrix2, double **res);
void printMatrix(double **res , size_t rows , size_t cols);