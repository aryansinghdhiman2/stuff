

max_depth = 4

def make3():
    if(board[1]!=2 and board[3]!=2)or(board[1]!=2 and board[5]!=2):
        return 0
    elif(board[7]!=2 and board[3]!=2)or(board[7]!=2 and board[5]!=2):
        return 8
    else:
        return 0

def make2 ():
    if board[4] == 2:
        return 4
    else:
        if board[1] ==2:
            return 1
        elif board[3] ==2:
            return 3
        elif board[5] ==2:
            return 5
        elif board[7] ==2:
            return 7
        

def move_generator():
    moveList = []

    if(checkWin('X')==0 or checkWin('O')==0):
        return moveList

    for i in range(len(board)):
        if board[i] == 2:
            moveList.append(i)
    # print(moveList)
    return moveList

def rating_function(player):
    if player == 'X': k = 3
    else: k = 5
    score = 0
    if checkWin(player) == 0:
        return 100
    elif checkWin('X' if player == 'O' else 'O') == 0:
        return -100
    elif posWin(player):
        return (posWin(player)*10)
    elif posWin('X' if player == 'O' else 'O'):
        return ((posWin('X' if player == 'O' else 'O')*(-10)))


    elif board[4] == k:
        score = 3
        if board[1] ==  k: score = score + 1
        if board[3] ==  k: score = score + 1
        if board[5] ==  k: score = score + 1
        if board[7] ==  k: score = score + 1
        if board[0] ==  k: score = score + 2
        if board[2] ==  k: score = score + 2
        if board[6] ==  k: score = score + 2
        if board[8] ==  k: score = score + 2
        # print("elif")
        return score

    else:
        score = 0
        for i in range (len(board)):
            if board[i] == k:
                score = score + 1
        # print("else ")
        return score
    

    

def Go(n):
    global turn
    if turn % 2 != 0:
        board[n] = 3
    else: board[n] = 5
    turn = turn + 1

def display():
    print()
    symbol_mapping = {3: "X", 5: "O", 2: " "}
    for i in range(3):
        for j in range(3):
            index = i * 3 + j
            cell_value = symbol_mapping[board[index]]
            print(f"{cell_value:^3}", end="|")
        print("\n" + "-" * 11)


def posWin(player):
    if player == 'X':
        k = 18
    else: k = 50

    count = 0
    if board[0] * board [3]* board[6] == k:
        count = count+1

    if board[1] * board [4]* board[7] == k:
        count = count+1

    if board[2] * board [5]* board[8] == k:
        count = count+1

    if board[0] * board [1]* board[2] == k:
        count = count+1
    
    if board[3] * board [4]* board[5] == k:
        count = count+1

    if board[6] * board [7]* board[8] == k:
        count = count+1

    if board[0] * board [4]* board[8] == k:
        count = count+1

    if board[2] * board [4]* board[6] == k:
        count = count+1

    
    
    # print("count: ", count)
    return count

def checkWin(player):

    if player == 'X':
        k = 27
    else: k = 125

    if board[0] * board [3]* board[6] == k:
        return 0
    
    elif board[1] * board [4]* board[7] == k:
        return 0

    elif board[2] * board [5]* board[8] == k:
        return 0

    elif board[0] * board [1]* board[2] == k:
        
        return 0
    
    elif board[3] * board [4]* board[5] == k:
        
        return 0

    elif board[6] * board [7]* board[8] == k:
        
        return 0
    
    elif board[0] * board [4]* board[8] == k:
        
        return 0
    
    elif board[2] * board [4]* board[6] == k:
        
        return 0

    else: return -1

def userMove(player):
    global turn
    x = int(input("Enter the position where you want to enter "))
    if player == 'O':
        board[x] = 5
    else: board[x] = 3
    turn = turn + 1

def compMove(player):
    if player == 'X': b = 3
    else: b = 5
    # global turn
        
    best_move = -1
    best_score = -100

    successors = move_generator()

    for move in successors:
        board[move] = b
        if player == 'X': opponent = 'O'
        else: opponent = 'X'
        result = min_max(1, opponent)
        # display()
        # print(-result)
        board[move] = 2 

        if (-result) > best_score:
            best_score = -result
            best_move = move
        

    Go(best_move)
    return
    

def min_max(depth, player):
    
    if depth >= max_depth:
        # print("rating: ",rating_function(player))
        return rating_function(player)
    
    best_score = -100

    successors = move_generator()
    if(len(successors)==0):
        return rating_function(player)
    for move in successors:
        board[move] = 3 if player == 'X' else 5
        # display()
        result = min_max(depth + 1, 'O' if player == 'X' else 'X')
        # display()
        # print(result)
        board[move] = 2  # Undo the move

        new_val = -(result)
        if new_val > best_score:
            best_score = new_val

    return best_score





if __name__ == '__main__':

    # board = [5,3,3,2,5,2,2,2,2]
    # min_max(1,'O')
    # exit()
    board = [2] * 9
    turn = 1
    response = input("Do you want to play first (y/n) ")
    
    if response == 'n':

        while(1):
            
            compMove('X')
            
            display()
            if turn > 9:
                print("Its a tie")
                break
            
            checkWin('X')
            if checkWin('X') == 0:
                print("player X has won")
                break
            
            userMove('O')
            
            display()
            if turn > 9:
                print("Its a tie")
                break

            checkWin('O')
            if checkWin('O') == 0:
                print("player O has won")
                break

    elif response == 'y':
        while(1):
           
            userMove('X')
            
            display()
            if turn > 9:
                print("Its a tie")
                break
            
            checkWin('X')
            if checkWin('X') == 0:
                print("player X has won")
                break
            
            compMove('O')
            
            display()
            if turn > 9:
                print("Its a tie")
                break

            checkWin('O')
            if checkWin('O') == 0:
                print("player O has won")
                break
    