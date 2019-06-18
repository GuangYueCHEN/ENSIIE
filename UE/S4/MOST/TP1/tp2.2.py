import pandas as pd
import numpy  
import matplotlib.pylab as plt




fichier="/Users/pingguo/WTF/UE/S4/MOST/DonCAC40/DonCAC40/regularite-mensuelle-tgv-axes.csv"

'''
读取数据
'''
df = pandas.read_csv(fichier,sep=";")
#df=pandas.read_table(fichier,sep=";")
#print(df.head(25).values)


'''
按时间排序
'''
df=df.sort_values(by=[df.columns[0] , df.columns[1]])
#print(df[df.columns[0]].values)






'''
统计车站数量
'''
Dic={}  #  dictionnaire
# dic['clé']=valeur
# clé de dictionnaire = Nom de Gare (axe) 
# valeur de dictionnaire = nombre d'observations

for x in df[df.columns[2]].values:
    Dic[x]=list(df[df.columns[2]].values).count(x)

    
## ordonner le dictionnaire par les clés
#import collections 
#Dic=collections.OrderedDict(sorted(Dic.items(), key=lambda t: t[0]))
print(Dic)




'''
西站的Ponctualité Origine图表
'''
# pour l'axe Paris EST
Paris_Est=df[df[df.columns[2]].values=='Est']
print("Paris  EST : ",Paris_Est.columns[5])




fig = plt.figure()
ax1 = fig.add_subplot(111)
# cacher les cadres : haut et droit
ax1.spines['right'].set_visible(False)
ax1.spines['top'].set_visible(False)


ax1.xaxis.set_ticks_position('bottom')

plt.plot(Paris_Est[Paris_Est.columns[5]].values)
plt.show()





fig = plt.figure()
ax1 = fig.add_subplot(111)

# cacher les cadres : haut , droit et gauche
ax1.spines['right'].set_visible(False)
ax1.spines['left'].set_visible(False)
ax1.spines['top'].set_visible(False)


ax1.xaxis.set_ticks_position('bottom')
ax1.set_yticks([])

plt.hist(Paris_Est[Paris_Est.columns[5]].values , ec="white")
plt.show()