def matrix_chain(p:list[int]):
    n = len(p)-1
    m = [[0]*n for i in range(n)]
    s = [[0]*(n) for i in range(0,n)]

    for l in range(1,n):
        for i in range(0,n-l):
            j=i+l
            m[i][j]=float('inf')
            for k in range(i,j):
                q=m[i][k]+m[k+1][j]+p[i]*p[k+1]*p[j+1]
                if(q<m[i][j]):
                    m[i][j]=q
                    s[i][j]=k
    
    return m,s

def print_optimal(s,i,j):
    if(i==j):
        print(f'A{i+1}',end=' ')
    else:
        print('(',end=' ')
        print_optimal(s,i,s[i][j])
        print_optimal(s,s[i][j]+1,j)
        print(')',end=' ')

def getInput():
    p = list(map(int,input('Enter Dimension of Matrices: ').strip().split()))
    return p

if(__name__=='__main__'):
    p=getInput()
    m,s=matrix_chain(p)
    print('Optimal Order is: ')
    print_optimal(s,0,len(m)-1)
    print(f'\nMinimum Operations are: {m[0][len(m)-1]}')