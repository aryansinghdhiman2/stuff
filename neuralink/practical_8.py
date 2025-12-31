import numpy as np
import matplotlib.pyplot as plt

def hebbian_learning(X, y, epochs=10, lr=0.1):
    weights = np.zeros(X.shape[1])
    for epoch in range(epochs):
        for i in range(X.shape[0]):
            weights += lr * X[i] * y[i]
    return weights

def plot_decision_boundary_AND(X, y, weights, title):
    plt.figure()
    plt.title(title)
    plt.scatter(X[:, 1], X[:, 2], c=y, cmap='bwr')

 # Generate values for x1
    x1 = np.linspace(-3, 3, 100)
    # Compute corresponding x2 values using the equation x2 = -x1 + 1
    x2 = -x1 + 1
    # Plot the decision boundary
    plt.plot(x1, x2, label='Decision Boundary: x2 = -x1 + 1')
    plt.show()

def plot_decision_boundary_OR(X, y, weights, title):
    plt.figure()
    plt.title(title)
    plt.scatter(X[:, 1], X[:, 2], c=y, cmap='bwr')
    # Generate values for x1
    x1 = np.linspace(-3, 3, 100)
    # Compute corresponding x2 values using the equation x2 = -x1 + 1
    x2 = -x1 - 1
    # Plot the decision boundary
    plt.plot(x1, x2, label='Decision Boundary: x2 = -x1 - 1')
    plt.show()
    # Input data for AND and OR gates

X = np.array([
 [1, -1, -1],
 [1, -1, 1],
 [1, 1, -1],
 [1, 1, 1]
])
# Labels for AND gate
y_and = np.array([-1, -1, -1, 1])

# Labels for OR gate
y_or = np.array([-1, 1, 1, 1])

# Train Hebbian model for AND gate
weights_and = hebbian_learning(X, y_and)
print("Weights for AND function:", weights_and)

# Train Hebbian model for OR gate
weights_or = hebbian_learning(X, y_or)
print("Weights for OR function:", weights_or)

# Plot decision boundaries
plot_decision_boundary_AND(X, y_and, weights_and, 'Decision Boundary for AND Function')
plot_decision_boundary_OR(X, y_or, weights_or, 'Decision Boundary for OR Function')
