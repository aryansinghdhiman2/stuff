import numpy as np
class SimpleBoltzmannMachine:
    def __init__(self, num_visible, num_hidden, learning_rate=0.1, temperature=1.0, epochs=1000):
        self.num_visible = num_visible
        self.num_hidden = num_hidden
        self.learning_rate = learning_rate
        self.temperature = temperature
        self.epochs = epochs

        # Initialize weights and biases
        self.weights = np.random.normal(0, 0.01, (num_visible + num_hidden, num_visible + num_hidden))
        self.weights = (self.weights + self.weights.T) / 2  # Make weights symmetric
        np.fill_diagonal(self.weights, 0)  
        self.visible_bias = np.zeros(num_visible)
        self.hidden_bias = np.zeros(num_hidden)
    
    def flip_probability(self, delta_energy):
        """Calculate flip probability using temperature-adjusted energy difference."""
        return 1 / (1 + np.exp(delta_energy / self.temperature))
    
    def sample_state(self, probs):
        """Sample binary states (0 or 1) from probabilities."""
        return (probs > np.random.rand(probs.shape[0])).astype(int)
    
    def train(self, data):
        for epoch in range(self.epochs):
            total_error = 0
            for sample in data:
                # Positive phase (clamped)
                hidden_probs = self.sigmoid(np.dot(sample, self.weights[:self.num_visible, self.num_visible:]) + self.hidden_bias)
                hidden_states = self.sample_state(hidden_probs)
                positive_phase = np.outer(sample, hidden_probs)

                # Negative phase (free-running)
                visible_probs = self.sigmoid(np.dot(hidden_states.reshape(1, -1), self.weights[self.num_visible:, :self.num_visible]).flatten() + self.visible_bias)
                visible_states = self.sample_state(visible_probs)
                hidden_probs_free = self.sigmoid(np.dot(visible_states, self.weights[:self.num_visible, self.num_visible:]) + self.hidden_bias)
                negative_phase = np.outer(visible_states, hidden_probs_free)

                # Update weights and biases
                self.weights[:self.num_visible, self.num_visible:] += self.learning_rate * (positive_phase - negative_phase)
                self.weights[self.num_visible:, :self.num_visible] = self.weights[:self.num_visible, self.num_visible:].T  # Ensure symmetry
                self.visible_bias += self.learning_rate * (sample - visible_states)
                self.hidden_bias += self.learning_rate * (hidden_probs - hidden_probs_free)

                # Calculate reconstruction error
                sample_error = np.sum((sample - visible_states) ** 2)
                total_error += sample_error

            # Print progress
            if epoch % 100 == 0:
                print(f"Epoch {epoch} complete - Reconstruction Error: {total_error}")
                print(f"Sample weights: {self.weights[:self.num_visible, self.num_visible:]}")
                print(f"Visible Biases: {self.visible_bias}")
                print(f"Hidden Biases: {self.hidden_bias}\n")



    def sigmoid(self, x):
        return 1 / (1 + np.exp(-x))

# Example usage
num_visible = 6
num_hidden = 3
learning_rate = 0.1
temperature = 1.0
epochs = 1000

# Training data: binary vectors
training_data = np.array([
    [1, 0, 1, 0, 1, 0],
    [0, 1, 0, 1, 0, 1],
    [1, 1, 0, 0, 1, 1]
])

bm = SimpleBoltzmannMachine(num_visible, num_hidden, learning_rate, temperature, epochs)
bm.train(training_data)
