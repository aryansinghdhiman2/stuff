def hammingDistance(s1:str,s2:str) -> int:
    diff = 0
    if(len(s1)!=len(s2)):
        return -1
    
    for i in range(len(s1)):
        if(s1[i]!=s2[i]):
            diff+=1
        
    return diff

if(__name__=="__main__"):
    s1 = input("Enter First String: ")
    s2 = input("Enter Second String: ")

    res = hammingDistance(s1,s2)
    if(res == -1):
        print("Strings should be of equal length! ")
    else: print(f"Hamming Distance is {res}")