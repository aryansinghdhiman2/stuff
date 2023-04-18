def matrix_chain(p:list[int]):
    n = len(p)-1
    m = [[0]*n for i in range(n)]
    s = [[0]*(n-1) for i in range(0,n-1)]

    for l in range(1,n):
        for i in range(1,n-l):
            j=i+l
            m[i][j]=float('inf')
            for k in range(i,j):
                q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j]
                if(q<m[i][j]):
                    m[i][j]=q
                    s[i][j]=k
    
    return m,s