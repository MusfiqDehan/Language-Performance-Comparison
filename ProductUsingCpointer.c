#include <stdio.h>
#include <time.h>

int main()
{
    int size;
    int rowA, columnA;
    int rowB, columnB;
    int storeA, storeB;
    clock_t startTime, endTime;

    int sizeOfMatrices[] = {16, 32, 64, 128, 256, 512};

    int length = sizeof(sizeOfMatrices) / sizeof(sizeOfMatrices[0]);

    for (int n = 0; n < length; n++)
    {
        size = sizeOfMatrices[n];

        int matrixA[size][size];
        for (rowA = 0; rowA < size; rowA++)
        {
            for (columnA = 0; columnA < size; columnA++)
            {
                storeA = columnA + 1;
                matrixA[rowA][columnA] = storeA;
            }
        }

        int matrixB[size][size];
        for (rowB = 0; rowB < size; rowB++)
        {
            for (columnB = 0; columnB < size; columnB++)
            {
                storeB = columnB + 1;
                matrixB[rowB][columnB] = storeB;
            }
        }

        startTime = clock();

        int productAxB[size][size], sum = 0;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                for (int k = 0; k < size; k++)
                {
                    sum += ((*(*(matrixA + i) + k) * (*(*(matrixB + k) + j))));
                }

                productAxB[i][j] = sum;
                sum = 0;
            }
        }

        endTime = clock();

        double time_taken = (double)(endTime - startTime) / CLOCKS_PER_SEC;

        printf("\nTime spend to execute %d X %d matrix is : %lf sec\n", size, size, time_taken);
    }

    return 0;
}