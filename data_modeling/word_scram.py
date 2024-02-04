import random

fptr = open("file.txt","r+")

lines = fptr.readlines()
fptr.close()

punctuations = ",\.!?'\";:()"


fptr = open("file.txt","w")
for words in lines:
    words = words.split()
    fin_str = ''
    i = 0
    while i < len(words):
        for punctuation in punctuations:
            if(punctuation in words[i] and not punctuation == words[i]):
                new_words = words[i].split(punctuation)
                words_with_punctuation = []
                for word in new_words:
                    words_with_punctuation.append(word)
                    words_with_punctuation.append(punctuation)
                words_with_punctuation = words_with_punctuation[:len(words_with_punctuation)-1]
                words = words[:i] + words_with_punctuation + words[i+1:]

        if(words[i] not in punctuations):
            alphabets = list(words[i])
            copy_of_alphabets = alphabets[1:len(alphabets)-1]
            random.shuffle(copy_of_alphabets)
            alphabets[1:len(alphabets)-1] = copy_of_alphabets
            fin_str+= ''.join(alphabets) + " "
        else:
            fin_str = fin_str.rstrip() + words[i]
        i+=1

    
    fptr.write(fin_str+'\n')
fptr.close()