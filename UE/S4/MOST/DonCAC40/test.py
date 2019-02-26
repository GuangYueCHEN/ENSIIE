

import numpy

x=numpy.array([2,1,5])

dim=x.shape


#x=numpy.random.randint(-5,7,[4,3])

#print(x)
#print(x.T)#转置
#s1=numpy.sum(x,axis=1)#axis 0 行取和 1 列求和
#print(s1)


#for i in range(2,11):
  #  print(i)
  
  
#for i in range(2,11,2):
#    print(i)
  
  
  
'''     
计数
#x6=numpy.random.normal(7,4,41)
#indice=[i for i in range(len(x6)) if x6[i]>10]

#print(x6)
#print(indice)
#print(len(indice))
'''

'''
import random

x7=[3+(7-3)*random.random() for _ in range(14)]
print(random.random())
'''

'''
创建函数
def normale_simul(mu,sigma2,taille):
    import numpy
    import math
    sig=math.sqrt(sigma2)
    return numpy.random.normal(mu,sig,taille)
    
x8=normale_simul(-1,14,15)
print(x8)
'''


'''
返回两个值 打印
def deux(data):
    import numpy
    return numpy.mean(data),
    numpy.var(data)
    
    
data=[1,5,6,3,2,5,6,3,5]
res=deux(data)
print('%.4f'%res[0])
'''




'''
x10=numpy.random.randint(-5,6,[3,3])
print(x10)
D=numpy.linalg.det(x10)
print(D)
#行列式
'''


'''
#解方程Ax=B
numpy.linalg.solve(A,B)
'''






