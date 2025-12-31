import numpy as np
import matplotlib.pyplot as plt

# Define input patterns
pattern1 = np.array([1, 1, 0, 0, 0, 0])
pattern2 = np.array([0, 0, 1, 1, 0, 0])
pattern3 = np.array([0, 0, 0, 0, 1, 1])
patterns = [pattern1, pattern2, pattern3]
# Initialize weights using Hebb's Rule
num_neurons = len(pattern1)
weights = np.zeros((num_neurons, num_neurons))
for pattern in patterns:
    weights += np.outer(pattern, pattern)
# Create a figure for displaying patterns
fig1, axes1 = plt.subplots(1, 3, figsize=(12, 3))
fig1.suptitle("Learnt Patterns")
patterns_to_display = [
    (pattern1, "Pattern 1"),
    (pattern2, "Pattern 2"),
    (pattern3, "Pattern 3"),
]
for i, (pattern, title) in enumerate(patterns_to_display):
    ax = axes1[i]
    ax.imshow(pattern.reshape(2, 3), cmap="gray")
    ax.set_title(title)

plt.tight_layout()

# Make noisy patterns
noisy_pattern1 = pattern1.copy()
noisy_pattern1[0] = 0
noisy_pattern2 = pattern2.copy()
noisy_pattern2[2] = 0
noisy_pattern3 = pattern3.copy()
noisy_pattern3[-2] = 0


# Implement the recall process
def recall_pattern(input_pattern, weights, max_iterations=5):
    for _ in range(max_iterations):
        output = np.dot(input_pattern, weights)

    input_pattern = np.sign(output)
    return input_pattern


retrieved_pattern1 = recall_pattern(noisy_pattern1, weights)
retrieved_pattern2 = recall_pattern(noisy_pattern2, weights)
retrieved_pattern3 = recall_pattern(noisy_pattern3, weights)
# Create a second figure for displaying noisy and recalled patterns
fig2, axes2 = plt.subplots(2, 3, figsize=(12, 6))
fig2.suptitle("Noisy and Retrieved Patterns")
noisy_and_retrieved_patterns = [
    (noisy_pattern1, "Noisy Pattern 1"),
    (noisy_pattern2, "Noisy Pattern 2"),
    (noisy_pattern3, "Noisy Pattern 3"),
    (retrieved_pattern1, "Retrieved Pattern 1"),
    (retrieved_pattern2, "Retrieved Pattern 2"),
    (retrieved_pattern3, "Retrieved Pattern 3"),
]
for i, (pattern, title) in enumerate(noisy_and_retrieved_patterns):
    row = i // 3
    col = i % 3
    ax = axes2[row, col]
    ax.imshow(pattern.reshape(2, 3), cmap="gray")
    ax.set_title(title)
plt.tight_layout()
plt.show()
