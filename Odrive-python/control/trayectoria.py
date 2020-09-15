#from sympy.plotting import plot
from sympy import *
from math import ceil

def trayectoria(tiempo, parametros, T = .01):

    matrixSize = len(parametros)
    tfin = Symbol('tfin')
    A =zeros(matrixSize, matrixSize)

    A[0,0] = 1
    for p in range(0, matrixSize):
        A[1,p] = tfin**p
    for d in range(3, matrixSize, 2):
        for c in range(0,matrixSize):
            A[d,c] = diff(A[1,c], tfin, round((d-1)/2))
    for f in range(2, matrixSize, 2):
        A[f,f-1] = factorial(f/2)

    numA =zeros(matrixSize, matrixSize);
    for i in range(0,matrixSize):
        for j in range(0,matrixSize):
            numA[i,j] = A[i,j].subs(tfin, tiempo)

    params = Matrix(parametros)
    coefs = symbols('a0:%d'%matrixSize)
    sols  = solve_linear_system(numA.col_insert(matrixSize, params), *coefs)

    polinomio = 0
    t = Symbol('t')
    for c in range(0, matrixSize):
        polinomio += sols[coefs[c]]*t**c

    plot(polinomio, xlim=(-.1*tiempo, 1.1*tiempo), ylim=(-pi,pi))

    setpointsArray = []
    setpoint = lambdify(t, polinomio, "numpy")
    for n in range(0,ceil(tiempo/T)):
        setpointsArray.append(setpoint(n*T))

    return setpointsArray

if(__name__ == '__main__'):
    print(trayectoria(3, [0,pi/2,0,-pi/4,0,0] , .01))
