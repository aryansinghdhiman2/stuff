import numpy as np


# Sigmoid activation function and its derivative
def sigmoid(x):
    return 1 / (1 + np.exp(-x))


def sigmoid_derivative(x):
    return x * (1 - x)


# Initialize weights and biases
def initialize_weights(layers):
    weights = []
    biases = []
    for i in range(len(layers) - 1):
        weight_matrix = np.random.uniform(-1, 1, (layers[i + 1], layers[i]))
        bias_vector = np.random.uniform(-1, 1, (layers[i + 1], 1))
        weights.append(weight_matrix)
        biases.append(bias_vector)
    return weights, biases


# Forward pass
def forward_propagation(x, weights, biases):
    activations = [x]
    zs = []  # Store weighted inputs for backpropagation
    for i in range(len(weights)):
        z = np.dot(weights[i], activations[-1]) + biases[i]
        zs.append(z)
        activation = sigmoid(z)
        activations.append(activation)
    return activations, zs


# Backward pass
def backward_propagation(y, activations, zs, weights, biases):
    gradients_w = [np.zeros(w.shape) for w in weights]
    gradients_b = [np.zeros(b.shape) for b in biases]

    # Output error (for the last layer)
    delta = (activations[-1] - y) * sigmoid_derivative(activations[-1])
    gradients_b[-1] = delta
    gradients_w[-1] = np.dot(delta, activations[-2].T)

    # Backpropagate the error
    for l in range(2, len(weights) + 1):
        z = zs[-l]
        sp = sigmoid_derivative(sigmoid(z))
        delta = np.dot(weights[-l + 1].T, delta) * sp
        gradients_b[-l] = delta
        gradients_w[-l] = np.dot(delta, activations[-l - 1].T)

    return gradients_w, gradients_b


# Update weights
def update_weights(weights, biases, gradients_w, gradients_b, learning_rate):
    for i in range(len(weights)):
        weights[i] -= learning_rate * gradients_w[i]
        biases[i] -= learning_rate * gradients_b[i]
    return weights, biases


# Training the network
def train(X, Y, layers, learning_rate=0.1, epochs=10000):
    weights, biases = initialize_weights(layers)
    for epoch in range(epochs):
        for x, y in zip(X, Y):
            x = x.reshape(-1, 1)
            y = y.reshape(-1, 1)

            # Forward pass
            activations, zs = forward_propagation(x, weights, biases)

            # Backward pass
            gradients_w, gradients_b = backward_propagation(
                y, activations, zs, weights, biases
            )

            # Update weights and biases
            weights, biases = update_weights(
                weights, biases, gradients_w, gradients_b, learning_rate
            )

        # Print loss every 1000 epochs
        if epoch % 1000 == 0:
            loss = np.mean((activations[-1] - y) ** 2)
            print(f"Epoch {epoch}, Loss: {loss}")

    print("\nFinal Weights and Biases after training:")
    for i, (w, b) in enumerate(zip(weights, biases)):
        print(f"Layer {i+1} - Weights:\n{w}")
        print(f"Layer {i+1} - Biases:\n{b}")

    return weights, biases


# Example usage
# Define the network layers (e.g., 2 input neurons, 3 hidden neurons, 1 output neuron)
layers = [2, 3, 1]

# Training data for XOR
X = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])
Y = np.array([[0], [1], [1], [0]])

# Train the network
weights, biases = train(X, Y, layers, learning_rate=0.5, epochs=10000)

# Testing the network
for x in X:
    x = x.reshape(-1, 1)
    activations, _ = forward_propagation(x, weights, biases)
    print(f"Input: {x.T}, Output: {activations[-1]}")
