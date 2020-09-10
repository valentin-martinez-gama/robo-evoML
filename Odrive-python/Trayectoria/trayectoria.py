from sympy import *

def trayectoria(tiempo, parametros,T):
    matrixSize = len(parametros)
    t = Symbol('t')
    A =zeros(matrixSize, matrixSize)
    A[0,0] = 1
    for p in range(0, matrixSize):
        A[1,p] = t**p
    for d in range(3, matrixSize, 2):
        for c in range(0,matrixSize):
            A[d,c] = diff(A[1,c], t, round((d-1)/2))
    for f in range(2, matrixSize, 2):
        A[f,f-1] = factorial(f/2)

    numA =zeros(matrixSize, matrixSize);

    for i in range(0,matrixSize):
        for j in range(0,matrixSize):
            numA[i,j] = A[i,j].subs(t, tiempo)

    params = Matrix(parametros)
    c0 = 33
    c1 = 33
    solve_linear_system(numA.col_insert(matrixSize, params), c0,c1)
    print(c0)
    print(c1)
    print(A.shape)
    print(params.shape)
    return numA

B = trayectoria(10,[0,pi/2,0,0,0,0],1)
print(B)
