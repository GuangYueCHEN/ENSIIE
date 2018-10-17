from math import *
from numpy import *
import scipy.special 
import matplotlib.pyplot as plt
import builtins as bul
from scipy.stats import norm
from numpy.linalg import inv
import numpy as np;
 
## question 20)

x=[i for i in range(0,1000)]
def explicites(K,r,sigma,T,L,M,N):
    P1=zeros(M)
    Yn=zeros(M)
    dT=T/N
    for i in  range(0,M):
        P1[i]=max(K-i,0)
    P=mat(P1).T
    matrice_A=zeros((M,M))
    for i in  range(0,M-1):
        matrice_A[i+1][i]=r*(i+1)-1/2*pow(sigma,2)*pow(i+1,2)
        matrice_A[i][i+1]=-1/2*pow(sigma,2)*pow(i+1,2)
        matrice_A[i][i] = 1/dT + pow(sigma,2)*pow(i+1,2)-r*(i+1)+r
        
    matrice_A[M-1][M-1]= 1/dT + pow(sigma,2)*pow(M,2) - M*r + r
    A=mat(matrice_A)

    
    for n in range(N,-1,-1):
        Yn[0]=K*exp(r*(n-N))*(r-1/2*pow(sigma,2))
        Y=mat(Yn).T
        Px=A**(-1) *((1/dT)*P-Y)
        P=Px
    return(P)
 # K = 100, r = 0.04, σ = 0.1, T = 1, L = 4K et M = 1000   
result2 = explicites(100,0.04,0.1,1,400,1000,10)
plt.plot(result2,color='b')
plt.show()    


def implicites(K,r,sigma,T,L,M,N):
    P1=zeros(M)
    Yn=zeros(M)
    dT=T/N
    for i in  range(0,M):
        P1[i]=max(K-i,0)
    P=mat(P1).T
    matrice_A=zeros((M,M))
    for i in  range(0,M-1):
        matrice_A[i+1][i]=1/2*pow(sigma,2)*pow(i+1,2)-r*(i+1)
        matrice_A[i][i+1]=1/2*pow(sigma,2)*pow(i+1,2)
        matrice_A[i][i] = -(1/dT + pow(sigma,2)*pow(i+1,2)-r*(i+1)+r)
        
    matrice_A[M-1][M-1]= -(1/dT + pow(sigma,2)*pow(M,2) - M*r + r)
    A=mat(matrice_A)

    
    for n in range(N,-1,-1):
        Yn[0]=K*exp(r*(n-N))*(1/2*pow(sigma,2)-r)
        Y=mat(Yn).T
        Px=A*P+Y
        P=Px*dT
    return(P)
result3 = implicites(100,0.04,0.1,1,400,1000,10)
plt.plot(result3,color='r')
plt.show()  

def Crank(K,r,sigma,T,L,M,N):
    P1=zeros(M)
    Yn=zeros(M)
    Yn1=zeros(M)
    dT=T/N
    for i in  range(0,M):
        P1[i]=max(K-i,0)
    P=mat(P1).T
    matrice_A=zeros((M,M))
    matrice_B=zeros((M,M))
    for i in  range(0,M-1):
        matrice_A[i+1][i]=1/2*pow(sigma,2)*pow(i+1,2)-r*(i+1)
        matrice_B[i+1][i]=-1/2*pow(sigma,2)*pow(i+1,2)+r*(i+1)
        matrice_A[i][i+1]=1/2*pow(sigma,2)*pow(i+1,2)
        matrice_B[i][i+1]=1/4*pow(sigma,2)*pow(i+1,2)+1/4*r*(i+1)
        matrice_A[i][i] = -(1/dT + pow(sigma,2)*pow(i+1,2)-r*(i+1)+r)
        matrice_B[i][i] = -(1/dT)+1/2*pow(sigma,2)*pow(i+1,2)
    matrice_A[M-1][M-1]= -(1/dT + pow(sigma,2)*pow(M,2) - M*r + r)
    matrice_B[M-1][M-1]= -(1/dT)+1/2*pow(sigma,2)*pow(M+1,2)
    A=mat(matrice_A)
    B=mat(matrice_B)
    
    for n in range(N,-1,-1):
        Yn[0]=K*exp(r*(n-N))*(1/4*pow(sigma,2)-r/4)
        Yn1[0]=K*exp(r*(n+1-N))*(1/4*pow(sigma,2)-r/4)
        Y=mat(Yn).T
        Y1=mat(Yn1).T
        Px=A.I*(B*P-Y-Y1)
        P=Px
    return(P)
result1 = Crank(100,0.04,0.1,1,400,1000,10)
plt.plot(result1,color='r')
plt.show() 