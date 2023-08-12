#include <stddef.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "functions.h"
#include "operations.h"

char postfixStack[MAX_OPERATION][MAX_OPERAND];
size_t elementsInPostfixStack = 0;

void infixToPostfix(char *str)
{
    char operatorStack[MAX_OPERATION];
    size_t elementsinOpStack = 0;

    char op[MAX_OPERAND];
    memset(op, '\0', MAX_OPERAND);

    for(int i=0; str[i]; i++)
    {
        if(isdigit(str[i])) //Push to stack
        {
            op[0] = str[i];
            int j=1;
            while(isdigit(str[i+1])) //Taking multiplle digit numbers
            {
                op[j++] = str[++i];
            }
            push(op , postfixStack , &elementsInPostfixStack);
        } 
        else if(str[i] == '(')
        {
            operatorStack[elementsinOpStack++] = '(';
        }
        else if(str[i] == ')')
        {
            while(operatorStack[elementsinOpStack-1] != '(' )
            {
                    op[0] = operatorStack[--elementsinOpStack];
                    push(op, postfixStack, &elementsInPostfixStack);
            }
            --(elementsinOpStack);
        }
        else //if it is an operator
        {
            if(elementsinOpStack > 0)
            {
                int j = elementsinOpStack;
                while(precedence(operatorStack[--j]) > precedence(str[i])) // while there is an operator with > precedence
                {
                    op[0] = operatorStack[--(elementsinOpStack)];
                    push(op, postfixStack, &elementsInPostfixStack);
                }
            }    
            operatorStack[elementsinOpStack++] = str[i];
            if(isalpha(str[i])) while (isalpha(str[i+1])) i++;
        }
        memset(op, '\0', MAX_OPERAND);
    }

    while(elementsinOpStack > 0)
    {
        op[0] = operatorStack[--(elementsinOpStack)];
        push(op, postfixStack, &elementsInPostfixStack);
    }
}

char resultStack[MAX_OPERATION][MAX_OPERAND];
size_t elementsInResultStack = 0;

double evaluatePostfix()
{
    for(int i=0; i<elementsInPostfixStack; i++)
    {
        char result[MAXVAL];
        double x;
        double y;

        if(isdigit(postfixStack[i][0]))
        {
            push(postfixStack[i], resultStack, &elementsInResultStack);
            continue;
        }

        else if(isalpha(postfixStack[i][0]))
        {
            x = atof(pop(resultStack, &elementsInResultStack));
            if(postfixStack[i][0] == 'p' || postfixStack[i][0] == 'e') y = atof(pop(resultStack, &elementsInResultStack));
        }

        else
        {
            x = atof(pop(resultStack, &elementsInResultStack));
            y = atof(pop(resultStack, &elementsInResultStack));
        }

        switch (postfixStack[i][0])
            {
                case '+':
                    sprintf(result, "%lf" , y + x);
                    break;
                case '-':
                    sprintf(result, "%lf" , y - x);
                    break;
                case '*':
                    sprintf(result, "%lf" , y * x);
                    break ;  
                case '/':
                    sprintf(result, "%lf" , y / x);
                    break;
                case 'p':    
                case 'e':
                    sprintf(result, "%lf" , pow(y, x));
                    break;    
                case 's':
                    sprintf(result, "%lf" , sin(x));
                    break;
                case 'c':
                    sprintf(result, "%lf" , cos(x));
                    break;
                case 't':
                    sprintf(result, "%lf" , tan(x));
                    break;
                case 'l':
                    sprintf(result, "%lf" , log(x));
                    break;    
        }
        push(result , resultStack , &elementsInResultStack);
    }
    return atof(pop(resultStack, &elementsInResultStack));
}

void solveTwoVarEquation()
{
    int x1 , y1 , c1 , x2 , y2 , c2;
    int x , y , c;

    printf("X1: ");
    scanf("%d" , &x1);
    printf("Y1: ");
    scanf("%d" , &y1);
    printf("C1: ");
    scanf("%d" , &c1);
    printf("X2: ");
    scanf("%d" , &x2);
    printf("Y2: ");
    scanf("%d" , &y2);
    printf("C2: ");
    scanf("%d" , &c2);

    int temp = x1;
    x1 *= x2;
    y1 *= x2;
    c1 *= x2;
    
    x2 *= temp;
    y2 *= temp;
    c2 *= temp;

    y = y1 - y2;
    c = c1 - c2;

    y = c/y;

    x = (c1 - (y1*y) ) / x1;

    clearScreen();
    printf("X = %d \t Y = %d\n" , x , y);
}

void solveThreeVarEquation()
{
    int x1 , y1 , z1 , c1 , x2 , y2 , z2 , c2 , x3 , y3 , z3 , c3;
    int ny1 , nz1 , nc1 , ny2 , nz2 , nc2;

    printf("X1: ");
    scanf("%d" , &x1);
    printf("Y1: ");
    scanf("%d" , &y1);
    printf("Z1: ");
    scanf("%d" , &z1);
    printf("C1: ");
    scanf("%d" , &c1);
    printf("X2: ");
    scanf("%d" , &x2);
    printf("Y2: ");
    scanf("%d" , &y2);
    printf("Z2: ");
    scanf("%d" , &z2);
    printf("C2: ");
    scanf("%d" , &c2);
    printf("X3: ");
    scanf("%d" , &x3);
    printf("Y3: ");
    scanf("%d" , &y3);
    printf("Z3: ");
    scanf("%d" , &z3);
    printf("C3: ");
    scanf("%d" , &c3);

    //reduce 1 and 2

    int temp = x1;
    int oy1 = y1 * x2;
    int oz1 = z1 * x2;
    int oc1 = c1 * x2;
    x2 *= temp;
    y2 *= temp;
    z2 *= temp;
    c2 *= temp; 

    ny1 = oy1 - y2;
    nz1 = oz1 - z2;
    nc1 = oc1 - c2;

     //reduce 1 and 3

    int oy2 =y1 * x3;
    int oz2 = z1 * x3;
    int oc2 = c1 * x3;
    x3*= temp;
    y3 *= temp;
    z3 *= temp;
    c3 *= temp; 
    
    ny2 = oy2 - y3;
    nz2 = oz2 - z3;
    nc2 = oc2 - c3;

    //solve two resulting equations for y and z
    int  y , z , c;

    temp = ny1;

    ny1 *= ny2;
    nz1 *= ny2;
    nc1 *= ny2;
    
    ny2 *= temp;
    nz2 *= temp;
    nc2 *= temp;

    z = nz1 - nz2;
    c = nc1 - nc2;

    z = c/z;
    y = (nc1 - (nz1*z) ) / ny1;

    //subs z and y to get x
    int x = (c1 - (y1*y) - (z1*z)) /x1;
    clearScreen();
    printf("X: %d\tY: %d\tZ: %d\n" , x , y ,z);
}


int baseConv(int base, int target, int number) {
    
    int decimalNum = 0;
    int power = 0;
    if(base != 10) { // first convert to base 10
        while(number != 0) { 
            decimalNum += (number % 10) * pow(base , power++);
            number /= 10;  
        }

    }
    else decimalNum = number;
    
    //convert from base 10 to required base
    int result = 0;
    power = 1;
    
    if(target != 10){
            while(decimalNum != 0){
            int rem = decimalNum % target;
            result += rem*power;
            power *= 10;
            decimalNum /= target;
        }
    }
    else result = decimalNum;

    return result;
    
}

void matrixAddition(size_t rows , size_t cols ,double **matrix1 , double **matrix2, double **res){
    for(size_t i =0; i<rows ; i++){
        for(size_t j =0; j<cols ; j++){
            res[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    printMatrix(res , rows , cols);
}
void matrixSubtraction(size_t rows , size_t cols ,double **matrix1 , double **matrix2, double **res){
    
    for(size_t i =0; i<rows ; i++){
        for(size_t j =0; j<cols ; j++){
            res[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    printMatrix(res , rows , cols);
}

void matrixMultiplication(size_t *rows , size_t *cols ,double **matrix1 , double **matrix2, double **res){

    printf("matrix multiplication start\n");
    if(rows[0] == cols[1]) //compatible matrices
    {
        for(int i=0; i< rows[0]; i++)
        {
            for(int j=0; j < cols[1]; j++)
            {
                res[i][j] = 0;
                for(int k=0; k<cols[0]; k++)
                {
                    res[i][j] += matrix1[i][k] * matrix2[k][i];
                }
            }
        }   
    } 
    else printf("incompatible Matrix sizes\n");
    
    printMatrix(res , rows[0] , cols[1]);
}
void matrixDivision(size_t *rows , size_t *cols ,double **matrix1 , double **matrix2, double **res){

    printf("matrix multiplication start\n");
    if(rows[0] == cols[1]) //compatible matrices
    {
        for(int i=0; i< rows[0]; i++)
        {
            for(int j=0; j < cols[1]; j++)
            {
                res[i][j] = 0;
                for(int k=0; k<cols[0]; k++)
                {
                    res[i][j] += matrix1[i][k] / matrix2[k][i];
                }
            }
        }   
    } 
    else printf("incompatible Matrix sizes\n");
    
    printMatrix(res , rows[0] , cols[1]);
}

void printMatrix(double **res , size_t rows , size_t cols) {
    clearScreen();
    for(int i=0 ; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%lf " , res[i][j]);
        }
        printf("\n");
    }
}

