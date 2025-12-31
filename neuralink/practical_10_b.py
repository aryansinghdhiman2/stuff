import numpy as np
import matplotlib.pyplot as plt
from matplotlib import gridspec
# Set the number of neurons and temperature (T)
num_neurons = 5
T = 0.9
# Initialize the weights randomly
weights = np.random.rand(num_neurons, num_neurons)
# Set self-connections to 0
np.fill_diagonal(weights, 0)
# Initialize the states of neurons randomly as +1(ON) or -1(OFF) independently
neuron_states = np.random.choice([-1, 1], size=num_neurons)
# Function to calculate the energy for a given configuration of neuron states
def calculate_energy(neuron_states):
    energy = 0
    for i in range(num_neurons):
        for j in range(num_neurons):
            if i != j:
                energy += neuron_states[i] * neuron_states[j] * weights[i, j]
    return -0.5 * energy
# Function to update a neuron's state based on the energy change
def update_neuron_state(neuron_index, neuron_states, temperature):
    # Store Old Configuration of neuron states
    oldConfig = neuron_states
    # Generate New Configuration of neuron states by flipping the selected neuron state 
    new_state = -oldConfig[neuron_index]
    newConfig = oldConfig
    newConfig[neuron_index] = new_state
    # Calculate ΔEnergy
    delta_energy = calculate_energy(newConfig) - calculate_energy(oldConfig)
    probability = 1 / (1 + np.exp(-delta_energy / temperature))
    # Flip the neuron state (change from +1 to -1 or vice versa) based on probability
    if np.random.rand() < probability:
        neuron_states[neuron_index] = new_state
# Set the number of iterations
num_iterations = 200
energies = []
neuron_states_history = []
for _ in range(num_iterations):
    # Choose a random neuron
    neuron_index = np.random.randint(0, num_neurons)
    # Try updating selected neuron state
    update_neuron_state(neuron_index, neuron_states, T)
    # Save the new system energy value
    energies.append(calculate_energy(neuron_states))
    # Save the new neuron states
    neuron_states_history.append(neuron_states.copy())
# Calculate the final energy and states
final_energy = energies[-1]
final_neuron_states = np.array(neuron_states_history[-1])
# Print the final energy and states
print(f"Final Energy: {final_energy}")
print(f"Final Neuron States: {final_neuron_states}")
# Create subplots for energy and neuron states
plt.figure(figsize=(16, 18))
plt.rc('axes', titlesize=17)
plt.rc('axes', labelsize=14)

gs = gridspec.GridSpec(num_neurons + 1, 1, height_ratios=[3] + [1] * num_neurons)
# Plot the energy for each iteration
ax1 = plt.subplot(gs[0])
plt.plot(range(num_iterations), energies)
plt.xlabel("Iteration")
plt.ylabel("Energy")
plt.title("Boltzmann Machine Learning - Energy over Iterations")
plt.grid(True)
# Create separate subplots for each neuron's state
for i in range(num_neurons):
    ax = plt.subplot(gs[i + 1])
    state_values = [1 if state[i] > 0 else -1 if state[i] < 0 else 0 for state in neuron_states_history]
# Plot the state of the neuron for each iteration
    plt.plot(range(num_iterations), state_values)
    plt.yticks([-1, 0, 1])
    plt.ylabel(f"N{i+1} State")
    plt.title(f"Neuron {i+1} States over Iterations")
    plt.grid(True)
    plt.tight_layout()
plt.subplots_adjust(top=0.93)
plt.suptitle("Boltzmann Machine Training Progress", fontsize=25)
plt.show()