inp = input("Enter a string: ")

freq_map = dict()

inp = inp.split(".")

for sentence in inp:
    words = sentence.split()
    for word in words:
        word = word.lower().strip()
        if word not in freq_map:
            freq_map[word] = 1
        else: freq_map[word] += 1

print(freq_map)