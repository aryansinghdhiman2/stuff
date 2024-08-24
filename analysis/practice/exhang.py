def amountExchange(trips:list[list[int]]):
    for trip in trips:
        avr=0
        exch=0
        for amt in trip:
            avr+=amt
        avr=avr/len(trip)
        for i in range(0,len(trip)):
            trip[i]=trip[i]-avr
            if(trip[i]>0):
                exch+=trip[i]
        print(exch)

trips=[[10,20,30],
       [15.00,15.01,3.00,3.01],
       [1,2,5,8]]

amountExchange(trips)
    
