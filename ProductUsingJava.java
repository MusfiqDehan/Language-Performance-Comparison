public class ProductUsingJava {
    public static void main(String[] args) {
        int size;
        int rowA, columnA;
        int rowB, columnB;
        int storeA, storeB;

        int[] sizeOfMatrices = {16, 32, 64, 128, 256};

        int length = sizeOfMatrices.length;

        for (int n = 0; n < length; n++) {
            size = sizeOfMatrices[n];

            int matrixA[][] = new int[size][size];
            for (rowA = 0; rowA < size; rowA++) {
                for (columnA = 0; columnA < size; columnA++) {
                    storeA = columnA + 1;
                    matrixA[rowA][columnA] = storeA;
                }
            }

            int matrixB[][] = new int[size][size];
            for (rowB = 0; rowB < size; rowB++) {
                for (columnB = 0; columnB < size; columnB++) {
                    storeB = columnB + 1;
                    matrixB[rowB][columnB] = storeB;
                }
            }

            long start = System.nanoTime();

            int productAxB[][] = new int[size][size];
            int sum = 0;
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    for (int k = 0; k < size; k++) {
                        sum += matrixA[i][k] * matrixB[k][j];
                    }

                    productAxB[i][j] = sum;
                    sum = 0;
                }
            }

            long end = System.nanoTime();

            double time_taken = ((double)(end - start) / 1000000000);

            System.out.println("\nTime taken by " + size + " X " + size + " matrix is : " + time_taken);

        }
        
    }

}
