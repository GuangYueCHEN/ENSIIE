from math import *
from numpy import *
import scipy.special 

 
## question 3)
 
# Nom de fonction : comb
# Arguments :  k et N
# Retourne : (N k)
# 
def comb(k,N):
     return(math.factorial(N) / ( math.factorial(k)* math.factorial(N-k)));

# Nom de fonction : f
# Arguments : x
# Retourne : le maximum entre x-100 et 0
# 
def f(x):
    return(max(x-100,0));
    


# Nom de fonction : price1
# Arguments : N, rN, hN, bN, s et la fonction g
# Retourne : retourne le prix p(N)
#  

def price1(N,rN,hN,bN,s,g):
    pN =0
    qN = (rN - bN)/(hN - bN)
    for i in range(0,N+1):
        pN = pN+comb(i,N)*pow(qN,i)*pow(1-qN,N-i)*g(s*pow(1+hN,i)*pow(1+bN,N-i))

    return(1/pow(1+rN,N)*pN);

## question 4)
    
print(price1(10,0.02,0.05,-0.05,100,f))

## question 5)

# Nom de fonction : f2
# Arguments : x
# Retourne : le maximum entre x-95 et 0
# 
def f2(x):
    return(max(x-95,0));
    
# Nom de fonction : price2
# Arguments : N, rN, hN, bN, s et la fonction g
# Retourne : retourne le prix p(N)
#  
 
def price2(N, rN, hN, bN, s, g):
    matrice_tableau=zeros((N+1,N+1))
    qN = (rN - bN)/(hN - bN)  
          
    for i in range(0,N+1):
        matrice_tableau[i][N] = g(s*pow(1 + hN, N - i)*pow(1+bN,i)) 

    for j in range (N,-1,-1):
        for i in range (0,j):
            matrice_tableau[i][j-1] = (1/(1+rN))*((1-qN)*matrice_tableau[i+1][j] + qN*matrice_tableau[i][j])

    return(matrice_tableau[0][0]);
    
print(price2(3, 0.02, 0.05, -0.05, 100, f2))

## question 7)

print("question 7")
print(price1(13,0.03,0.05,-0.05,100,f))
    
print(price2(13,0.03,0.05,-0.05,100,f))


## question 9)

# Nom de fonction : c
# Arguments : N, rN, hN, bN, s et la fonction g
# Retourne : 
#  

def converture(N, rN, hN, bN, s, g ):
    matrice_tableau=zeros((N+1,N+1))
    qN = (rN - bN)/(hN - bN)  
          
    for i in range(0,N+1):
        matrice_tableau[i][N] = g(s*pow(1 + hN, N - i)*pow(1+bN,i)) 

    for j in range (N,-1,-1):
        for i in range (0,j):
            matrice_tableau[i][j-1] = (1/(1+rN))*((1-qN)*matrice_tableau[i+1][j] + qN*matrice_tableau[i][j])


    alpha=zeros((N,N))
    beta=zeros((N,N))
    gama=(1+bN)/(1+hN)

    for i in range(0,N):
        for j in range(0,i+1):
            alpha[i][j]=(matrice_tableau[j][i+1]-matrice_tableau[j+1][i+1])/(s*(hN-bN)*(pow(1+hN,i-j)*pow(1+bN,j-1)))
            beta[i][j]=(matrice_tableau[j+1][i+1]*(1+hN)-matrice_tableau[j][i+1]*(1+bN))/((hN-bN)*(pow(1+rN,i)*s))
            
    return(alpha,beta);

## question 10)

#N = 2, s = 100, rN = 0.03, hN = 0.05, bN = −0.05, f(x) = max(x − 100,0)

[A,B]=converture(2,0.03,0.05,-0.05,100,f);
print("data=0")
print("α=")
print(A[0][0])
print("β=")
print(B[0][0])

print("data=1")
print("α1=")
print(A[1][0])
print("β1=")
print(B[1][0])
print("α2=")
print(A[1][1])
print("β2=")
print(B[1][1])