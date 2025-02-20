def jacobi_method(A, b, x_init, max_iterations, tol=1e-10):
    n = len(b)
    x = x_init[:]  
    x_new = [0] * n

    for _ in range(max_iterations):
        for i in range(n):
            
            sum_except_i = 0
            for j in range(n):
                if j != i:
                    sum_except_i += A[i][j] * x[j]
            x_new[i] = (b[i] - sum_except_i) / A[i][i]
        
        x = x_new[:]

    return x_new, max_iterations

A = [
    [5, -2, 3],
    [-3, 9, 1],
    [2, -1, -7]
]
b = [-1, 2, 3]
x_init = [0, 0, 0] 

maxiterations = int(input("Masukkan jumlah iterasi maksimum: "))

solusi, iterasi = jacobi_method(A, b, x_init, maxiterations)

print("Solusi:")
for value in solusi:
    print(value)

print("Jumlah iterasi:", iterasi)