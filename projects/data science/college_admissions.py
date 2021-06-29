import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

dataset=pd.readcsv("Admission_Predict.csv")
x=dataset.iloc[:,1:-1].values
y=dataset.iloc[:,-1].values
