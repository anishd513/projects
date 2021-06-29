# -*- coding: utf-8 -*-
"""
Created on Sun Aug 30 19:35:49 2020

@author: Admin
"""

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
#data preprocessing
dataset=pd.read_csv("Admission_Predict.csv")
x=dataset.iloc[:,1:-1].values
y=dataset.iloc[:,-1:].values
from sklearn.model_selection import train_test_split
x_train,x_test,y_train,y_test=train_test_split(x,y,random_state=1,test_size=0.2)

##taking only deviation
from sklearn.preprocessing import StandardScaler
sc1=StandardScaler()
x_train[:,0:1]=sc1.fit_transform(x_train[:,0:1])
x_test[:,0:1]=sc1.transform(x_test[:,0:1])
sc2=StandardScaler()
x_train[:,1:2]=sc2.fit_transform(x_train[:,1:2])
x_test[:,1:2]=sc2.transform(x_test[:,1:2])
#implementaion of classification model

#multi regression 

from sklearn.linear_model import LinearRegression
lin_regressor=LinearRegression()
lin_regressor.fit(x_train,y_train)
y_pred=lin_regressor.predict(x_test)
#print(np.concatenate((y_pred.reshape(len(y_pred),1), y_test.reshape(len(y_test),1)),1))
cf_lin=(0.5/len(y_test))*np.sum(((y_test-y_pred))**2)
print(" \n\n cost funtion of linear regression \t ",cf_lin)


#polynomial regression
from sklearn.model_selection import train_test_split
x_train,x_test,y_train,y_test=train_test_split(x,y,random_state=1,test_size=0.2)
from sklearn.linear_model import LinearRegression
lin_reg1=LinearRegression()
from sklearn.preprocessing import PolynomialFeatures
poly=PolynomialFeatures(degree=3)
poly_train=poly.fit_transform(x_train)
poly_test=poly.fit_transform(x_test)
lin_reg1.fit(poly_train,y_train)
y_pred2=lin_reg1.predict(poly_test)
#print(np.concatenate((y_pred.reshape(len(y_pred),1), y_test.reshape(len(y_test),1)),1))
cf_pol=(0.5/len(y_test))*np.sum(((y_test-y_pred2))**2)
print("\n\n cost fuction of polynomial regression \t ",cf_pol)

#desicion tree
from sklearn.model_selection import train_test_split
x_train,x_test,y_train,y_test=train_test_split(x,y,random_state=1,test_size=0.2)
from sklearn.tree import DecisionTreeRegressor
regressor=DecisionTreeRegressor(random_state=0)
regressor.fit(x_train,y_train)
y_pred3=regressor.predict(x_test)
#print(np.concatenate((y_pred.reshape(len(y_pred),1), y_test.reshape(len(y_test),1)),1))
cf_dtr=(0.5/len(y_test))*np.sum(((y_test-y_pred3))**2)
print("\n\n cost function of Desicion Tree regression \t ",cf_dtr)


##best model
print(" \n\n multi-linear  regression has the least cost function hence least deviation from desired output \t \n\n\n")

##arrranging in ascending order
multi=np.concatenate((y_test.reshape(len(y_test),1), y_pred.reshape(len(y_pred),1)),1)
poly=np.concatenate((y_test.reshape(len(y_test),1), y_pred2.reshape(len(y_pred2),1)),1)
detree=np.concatenate((y_test.reshape(len(y_test),1), y_pred3.reshape(len(y_pred3),1)),1)
multi=np.sort(multi,axis=0)
poly=np.sort(poly,axis=0)
detree=np.sort(detree,axis=0)
##plotting ouptuts
#xaxis=np.arange(min(y_test),max(y_test),(max(y_test)-min(y_test))/len(y_test))


xaxis=np.arange(0,len(y_test))
plt.figure(1)
plt.plot(xaxis,np.sort(y_test,axis=0),color='black')
plt.scatter(xaxis,multi[:,1],color='blue')
plt.ylim([0.3,1])
plt.xlabel("serial number of input")
plt.ylabel("probabilty of predicted values of mulitlinear regressiom")
plt.title("multilinear regression")

plt.figure(2)
plt.plot(xaxis,np.sort(y_test,axis=0),color='black')
plt.scatter(xaxis,poly[:,1],color='red')
plt.xlabel("serial number of input")
plt.ylabel("probabilty of predicted values of polynomial regression")
plt.title("polynomial regression")
plt.ylim([0.3,1])


plt.figure(3)
plt.plot(xaxis,np.sort(y_test,axis=0),color='black')
plt.scatter(xaxis,detree[:,1],color='green')
plt.ylim([0.3,1])
plt.xlabel("serial number of input")
plt.ylabel("probabilty of predicted values of decision tree regression")
plt.title("decision tree regressison")

