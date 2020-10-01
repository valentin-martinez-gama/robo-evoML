#from sympy.plotting import plot
from sympy import *
from math import ceil, pi

def pol_trayectory(time, parameters, T = .01):

    matrixSize = len(parameters)
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
            numA[i,j] = A[i,j].subs(tfin, time)

    params = Matrix(parameters)
    coefs = symbols('a0:%d'%matrixSize)
    sols  = solve_linear_system(numA.col_insert(matrixSize, params), *coefs)

    polinomial = 0
    t = Symbol('t')
    for c in range(0, matrixSize):
        polinomial += sols[coefs[c]]*t**c

    plot(polinomial, xlim=(-.1*time, 1.1*time), ylim=(-pi,pi))

    setpointsArray = []
    setpoint = lambdify(t, polinomial, "numpy")
    for n in range(0,ceil(time/T)):
        setpointsArray.append(setpoint(n*T))

    return setpointsArray

if(__name__ == '__main__'):
    print(pol_trayectory(3, [0,pi/2,0,-pi/4,0,0], .01))
