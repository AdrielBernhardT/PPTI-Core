def jacobi_method(A, b, x_init, tol=1e-10, max_iterations=1):
    n = len(b)
    x = x_init[:]  
    x_new = [0] * n

    for iteration in range(max_iterations):
        for i in range(n):
            
            sum_except_i = 0
            for j in range(n):
                if j != i:
                    sum_except_i += A[i][j] * x[j]
            x_new[i] = (b[i] - sum_except_i) / A[i][i]
        
        max_diff = max(abs(x_new[i] - x[i]) for i in range(n))
        x = x_new[:]

    return x_new, max_iterations

A = [
    [5 , -2, 3],
    [-3, 9, 1],
    [2, -1, -7]
]
b = [-1, 2, 3]
x_init = [0, 0, 0] 

solusi, iterasi = jacobi_method(A, b, x_init)

print("Solusi:")
for value in solusi:
    print(value)

print("Jumlah iterasi:", iterasi)