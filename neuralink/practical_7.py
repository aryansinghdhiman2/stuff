import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
DATA_URL = 'http://socr.ucla.edu/docs/resources/SOCR_Data/SOCR_Data_Dinov_020108_HeightsWeights.html '
html_tables = pd.read_html(DATA_URL, header=0)

data_url=html_tables[0]
data_url.to_csv('data.csv', index=False)
df=pd.read_csv('data.csv')


# Convert weight from pounds to kilograms
df['weight_kg'] = df['Weight(Pounds)'] * 0.453592

df = df.drop(columns=['Height(Inches)', 'Weight(Pounds)'])
X = df['Height'].values
y = df['weight_kg'].values
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42) 

alpha = 0.001  # Learning rate
iterations = 1000  # Number of iterations for gradient descent
# Gradient Descent Algorithm
def gradient_descent(X, y, alpha, iterations):
    m = 0;
    c = 0;
    n = len(y)
    cost_history = []
    for i in range(iterations):
            y_pred = m*X + c
            error = y - y_pred
            
            m_grad = -(2/n) * np.sum(X*error)
            c_grad = -(2/n) * np.sum(error)
            
            
            m = m - alpha * m_grad
            c = c - alpha * c_grad
            
            # Calculate and store the cost
            cost = (1 /n) * np.sum(error**2)
            cost_history.append(cost)

    return (m ,c, cost_history)


m,c, cost_history = gradient_descent(X_train, y_train, alpha, iterations)
y_pred = m* X_test + c
plt.scatter(X_test, y_test, label='True values')
plt.plot(X_test, y_pred, color='red', label='Predictions')
plt.xlabel('Height (Feet)')
plt.ylabel('Weight (kg)')
plt.title('Linear Regression: Height vs Weight')
plt.legend()
plt.show()
