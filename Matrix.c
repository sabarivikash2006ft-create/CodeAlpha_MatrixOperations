#include <stdio.h>

#define MAX 10

// Function to input a matrix
void inputMatrix(int matrix[MAX][MAX], int rows, int cols)
{
    int i, j;

    printf("Enter matrix elements:\n");

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[MAX][MAX], int rows, int cols)
{
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function for matrix addition
void addMatrix(int A[MAX][MAX], int B[MAX][MAX],
               int result[MAX][MAX], int rows, int cols)
{
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function for matrix multiplication
void multiplyMatrix(int A[MAX][MAX], int B[MAX][MAX],
                    int result[MAX][MAX],
                    int r1, int c1, int c2)
{
    int i, j, k;

    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            result[i][j] = 0;

            for (k = 0; k < c1; k++)
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Function for matrix transpose
void transposeMatrix(int A[MAX][MAX], int result[MAX][MAX],
                     int rows, int cols)
{
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            result[j][i] = A[i][j];
        }
    }
}

int main()
{
    int A[MAX][MAX], B[MAX][MAX], result[MAX][MAX];
    int r1, c1, r2, c2;
    int choice;

    printf("===== MATRIX OPERATIONS =====\n");
    printf("1. Matrix Addition\n");
    printf("2. Matrix Multiplication\n");
    printf("3. Matrix Transpose\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            // Matrix Addition
            printf("Enter rows and columns: ");
            scanf("%d %d", &r1, &c1);

            printf("Enter Matrix A:\n");
            inputMatrix(A, r1, c1);

            printf("Enter Matrix B:\n");
            inputMatrix(B, r1, c1);

            addMatrix(A, B, result, r1, c1);

            printf("Result of Addition:\n");
            displayMatrix(result, r1, c1);
            break;

        case 2:
            // Matrix Multiplication
            printf("Enter rows and columns of Matrix A: ");
            scanf("%d %d", &r1, &c1);

            printf("Enter rows and columns of Matrix B: ");
            scanf("%d %d", &r2, &c2);

            if (c1 != r2)
            {
                printf("Matrix multiplication is not possible.\n");
                break;
            }

            printf("Enter Matrix A:\n");
            inputMatrix(A, r1, c1);

            printf("Enter Matrix B:\n");
            inputMatrix(B, r2, c2);

            multiplyMatrix(A, B, result, r1, c1, c2);

            printf("Result of Multiplication:\n");
            displayMatrix(result, r1, c2);
            break;

        case 3:
            // Matrix Transpose
            printf("Enter rows and columns: ");
            scanf("%d %d", &r1, &c1);

            printf("Enter Matrix:\n");
            inputMatrix(A, r1, c1);

            transposeMatrix(A, result, r1, c1);

            printf("Transpose of Matrix:\n");
            displayMatrix(result, c1, r1);
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
