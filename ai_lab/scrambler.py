import random

inp = input('Enter String: ')
words = inp.split(' ')
for i in range(0,len(words)):
    alphabets = list(words[i])
    if(len(alphabets) < 3):
        continue
    copy_of_alpha = alphabets[1:len(alphabets)-1]
    random.shuffle(copy_of_alpha)
    alphabets[1:len(alphabets)-1] = copy_of_alpha
    word = ''
    for alphabet in alphabets:
        word = word + alphabet
    words[i] = word

fin_str = ''
for word in words:
    fin_str = fin_str + word + ' '

print(fin_str)