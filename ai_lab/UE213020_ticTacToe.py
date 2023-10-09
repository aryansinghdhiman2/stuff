import termtables as tt
X = 3
O = 5


def go(board:list[int],index:int,turn:int):
    marker = 2
    if(turn % 2 == 0): marker = O
    else: marker = X
    board[index-1] = marker

def goToEmpty(board:list[int],turn:int):
    if(board[0]==2): go(board,1,turn)
    elif(board[1]==2): go(board,2,turn)
    elif(board[2]==2): go(board,3,turn)
    elif(board[3]==2): go(board,4,turn)
    elif(board[4]==2): go(board,5,turn)
    elif(board[5]==2): go(board,6,turn)
    elif(board[6]==2): go(board,7,turn)
    elif(board[7]==2): go(board,8,turn)
    elif(board[8]==2): go(board,9,turn)

def possibleForkonDiagonalSquares(board:list[int]) -> int:
    if(board[4]==X and board[2]==X): return 9
    elif(board[4]==X and board[8]==X): return 3
    elif(board[4]==X and board[6]==X): return 9
    return 0

def possibleForkOnNonDiagonalSquares(board:list[int]) -> int:
    if(board[1]==X and board[3]==X): return 1
    elif(board[1]==X and board[5]==X): return 3
    elif(board[3]==X and board[7]==X): return 6
    elif(board[5]==X and board[7]==X): return 9
    return 0

def make2(board:list[int]) -> int:
    if(board[4]==2): return 5
    elif(board[1]==2): return 2
    elif(board[3]==2): return 4
    elif(board[5]==2): return 6
    elif(board[7]==2): return 8
    return 0

def posswin(board:list[int],O_X:int) -> int:
    if(O_X == O):
        #Rows
        if(board[0]*board[1]*board[2]==50):
            if(board[0]==2): return 1
            if(board[1]==2): return 2
            if(board[2]==2): return 3

        if(board[3]*board[4]*board[5]==50):
            if(board[3]==2): return 4
            if(board[4]==2): return 5
            if(board[5]==2): return 6

        if(board[6]*board[7]*board[8]==50):
            if(board[6]==2): return 7
            if(board[7]==2): return 8
            if(board[8]==2): return 9

        #Columns
        if(board[0]*board[3]*board[6]==50):
            if(board[0]==2): return 1
            if(board[3]==2): return 4
            if(board[6]==2): return 7
        
        if(board[1]*board[4]*board[7]==50):
            if(board[1]==2): return 2
            if(board[4]==2): return 5
            if(board[7]==2): return 8

        if(board[2]*board[5]*board[8]==50):
            if(board[2]==2): return 3
            if(board[5]==2): return 6
            if(board[8]==2): return 9

        #Diagonals
        if(board[0]*board[4]*board[8]==50):
            if(board[0]==2): return 1
            if(board[4]==2): return 5
            if(board[8]==2): return 9

        if(board[2]*board[4]*board[6]==50):
            if(board[2]==2): return 3
            if(board[4]==2): return 5
            if(board[6]==2): return 7
    else:
        #Rows
        if(board[0]*board[1]*board[2]==18):
            if(board[0]==2): return 1
            if(board[1]==2): return 2
            if(board[2]==2): return 3

        if(board[3]*board[4]*board[5]==18):
            if(board[3]==2): return 4
            if(board[4]==2): return 5
            if(board[5]==2): return 6

        if(board[6]*board[7]*board[8]==18):
            if(board[6]==2): return 7
            if(board[7]==2): return 8
            if(board[8]==2): return 9

        #Columns
        if(board[0]*board[3]*board[6]==18):
            if(board[0]==2): return 1
            if(board[3]==2): return 4
            if(board[6]==2): return 7
        
        if(board[1]*board[4]*board[7]==18):
            if(board[1]==2): return 2
            if(board[4]==2): return 5
            if(board[7]==2): return 8

        if(board[2]*board[5]*board[8]==18):
            if(board[2]==2): return 3
            if(board[5]==2): return 6
            if(board[8]==2): return 9

        #Diagonals
        if(board[0]*board[4]*board[8]==18):
            if(board[0]==2): return 1
            if(board[4]==2): return 5
            if(board[8]==2): return 9

        if(board[2]*board[4]*board[6]==18):
            if(board[2]==2): return 3
            if(board[4]==2): return 5
            if(board[6]==2): return 7
    return 0

def userMove(board:list[int],turn:int):
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

def computerMove(board:list[int],turn:int):
    match(turn):
        case 1:
            go(board,1,turn)
        case 2:
            if(board[4]==2): 
                go(board,5,turn)
            else:
                go(board,1,turn)
        case 3:
            if(board[8]==2):
                go(board,9,turn)
            else: 
                go(board,3,turn)
        case 4:
            win_index = posswin(board,X)
            if(win_index != 0):
                go(board,posswin(board,X),turn)
            elif(possibleForkOnNonDiagonalSquares(board) != 0):
                go(board,possibleForkOnNonDiagonalSquares(board),turn)
            elif(possibleForkonDiagonalSquares(board) != 0):
                go(board,possibleForkonDiagonalSquares(board),turn)
            else: 
                go(board,make2(board),turn)
        case 5:
            if(posswin(board,X) != 0):
                go(board,posswin(board,X),turn)
            elif(posswin(board,O) != 0):
                go(board,posswin(board,O),turn)
            elif(board[6]==2):
                go(board,7,turn)
            else: 
                go(board,3,turn)
        case 6:
            if(posswin(board,O)!=0):
                go(board,posswin(board,O),turn)
            elif(posswin(board,X) != 0):
                go(board,posswin(board,X),turn)
            else: 
                go(board,make2(board),turn)
        case 7:
            if(posswin(board,X) != 0):
                go(board,posswin(board,X),turn)
            elif(posswin(board,O) != 0):
                go(board,posswin(board,O),turn)
            else:
                goToEmpty(board,turn)
        case 8:
            if(posswin(board,O) != 0):
                go(board,posswin(board,O),turn)
            elif(posswin(board,X) != 0):
                go(board,posswin(board,X),turn)
            else:
                goToEmpty(board,turn)
        case 9:
            if(posswin(board,X) != 0):
                go(board,posswin(board,X),turn)
            elif(posswin(board,O) != 0):
                go(board,posswin(board,O),turn)
            else:
                goToEmpty(board,turn)
        
def checkWin(board:list[int],O_X:int) -> bool:
    if(O_X == O):
        #Rows
        if(board[0]*board[1]*board[2]==125):
            return True

        if(board[3]*board[4]*board[5]==125):
            return True

        if(board[6]*board[7]*board[8]==125):
            return True

        #Columns
        if(board[0]*board[3]*board[6]==125):
            return True
        
        if(board[1]*board[4]*board[7]==125):
            return True

        if(board[2]*board[5]*board[8]==125):
            return True

        #Diagonals
        if(board[0]*board[4]*board[8]==125):
            return True

        if(board[2]*board[4]*board[6]==125):
            return True
    else:
        #Rows
        if(board[0]*board[1]*board[2]==27):
            return True

        if(board[3]*board[4]*board[5]==27):
            return True

        if(board[6]*board[7]*board[8]==27):
            return True

        #Columns
        if(board[0]*board[3]*board[6]==27):
            return True
        
        if(board[1]*board[4]*board[7]==27):
            return True

        if(board[2]*board[5]*board[8]==27):
            return True

        #Diagonals
        if(board[0]*board[4]*board[8]==27):
            return True

        if(board[2]*board[4]*board[6]==27):
            return True
    return False

def displayBoard(board:list[int]):
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
    turn = 1
    board = [2,2,2,2,2,2,2,2,2]
    
    if(moveFirst != 0):
        while(True):
            if(turn > 9): break
            # print("Computer is moving")
            computerMove(board,turn)
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
            computerMove(board,turn)
            if(checkWin(board,O)):
                displayBoard(board)
                print("Computer Win")
                break
            displayBoard(board)
            turn+=1
            if(turn > 9): break 
    displayBoard(board)
    if(turn > 9):print("Draw")