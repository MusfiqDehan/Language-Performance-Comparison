from time import perf_counter

sizeOfMatrices = [16, 32, 64, 128, 256]

for p in range(len(sizeOfMatrices)):
    size = sizeOfMatrices[p]

    matrixA = [[2 for i in range(size)] for j in range(size)]

    matrixB = [[2 for i in range(size)] for j in range(size)]

    start = perf_counter()

    productAxB = [[0 for i in range(size)] for j in range(size)]

    for i in range(size):
        for j in range(size):
            productAxB[i][j] = 0
            for k in range(size):
                productAxB[i][j] += matrixA[i][k] * matrixB[k][j]

    end = perf_counter()
    time_taken = end - start

    print("\nTime spend to execute " + str(size) +" X " + str(size) + " matrix is : " + str(time_taken) + " sec\n")
