# -*- coding: utf-8 -*-
"""
Created on Fri Oct 16 21:23:39 2020

@author: Admin
"""

import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
dataset=pd.read_csv("Admission_Predict.csv")
x=dataset.iloc[:,1:-1].values
y=dataset.iloc[:,-1:].values
from sklearn.model_selection import train_test_split
x_train,x_test,y_train,y_test=train_test_split(x,y,random_state=1,test_size=0.2)

from sklearn.tree import DecisionTreeRegressor
regressor=DecisionTreeRegressor(random_state=0)
regressor.fit(x_train,y_train)
y_pred=regressor.predict(x_test)
#print(np.concatenate((y_pred.reshape(len(y_pred),1), y_test.reshape(len(y_test),1)),1))
cf_dtr=np.sum(abs((y_test-y_pred)))
print(cf_dtr)