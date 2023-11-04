from typing import Any
import termtables as tt

def static_vars(**kwargs):
    def decorate(func):
        for k in kwargs:
            setattr(func, k, kwargs[k])
        return func
    return decorate

Board = list[int]

X = 3
O = 5

MAX_RATING = 100

magic_square_to_board : dict[int,int] = {
    8 : 1,
    1 : 2,
    6 : 3,
    3 : 4,
    5 : 5,
    7 : 6,
    4 : 7,
    9 : 8,
    2 : 9
}

board_to_magic_square : dict[int,int] = {
    1 : 8,
    2 : 1,
    3 : 6,
    4 : 3,
    5 : 5,
    6 : 7,
    7 : 4,
    8 : 9,
    9 : 2
}

def go(board:Board,index:int,turn:int):
    marker = 2
    if(turn % 2 == 0): marker = O
    else: marker = X
    board[index-1] = marker

def goToEmpty(board:Board,turn:int):
    if(board[0]==2): go(board,1,turn)
    elif(board[1]==2): go(board,2,turn)
    elif(board[2]==2): go(board,3,turn)
    elif(board[3]==2): go(board,4,turn)
    elif(board[4]==2): go(board,5,turn)
    elif(board[5]==2): go(board,6,turn)
    elif(board[6]==2): go(board,7,turn)
    elif(board[7]==2): go(board,8,turn)
    elif(board[8]==2): go(board,9,turn)

def make2(board:Board) -> int:
    if(board[4]==2): return 5
    elif(board[1]==2): return 2
    elif(board[3]==2): return 4
    elif(board[5]==2): return 6
    elif(board[7]==2): return 8
    return 0

def posswin(board:Board,O_X:int) -> int:
    indices = [ i+1 for i,x in enumerate(board) if x == O_X]
    
    i = 0
    while(i<len(indices)):
        j = i + 1
        while(j<len(indices)):
            possible_win_condition = 15 - (board_to_magic_square[indices[i]]+board_to_magic_square[indices[j]])
            if(possible_win_condition in magic_square_to_board):
                if(board[magic_square_to_board[possible_win_condition]-1]==2):
                    return magic_square_to_board[possible_win_condition]
            j+=1
        i += 1
    return 0

def checkWin(board:Board,O_X:int) -> bool:
    indices = [ i+1 for i,x in enumerate(board) if x == O_X]
    
    i = 0
    while(i<len(indices)):
        j = i + 1
        while(j<len(indices)):
            k = j + 1
            while(k<len(indices)):
                win_condition = board_to_magic_square[indices[i]]+board_to_magic_square[indices[j]]+board_to_magic_square[indices[k]]
                if(win_condition==15):return True
                k+=1
            j+=1
        i += 1 
    return False

def userMove(board:Board,turn:int):
    index = 0
    while(True):
        index = int(input("Enter your move: "))
        if(index <= 0 or index > 9):
            print("Invalid Input")
            continue
        elif(board[index-1]!=2):
            print("Marker Already Present")
            continue
        break
    go(board,index,turn)

def numberOfposswin(board:Board,O_X:int) -> int:
    indices = [ i+1 for i,x in enumerate(board) if x == O_X]
    wins = 0
    i = 0
    while(i<len(indices)):
        j = i + 1
        while(j<len(indices)):
            possible_win_condition = 15 - (board_to_magic_square[indices[i]]+board_to_magic_square[indices[j]])
            if(possible_win_condition in magic_square_to_board):
                if(board[magic_square_to_board[possible_win_condition]-1]==2):
                    wins+=1
            j+=1
        i += 1
    return wins

def generator(board:Board,O_X:int) ->list[tuple[Board,int]]:
    boards:list[tuple[Board,int]] = []
    
    for i in range(0,len(board)):
        if(board[i]==2):
            new_board = board.copy()
            new_board[i]=O_X
            boards.append((new_board,i))

    return boards

def ratePosition(board:Board,O_X:int) -> int:
    if(checkWin(board,O_X)):
        return 100
    elif(checkWin(board,8-O_X)):
        return -100
    elif(numberOfposswin(board,O_X) > 0):
        return (numberOfposswin(board,O_X) * (10))
    elif(numberOfposswin(board,8-O_X)):
        return (numberOfposswin(board,8-O_X) * (-10))
    elif(board[4]==O_X):
        rating=3
        if(board[0]==O_X):
            rating+=2
        if(board[2]==O_X):
            rating+=2
        if(board[6]==O_X):
            rating+=2
        if(board[8]==O_X):
            rating+=2
        if(board[1]==O_X):
            rating+=1
        if(board[3]==O_X):
            rating+=1
        if(board[5]==O_X):
            rating+=1
        if(board[7]==O_X):
            rating+=1
        return rating
    else:
        rating = 0
        for i in board:
            if(i==O_X):
                rating+=1
        return rating

def minMaxAB(board:Board,player:int,depth:int,use_thresh:int,pass_thresh:int) -> dict[str,Any]:
    minMaxAB.counter+=1
    if(depth<=0):
        return {
                'path':None,
                'value':ratePosition(board,player),
                }
    
    successors = generator(board,player)
    if(len(successors) == 0): 
        return {
                'path':None,
                'value':ratePosition(board,player),
                }
    else:
        path:list[int] = [0]
        for successor,suc_pos in successors:
            result = minMaxAB(successor,8-player,depth-1,-pass_thresh,-use_thresh)
            if(-result['value'] > pass_thresh):
                pass_thresh = -result['value']
                path = [suc_pos] if result['path'] is None else [suc_pos] + result['path']
            if(pass_thresh >= use_thresh):
                return {
                    'value':pass_thresh,
                    'path':path
                }


        return {
                'value':pass_thresh,
                'path':path
            }

def minMax(board:Board,player:int,depth:int) -> dict[str,Any]:
    minMax.counter+=1
    if(depth<=0):
        return {
                'path':None,
                'rating':ratePosition(board,player)
                }
    
    successors = generator(board,player)
    if(len(successors) == 0): 
        return {
                'path':None,
                'rating':ratePosition(board,player)
                }
    else:
        max_value = -MAX_RATING - 1
        best_path:list[int] = []
        for successor,suc_pos in successors:
            result = minMax(successor,8-player,depth-1)
            if(-result['rating'] > max_value):
                max_value = -result['rating']
                best_path = [suc_pos] if result['path'] is None else [suc_pos] + result['path']
        return {
                'path':best_path,
                'rating':max_value
                }
    

if(__name__=="__main__"):
    board:Board = [2,2,2,2,2,2,2,2,2]
    depth = 9
    minMax.counter = 0
    minMaxAB.counter = 0

    minMax(board,X,depth)
    minMaxAB(board,X,depth,MAX_RATING,-MAX_RATING)

    print(f"Number of Calls for simple Min Max: {minMax.counter}")
    print(f"Number of Calls for AB Min Max: {minMaxAB.counter}")