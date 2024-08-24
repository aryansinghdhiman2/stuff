def findMaxProduct(n: int):
    if(n<=1):
        return 0
    max_product = 0
    for i in range(1, n):
        uncut_product = i * (n - i)
        further_cut_product = findMaxProduct(n - i) * i
        product = max(uncut_product, further_cut_product)
        max_product = max(max_product, product)
    return max_product

def getInput():
    return int(input("Enter Length of String: "))

if(__name__=="__main__"):
    n=getInput()
    print(f"Maximum Possible Product is: {findMaxProduct(n)}")