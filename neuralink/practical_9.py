#Write a program to demonstrate competitive learning and display the results in a geometric format

import numpy as np
import matplotlib.pyplot as plt
def competitive_learning(inputs, centroids, iterations=300, learning_rate=0.5):  
    for _ in range(iterations):  # Using _ for an unused loop variable (epoch)
        for sample in range(inputs.shape[0]):
            # Compute the induced local fields (dot products)
            distances = np.dot(centroids, inputs[sample])  # Changed local_fields to distances
            # Find the index of the neuron with the highest local field (winner)
            winning_neuron = np.argmax(distances)  # Renamed winner to winning_neuron
            # Update the winner's weights to move closer to the input
            centroids[winning_neuron] += learning_rate * (inputs[sample] - centroids[winning_neuron])
    return centroids

# Generate clustered input data
def create_cluster_data(n_clusters=3, points_per_cluster=30, cluster_deviation=1.0):  
    data_points = []
    for _ in range(n_clusters):
        # Generate random cluster center
        cluster_center = np.random.rand(2) * 10
        # Generate points around the cluster center
        cluster_data = np.random.normal(loc=cluster_center, scale=cluster_deviation, size=(points_per_cluster, 2))
        data_points.append(cluster_data)
    return np.vstack(data_points)

# Set random seed for reproducibility
np.random.seed(42)

# Generate the data
input_data = create_cluster_data(n_clusters=3, points_per_cluster=30)

# Initialize random weights for 3 neurons
initial_centroids = np.random.rand(3, 2) * 10  

# Train the competitive learning model
final_centroids = competitive_learning(input_data, initial_centroids.copy(), iterations=300, learning_rate=0.5)  

# Plot the results
plt.figure(figsize=(10, 8))
plt.scatter(input_data[:, 0], input_data[:, 1], color='blue', label='Input Data', alpha=0.5)  # Input data points
plt.scatter(initial_centroids[:, 0], initial_centroids[:, 1], color='red', marker='x', s=100, label='Initial Weights') 
plt.scatter(final_centroids[:, 0], final_centroids[:, 1], color='green', marker='o', s=100, label='Final weights')  

plt.legend()

plt.xlabel('X1')
plt.ylabel('X2')
plt.xlim(0, 10)
plt.ylim(0, 10)
plt.grid(True)
plt.show()
