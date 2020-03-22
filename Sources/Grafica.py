# -- coding: utf-8 --
"""
Created on Fri Mar 20 17:28:06 2020
@author: miguelangel
"""
import pandas as pd
import numpy as np
from matplotlib import pyplot as pltb
from matplotlib import pyplot as pltb

datIAVL = pd.read_csv('InsertionTimes.txt',delim_whitespace=True)
x=datIAVL.ix[:,0]
y=datIAVL.ix[:,1]
pltb.plot(x,y, 'ro')
pltb.ylabel('Tiempo en nanosegundos')
pltb.xlabel('Numeros')
print (datIAVL)
pltb.show
pltb.savefig('InsertionTimesAVL.png')
pltb.clf()

datIB = pd.read_csv('InsertionTimesB.txt',delim_whitespace=True)
x=datIB.ix[:,0]
y=datIB.ix[:,1]
pltb.plot(x,y, 'o')
pltb.ylabel('Tiempo en nanosegundos')
pltb.xlabel('Numeros')
print (datIB)
pltb.show
pltb.savefig('InsertionTimesB.png')
pltb.clf()

dataSAVL = pd.read_csv('SearchTimes.txt',delim_whitespace=True)
x=dataSAVL.ix[:,0]
y=dataSAVL.ix[:,1]
pltb.plot(x,y, 'ro')
pltb.ylabel('Tiempo en nanosegundos')
pltb.xlabel('Numeros')
print (dataSAVL)
pltb.show
pltb.savefig('SearchTimesAVL.png')
pltb.clf()

dataSB = pd.read_csv('SearchTimesB.txt',delim_whitespace=True)
x=dataSB.ix[:,0]
y=dataSB.ix[:,1]
pltb.plot(x,y, 'o')
pltb.ylabel('Tiempo en nanosegundos')
pltb.xlabel('Numeros')
print (dataSB)
pltb.show
pltb.savefig('SearchTimesB.png')
pltb.clf()

dataEAVL = pd.read_csv('EliminationTimes.txt',delim_whitespace=True)
x=dataEAVL.ix[:,0]
y=dataEAVL.ix[:,1]
pltb.plot(x,y, 'ro')
pltb.ylabel('Tiempo en nanosegundos')
pltb.xlabel('Numeros')
print (dataEAVL)
pltb.show
pltb.savefig('EliminationTimesAVL.png')
pltb.clf()

dataEB = pd.read_csv('EliminationTimesB.txt',delim_whitespace=True)
x=dataEB.ix[:,0]
y=dataEB.ix[:,1]
pltb.plot(x,y, 'o')
pltb.ylabel('Tiempo en nanosegundos')
pltb.xlabel('Numeros')
print (dataEB)
pltb.show
pltb.savefig('EliminationTimesB.png')
pltb.clf()



