# %%
import pandas as pd
import numpy as np
from matplotlib import pyplot as plt

# %%
from pint import UnitRegistry
ureg = UnitRegistry()

# %%
link = "http://socr.ucla.edu/docs/resources/SOCR_Data/SOCR_Data_Dinov_020108_HeightsWeights.html"
df = pd.read_html(link,header=0,index_col=0)[0]

# %%
def convert(s):
    feet = ureg.convert(s["Height(Inches)"],"inch","feet")
    inch = np.round(feet % 1,5)
    feet = int(feet)
    
    s["Height(Inches)"] = inch
    s["Height(Feet)"] = feet
    s["Weight(Kilogram)"] = ureg.convert(s["Weight(Pounds)"],"pound","kilogram")
    return s

df = df.apply(convert,axis=1)

# %%
df = df.drop(["Weight(Pounds)"],axis=1)

# %%
X = df[["Height(Inches)","Height(Feet)"]].values
X_b = np.concatenate([np.ones((X.shape[0],1)),X],axis=1)

# %%
y = df["Weight(Kilogram)"].values

# %%
theta_best = np.linalg.inv(X_b.T.dot(X_b)).dot(X_b.T).dot(y)

# %%
intercept, *coef = theta_best
print(f"Intercept: {intercept}")
print(f"Coefficients: {coef}")

# %%
y_pred = X_b.dot(theta_best)

# %%
from sklearn.metrics import mean_squared_error
print(f"Root Mean Squared Error {np.sqrt(mean_squared_error(y,y_pred))}")

# %%
plt.scatter(y,y_pred)
plt.xlabel("Original Weight")
plt.ylabel("Predicted Weight")
plt.show()