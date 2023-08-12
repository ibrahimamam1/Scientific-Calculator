#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operations.h"
#include "functions.h"


int main(int argc , char *argv[])
{
    char operation[MAX_OPERATION];

    if(argc > 1)
    {
        strcpy(operation, argv[1]);
    }
    else scanf("%s" , operation);
    lowerCase(operation);

    if(!(strcmp(operation, "equation")) || !(strcmp(operation, "eqn")))
    {
        int op;
        printf("\n1- ax + by =  c");
        printf("\n2- ax + by + cz =  d\n");
        scanf("%d" , &op);
        switch (op)
        {
            case 1:
                solveTwoVarEquation();
                break;
            case 2:
                solveThreeVarEquation();
                break;
            default:
                printf("Invalid input\n");
                break;    
                    
        }
    }
    else if(!(strcmp(operation, "base")) || !(strcmp(operation, "base conversion")))
    {
        int base , target , number;
        printf("Source base: ");
        scanf("%d" , &base);
        printf("Target base: ");
        scanf("%d" , &target);
        printf("Number: ");
        scanf("%d" , &number);
        clearScreen();
        printf("%d\n" , baseConv(base, target, number));

    }
    else if(!(strcmp(operation, "matrix")))
    {
        printf("\n1- Matrix addition\n");
        printf("2- Matrix subtraction\n");
        printf("3- Matrix multiplication\n");
        printf("4- Matrix division\n");

        int op;
        scanf("%d" , &op);
        clearScreen();

        size_t n_rows[2] , n_cols[2];
        double **matrix1;
        double **matrix2;
        double **res;
        if(op > 0 && op < 3){ //add and sub
            printf("Enter number of n_rows (space) number of n_cols : ");
            scanf("%ld %ld" , n_rows , n_cols);

            matrix1 = malloc(n_rows[0] * sizeof(size_t));

            for (int i=0; i<n_rows[0]; i++) {
                matrix1[i] = malloc(n_cols[0] * sizeof(size_t));
            }
 
            matrix2 = malloc(n_rows[0] * sizeof(size_t));

            for (int i=0; i<n_rows[0]; i++) {
                matrix2[i] = malloc(n_cols[0] * sizeof(size_t));
            }

            printf("Enter elements of matrix 1 : ");
            scanMatrix(matrix1 , n_rows[0] , n_cols[0]);
            printf("Enter elements of matrix 2 : ");
            scanMatrix(matrix2 , n_rows[0] , n_cols[0]);

            res = malloc(n_rows[0] * sizeof(size_t));

            for (int i=0; i<n_rows[0]; i++) {
                res[i] = malloc(n_cols[0] * sizeof(size_t));
            }
        }
        

        else {
            printf("Enter number of rows (space) number of cols for matrix 1: ");
            scanf("%ld %ld" , n_rows , n_cols);

            matrix1 = malloc(n_rows[0] * sizeof(size_t));
            for (int i=0; i<n_rows[0]; i++) {
                matrix1[i] = malloc(n_cols[0] * sizeof(size_t));
            }
            printf("Enter elements of matrix1 (One row at a time) : ");
            scanMatrix(matrix1, n_rows[0], n_cols[0]);

            printf("\nEnter number of rows (space) number of cols for matrix 2: ");
            scanf("%ld %ld" , &n_rows[1] , &n_cols[1]);

            matrix2 = malloc(n_rows[1] * sizeof(size_t));
            for (int i=0; i<n_rows[1]; i++) {
                matrix2[i] = malloc(n_cols[1] * sizeof(size_t));
            }
            printf("Enter elements of matrix2 (One row at a time): ");
            scanMatrix(matrix2, n_rows[1], n_cols[1]);

            res = malloc(n_cols[1] * sizeof(size_t));

            for (int i=0; i<n_rows[0]; i++) {
                res[i] = malloc(n_rows[0] * sizeof(size_t));
            }
        }
        switch (op) {
            case 1:
                matrixAddition(n_rows[0], n_cols[0], matrix1, matrix2, res);
                break;
            case 2:
                matrixSubtraction(n_rows[0], n_cols[0], matrix1, matrix2, res);
                break;
            case 3:
                matrixMultiplication(n_rows , n_cols , matrix1 , matrix2 , res);
                break;
            case 4:
                 matrixDivision(n_rows , n_cols , matrix1 , matrix2 , res);
                break;                
        }
        free(res);
        free(matrix1);
        free(matrix2);
    }
    else if(!(strcmp(operation, "help")) || !(strcmp(operation, "h"))) displayHelp();
    else
    {
        infixToPostfix(operation);
        printf("\n%.2lf" , evaluatePostfix() );
    }
}
