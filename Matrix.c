#include <stdio.h>

#define MAX 10

// Function Prototypes
void inputMatrix(int matrix[MAX][MAX], int rows, int cols, char name);
void displayMatrix(int matrix[MAX][MAX], int rows, int cols);
void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int rows, int cols);
void multiplyMatrices(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int r1, int c1, int c2);
void transposeMatrix(int A[MAX][MAX], int T[MAX][MAX], int rows, int cols);

// Input Function
void inputMatrix(int matrix[MAX][MAX], int rows, int cols, char name)
{
    printf("\nEnter elements of Matrix %c (%dx%d):\n", name, rows, cols);

    for(int i = 0; i < rows; i++) 
    {
        for(int j = 0; j < cols; j++)
        {
            printf("[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Display Function
void displayMatrix(int matrix[MAX][MAX], int rows, int cols)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            printf("%5d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Addition Function
void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int rows, int cols)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Multiplication Function
void multiplyMatrices(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int r1, int c1, int c2)
{
    for(int i = 0; i < r1; i++)
    {
        for(int j = 0; j < c2; j++)
        {
            C[i][j] = 0;

            for(int k = 0; k < c1; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Transpose Function
void transposeMatrix(int A[MAX][MAX], int T[MAX][MAX], int rows, int cols)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            T[j][i] = A[i][j];
        }
    }
}

// Main Function
int main()
{
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX], T[MAX][MAX];
    int choice;
    int r1, c1, r2, c2;

    printf("========================================\n");
    printf(" Matrix Operations Program\n");
    printf("========================================\n");

    while(1)
    {
        printf("\n----- MENU -----\n");
        printf("1. Matrix Addition\n");
        printf("2. Matrix Multiplication\n");
        printf("3. Matrix Transpose\n");
        printf("4. Exit\n");

        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\n== Matrix Addition ==\n");

                printf("Enter rows and columns: ");
                scanf("%d %d", &r1, &c1);

                inputMatrix(A, r1, c1, 'A');
                inputMatrix(B, r1, c1, 'B');

                addMatrices(A, B, C, r1, c1);

                printf("\nMatrix A:\n");
                displayMatrix(A, r1, c1);

                printf("\nMatrix B:\n");
                displayMatrix(B, r1, c1);

                printf("\nResult (A + B):\n");
                displayMatrix(C, r1, c1);
                break;

            case 2:
                printf("\n== Matrix Multiplication ==\n");

                printf("Enter rows and columns of Matrix A: ");
                scanf("%d %d", &r1, &c1);

                printf("Enter rows and columns of Matrix B: ");
                scanf("%d %d", &r2, &c2);

                if(c1 != r2)
                {
                    printf("Error! Columns of A must equal Rows of B.\n");
                    break;
                }

                inputMatrix(A, r1, c1, 'A');
                inputMatrix(B, r2, c2, 'B');

                multiplyMatrices(A, B, C, r1, c1, c2);

                printf("\nResult (A x B):\n");
                displayMatrix(C, r1, c2);
                break;

            case 3:
                printf("\n== Matrix Transpose ==\n");

                printf("Enter rows and columns of Matrix A: ");
                scanf("%d %d", &r1, &c1);

                inputMatrix(A, r1, c1, 'A');

                transposeMatrix(A, T, r1, c1);

                printf("\nOriginal Matrix:\n");
                displayMatrix(A, r1, c1);

                printf("\nTranspose Matrix:\n");
                displayMatrix(T, c1, r1);
                break;

            case 4:
                printf("Thank you for using CodeAlpha Matrix Program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice! Please enter 1-4.\n");
        }
    }

    return 0;
}
