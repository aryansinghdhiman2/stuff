import numpy as np


class HeteroAssociativeMemory:
    def __init__(self, input_patterns, output_patterns):
        self.input_patterns = input_patterns
        self.output_patterns = output_patterns
        self.num_inputs = len(input_patterns[0])
        self.num_outputs = len(output_patterns[0])
        self.weights = np.zeros((self.num_inputs, self.num_outputs))
        for i in range(len(input_patterns)):
            input_pattern = np.array(input_patterns[i]).reshape(-1, 1)
            output_pattern = np.array(output_patterns[i]).reshape(-1, 1)
            self.weights += np.dot(input_pattern, output_pattern.T)

    def recall(self, input_pattern):
        output_pattern = np.dot(self.weights.T, input_pattern)
        output_pattern[output_pattern > 0.5] = 1
        output_pattern[output_pattern <= 0.5] = 0
        return output_pattern


# Define the input and output patterns
input_patterns = [[0, 0, 0], [0, 1, 1], [1, 1, 1]]
output_patterns = [[0], [1], [1]]
# Create a heteroassociative memory network
HAM = HeteroAssociativeMemory(input_patterns, output_patterns)
# Test the network with inputs
test1 = np.array([0, 0, 0]).reshape(-1, 1)
test2 = np.array([0, 1, 1]).reshape(-1, 1)
test3 = np.array([1, 1, 1]).reshape(-1, 1)
output1 = HAM.recall(test1)
output2 = HAM.recall(test2)
output3 = HAM.recall(test3)
print("Test input 1:", test1.T, "\tOutput:", output1.T)
print("Test input 2:", test2.T, "\tOutput:", output2.T)
print("Test input 3:", test3.T, "\tOutput:", output3.T)
