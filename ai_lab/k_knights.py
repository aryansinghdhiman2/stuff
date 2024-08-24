from typing import Literal
import termtables

Board = list[list[Literal[0,1]]]
EMPTY = 0
KNIGHT = 1

def attack(board:Board,i:int,j:int) -> list[tuple[int,int]]:
    positions:list[tuple[int,int]] = []
    if(i-1>=0 and j-2>=0 and i-1<len(board) and j-2<len(board[i-1])):
        positions.append((i-1,j-2))
    if(i+1>=0 and j-2>=0 and i+1<len(board) and j-2<len(board[i-1])):
        positions.append((i+1,j-2))
    if(i+2>=0 and j-1>=0 and i+2<len(board) and j-1<len(board[i-1])):
        positions.append((i+2,j-1))    
    if(i+2>=0 and j+1>=0 and i+2<len(board) and j+1<len(board[i-1])):
        positions.append((i+2,j+1))
    if(i+1>=0 and j+2>=0 and i+1<len(board) and j+2<len(board[i-1])):
        positions.append((i+1,j+2))
    if(i-1>=0 and j+2>=0 and i-1<len(board) and j+2<len(board[i-1])):
        positions.append((i-1,j+2))
    if(i-2>=0 and j+1>=0 and i-2<len(board) and j+1<len(board[i-1])):
        positions.append((i-2,j+1))
    if(i-2>=0 and j-1>=0 and i-2<len(board) and j-1<len(board[i-1])):
        positions.append((i-2,j-1))
    return positions

def can_place(board:Board,i:int,j:int) -> bool:
    if(board[i][j]!=EMPTY):
        return False
    for a,b in attack(board,i,j):
        if(board[a][b]!=EMPTY):
            return False
    return True

def place(board:Board,i:int,j:int) -> Board:
    new_board = board.copy()
    new_board[i][j] = 1
    return new_board

# def Kn