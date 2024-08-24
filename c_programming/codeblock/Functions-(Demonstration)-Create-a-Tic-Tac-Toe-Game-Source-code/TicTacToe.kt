import java.util.*

class TicTacToe {
    private val board: Array<CharArray>
    var currentPlayerMark: Char = ' '

    init {
        board = Array<CharArray>(3, { CharArray(3) })
        currentPlayerMark = 'x'
        initializeBoard()
    }

    fun initializeBoard() {
        for (i in 0..2) {
            for (j in 0..2) {
                board[i][j] = '-'
            }
        }
    }

    fun printBoard() {
        println("-------------")

        for (i in 0..2) {
            print("| ")
            for (j in 0..2) {
                print(board[i][j] + " | ")
            }
            println()
            println("--------------")
        }
    }

    fun isBoardFull(): Boolean {
        var isFull = true

        for (i in 0..2) {
            for (j in 0..2) {
                if (board[i][j] == '-')
                    isFull = false
            }
        }

        return isFull
    }

    private fun checkRowCol(c1: Char, c2: Char, c3: Char): Boolean {
        return ((c1 != '-') && (c1 == c2) && (c2 == c3))
    }

    private fun checkRowsForWin(): Boolean {
        for (i in 0..2) {
            if (checkRowCol(board[i][0], board[i][1], board[i][2])) {
                return true
            }

        }
        return false
    }

    private fun checkColumnsForWin(): Boolean {
        for (i in 0..2) {
            if (checkRowCol(board[0][i], board[1][i], board[2][i])) {
                return true
            }

        }
        return false
    }

    private fun checkDiagnalsForWin(): Boolean {
        return ((checkRowCol(board[0][0], board[1][1], board[2][2]) == true) || (checkRowCol(board[0][2], board[1][1], board[2][0]) == true))
    }

    fun checkForWin(): Boolean {
        return (checkRowsForWin() || checkColumnsForWin() || checkDiagnalsForWin())
    }

    fun changePlayer() {
        if (currentPlayerMark == 'x') {
            currentPlayerMark = 'o'
        } else {
            currentPlayerMark = 'x'
        }
    }

    fun placeMark(row: Int, col: Int): Boolean {
        if ((row >= 0) && (row < 3)) {
            if ((col >= 0) && (col < 3)) {
                if (board[row][col] == '-') {
                    board[row][col] = currentPlayerMark
                    return true
                }
            }
        }
        return false
    }
}

fun main(args: Array<String>)
{
    val game = TicTacToe()

    val keyboard = Scanner(System.`in`)
    var row: Int
    var col: Int

    println("Ready to play Tic Tac Toe, lets go!!")

    game.printBoard()

    println()

    while (true) {

        println("Player ${game.currentPlayerMark}, please enter the board coordinates for your next spot:")

        row = keyboard.nextInt()
        col = keyboard.nextInt()

        game.placeMark(row, col)

        game.printBoard()
        println()

        if (game.checkForWin()) {
            println("We have a winner! Congrats")
            System.exit(0)
        } else if (game.isBoardFull()) {
            println("Appears we have a draw")
            System.exit(0)
        }

        game.changePlayer()
    }
}
