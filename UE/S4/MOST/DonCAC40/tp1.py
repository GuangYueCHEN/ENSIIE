import matplotlib.pyplot as plt
import numpy 

def Mouvement_Brownien(nb_point=1000):
    z=numpy.random.normal(0,1,nb_point)
    w=numpy.zeros(nb_point)
    for i in range(1,nb_point,1):
        w[i]=w[i-1]+z[i]
    return w


fig=plt.figure(figsize=(8,5))
ax=fig.add_subplot(111)
ax.spines['right'].set_visible(False)
ax.spines['top'].set_visible(False)  #修改边界
    
'''
for _ in range(3):
    plt.plot(Mouvement_Brownien())
plt.show()
'''

plt.hist(Mouvement_Brownien(),ec='white',color=[0.95,0.27,0.99])
plt.show()


