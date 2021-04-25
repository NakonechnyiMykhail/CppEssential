boardPrint = """
 _ _ _
|1|2|3|
-------
|4|5|6|
-------
|7|8|9|
-------
"""
gift = "🎁"
openGift2 = "💵"
openGift3 = "🎮"
openGift4 = "💻"
openGift5 = "💎"
openGift6 = "🎂"
openGift7 = "📖"
openGift8 = "🔮"
openGift9 = "🥇"
openGift10 = "🏆"
openGift11 = "📱"
openGift12 = "🧪"
openGift13 = "🐈"
openGift14 = "👑"
openGift15 = "🦋"
import random
#name = int(input("What is your name?"))
#def  hello(str(name)):
#    print("Hello " + name + ".")
# welcome = """
#  __          __  _
#  \ \        / / | |
#   \ \  /\  / /__| | ___ ___  _ __ ___   ___
#    \ \/  \/ / _ \ |/ __/ _ \| '_ ` _ \ / _ \\
#     \  /\  /  __/ | (_| (_) | | | | | |  __/
#      \/  \/ \___|_|\___\___/|_| |_| |_|\___|
# """
# print(welcome)


def drawBoard(board):
    print(' _ _ _')
    print('|' + board[1]+ '|' + board[2] + '|' + board[3] + '|')
    print('-------')
    print('|' + board[4] + '|' + board[5] + '|' + board[6] + '|')
    print('-------')
    print('|' + board[7]+ '|' + board[8] + '|' + board[9] + '|')
    print('-------')

def inputPlayerLetter():
    letter = ""
    while not (letter == "X" or letter == "O"):
        print("Are you choosing 'O' or 'X'?")
        letter = input().upper()

    if letter == "X":
        return ["X", "O"]
    else:
        return ["O", "X"]

def whoGoFirst():
    if random.randint(0,1) == 0:
        return "Computer"
    else:
        return "Player"

def makeMove(board, letter, move):
    board[move] = letter

def isWinner(board, letter):
    return(
        (board[7] == letter and board[8] == letter and board[9] == letter) or
        (board[4] == letter and board[5] == letter and board[6] == letter) or
        (board[1] == letter and board[2] == letter and board[3] == letter) or
        (board[7] == letter and board[4] == letter and board[1] == letter) or
        (board[8] == letter and board[5] == letter and board[2] == letter) or
        (board[9] == letter and board[6] == letter and board[3] == letter) or
        (board[7] == letter and board[5] == letter and board[3] == letter) or
        (board[9] == letter and board[5] == letter and board[1] == letter)
    )

def getBoardcopy(board):
    boardCopy = []
    for i in board:
        boardCopy.append(i)
    return boardCopy

def isSpaceFree(board, move):
    return board[move] == ' '

def getPlayerMove(board):
    move = ' '
    while move not in '1 2 3 4 5 6 7 8 9'.split() or not isSpaceFree(board, int(move)):
        print ("Your move: ")
        move = input()
    return int(move)

def chooseRandomMoveFromList(board, moveList):
    possibleMoves = []
    for i in moveList:
        if isSpaceFree(board, i):
            possibleMoves.append(i)
    if len(possibleMoves) != 0:
        return random.choice(possibleMoves)
    else:
        return None

def getComputerMove(board, computerLetter):
    if computerLetter == "X":
        playerLetter = "O"
    else:
        playerLetter = "X"

    for i in range(1,10):
        boardCopy = getBoardcopy(board)
        if isSpaceFree(boardCopy, i):
            makeMove(boardCopy, computerLetter, i)
            if isWinner(boardCopy, computerLetter):
                return i
    for i in range(1,10):
        boardCopy = getBoardcopy(board)
        if isSpaceFree(boardCopy, i):
            makeMove(boardCopy, playerLetter, i)
            if isWinner(boardCopy, playerLetter):
                return i

    if isSpaceFree(board, 5):
        return 5

    move = chooseRandomMoveFromList(board, [1,3,7,9])
    if move != None:
        return move

    return chooseRandomMoveFromList(board, [2,4,6,8])

def isBoardFull(board):
    for i in range(1, 10):
        if isSpaceFree(board, i):
            return False
    return True

def StartTicTacToe():
    print("Tic-Tac-Toe")

    while True:
        theBoard = [' '] * 10
        playerLetter, computerLetter = inputPlayerLetter()
        turn = whoGoFirst()
        print("\n"+ turn + " goes first.")

        gameIsPlaying = True

        while gameIsPlaying:
            if turn == "Player":
                print("This is the board:")
                print(boardPrint)
                drawBoard(theBoard)
                move = getPlayerMove(theBoard)
                makeMove(theBoard, playerLetter, move)

                if isWinner(theBoard, playerLetter):
                    drawBoard(theBoard)
                    print("You win!")
                    print("This is your gift:" + gift)
                    openGift = input("Press 'Enter' to open the gift: ")
                    openGiftRandom = random.choice([openGift2,openGift3,openGift4,openGift5,openGift6,openGift7,openGift8,openGift9,openGift10,openGift11,openGift12,openGift13,openGift14,openGift15])
                    print(openGiftRandom)
                    gameIsPlaying = False
                else:
                    if isBoardFull(theBoard):
                        drawBoard(theBoard)
                        print("It is a tie.")
                        break
                    else:
                        turn = "Computer"
            else:
                move = getComputerMove(theBoard, computerLetter)
                makeMove(theBoard, computerLetter, move)

                if isWinner(theBoard, computerLetter):
                    drawBoard(theBoard)
                    print("Computer wins!")
                    gameIsPlaying = False
                else:
                    if isBoardFull(theBoard):
                        drawBoard(theBoard)
                        print("It is a tie.")
                        break
                    else:
                        turn = "Player"

        print("Do you want to play again?(yes, no)")
        if not input().lower().startswith("yes"):
            break

StartTicTacToe()