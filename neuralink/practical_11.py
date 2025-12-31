import numpy as np
import matplotlib.pyplot as plt


# Function for calculating weighted sum
def calc_weighted_sum(x1, x2, b):
    return x1 + x2 + b


def activation(ws):
    if ws > 0:
        return 1
    else:
        return 0


# XOR function
def xor(x):
    # Hidden layer
    O1 = [activation(calc_weighted_sum(x1, x2, -1.5)) for x1, x2 in x]
    O1 = np.array(O1)
    O2 = [activation(calc_weighted_sum(x1, x2, -0.5)) for x1, x2 in x]
    O2 = np.array(O2)
    # Output layer
    O3 = [activation(calc_weighted_sum(-2 * o1, o2, -0.5)) for o1, o2 in zip(O1, O2)]
    O3 = np.array(O3)
    return O3


# Input vector
x = np.array(
    [
        [0, 0],
        [0, 1],
        [1, 0],
        [1, 1],
    ]
)
print(f"Input vector : \n {x}\n")
print(f"Output : {xor(x)}")
# Create a mesh grid of values
xx, yy = np.meshgrid(np.linspace(-0.5, 1.5, 200), np.linspace(-0.5, 1.5, 200))
zz = xor(np.c_[xx.ravel(), yy.ravel()])
zz = zz.reshape(xx.shape)
# Plot the decision boundary
plt.contourf(xx, yy, zz, cmap=plt.cm.RdYlGn, alpha=0.65)
plt.scatter(x[:, 0], x[:, 1], c=xor(x), cmap=plt.cm.RdYlGn, s=100)
plt.title("XOR Gate Decision Boundary")
plt.xlabel("X1")
plt.ylabel("X2")
plt.show()
