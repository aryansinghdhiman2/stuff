from typing import Any
import termtables as tt

Board = list[int]

X = 3
O = 5



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
    
    if(checkWin(board,O_X) or checkWin(board,8-O_X)):
        return boards

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

def minMax(board:Board,O_X:int,turn:int,depth:int,position:int) -> dict[str,Any]:
    if(depth<=0):
        return {
                'path':[position],
                'rating':ratePosition(board,8-O_X)
                }
    
    successors = generator(board,8-O_X)
    if(len(successors) == 0): 
        return {
                'path':[position],
                'rating':ratePosition(board,8-O_X)
                }
    else:
        max_value = -101
        best_path:list[int] = []
        for successor,suc_pos in successors:
            marker = 2
            if(turn % 2 == 0): marker = O
            else: marker = X
            result = minMax(successor,marker,turn+1,depth-1,suc_pos)
            if(-result['rating'] > max_value):
                max_value = -result['rating']
                best_path = result['path']
        path = [position] + best_path
        return {
                'path':path,
                'rating':max_value
                }

def computerMove(board:Board,turn:int,depth:int):
    marker = 2
    if(turn % 2 == 0): marker = O
    else: marker = X
    
    successors = generator(board,marker)
    max_value = -101

    best_path:list[int] = []
    for successor,suc_pos in successors:
        result = minMax(successor,marker,turn+1,depth-1,suc_pos)
        if(-result['rating'] > max_value):
            max_value = -result['rating']
            best_path = result['path']
        # displayBoard(successor)
        # print(-result['rating'])
    # print([pos+1 for pos in best_path])
    go(board,best_path[0]+1,turn)


def displayBoard(board:Board):
    pretty_board:list[list[str]] = []
    row:list[str] = []
    counter = 0

    for i in board:
        if(counter==3 or counter==6): 
            pretty_board.append(row)
            row = []
        if(i==2):row.append(' ')
        if(i==3):row.append('X')
        if(i==5):row.append('O')
        counter+=1
    pretty_board.append(row)
    tt.print(pretty_board)


if(__name__ =="__main__"):
    moveFirst = int(input("Enter 0 if you want to move first: "))
    depth = int(input("Enter Depth of AI: "))
    turn = 1
    board = [2,2,2,2,2,2,2,2,2]
    if(moveFirst != 0):
        while(True):
            if(turn > 9): break
            # print("Computer is moving")
            computerMove(board,turn,depth)
            if(checkWin(board,X)):
                displayBoard(board)
                print("Computer Win")
                break
            displayBoard(board)
            print("Your Turn")
            turn+=1
            if(turn > 9): break
            userMove(board,turn)
            if(checkWin(board,O)):
                displayBoard(board)
                print("Human Win")
                break
            turn+=1
            # displayBoard(board)
    else:
        displayBoard(board)
        while(True):
            if(turn > 9): break
            print("Your Turn")
            userMove(board,turn)
            if(checkWin(board,X)):
                displayBoard(board)
                print("Human Win")
                break
            turn+=1
            if(turn > 9): break 
            computerMove(board,turn,depth)
            if(checkWin(board,O)):
                displayBoard(board)
                print("Computer Win")
                break
            displayBoard(board)
            turn+=1
            if(turn > 9): break 
    displayBoard(board)
    if(turn > 9):print("Draw")