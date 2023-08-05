#from sympy.plotting import plot
from sympy import *
from math import ceil, pi

def build_trajectory(pos1=0, pos2=pi, t1=.5, t2=.5, res=50):

    out_T = t1/(res/2)
    ret_T = t2/(res/2)
    outbound_trajectory = pol_trajectory(t1, [pos1,pos2,0,0], out_T)
    return_trajectory = pol_trajectory(t2, [pos2,pos1,0,0], ret_T)
    outbound_traj_turns = [p/(2*pi) for p in outbound_trajectory]
    return_traj_turns = [p/(2*pi) for p in return_trajectory]

    return {"OUTBOUND":outbound_traj_turns,
            "RETURN": return_traj_turns,
            "OUT_PERIOD":out_T,
            "RET_PERIOD":ret_T}

def pol_trajectory(time, parameters, T):

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
    #plot(polinomial, xlim=(-.1*time, 1.1*time), ylim=(-pi,pi))

    setpointsArray = []
    setpoint = lambdify(t, polinomial, "numpy")
    for n in range(1,ceil(time/T)+1):
        setpointsArray.append(setpoint(n*T))
    return setpointsArray
