# 1. Name:
#      -your name-
# 2. Assignment Name:
#      Lab 01: Tic-Tac-Toe
# 3. Assignment Description:
#      Play the game of Tic-Tac-Toe
# 4. What was the hardest part? Be as specific as possible.
#      -a paragraph or two about how the assignment went for you-
# 5. How long did it take for you to complete the assignment?
#      -total time in hours including reading the assignment and submitting the program-

import json

# The characters used in the Tic-Tac-Too board.
# These are constants and therefore should never have to change.
X = 'X'
O = 'O'
BLANK = ' '

# A blank Tic-Tac-Toe board. We should not need to change this board;
# it is only used to reset the board to blank. This should be the format
# of the code in the JSON file.
blank_game_data = {
    "board": [
    BLANK, BLANK, BLANK,
    BLANK, BLANK, BLANK,
    BLANK, BLANK, BLANK],
    "turn": [1]
    }


def get_game_data(filename):
    # Put file reading code here.
    try:
        with open(filename) as json_file:
            game_data = json.load(json_file)
            return(game_data)
        

    except FileNotFoundError:
        save_game(filename, blank_game_data)
        get_game_data(filename)

    


def save_game(filename, board):
    '''Save the current game to a file.'''
    # Put file writing code here.
    with open(filename, 'w') as file:
        json.dump(board, file)
    file.close()


def display_board(board):
    '''Display a Tic-Tac-Toe board on the screen in a user-friendly way.'''
    # Put display code here.
    print(f" {board['board'][0]} | {board['board'][1]} | {board['board'][2]} ")
    print("---+---+---")
    print(f" {board['board'][3]} | {board['board'][4]} | {board['board'][5]} ")
    print("---+---+---")
    print(f" {board['board'][6]} | {board['board'][7]} | {board['board'][8]} \n")


def is_x_turn(turn):
    '''Determine whose turn it is.'''
    if turn % 2 != 0:
        return True
    else:
        return False


def get_input():
    try:
        user_input = input(">>> ")
    except user_input != 'Q' or '1' or '2' or '3' or '4' or '5' or '6' or '7' or '8' or '9':
        print("Error: Input must be a position on the board or Q")
        get_input()
    return (user_input)


def play_game(filename, game_data):
    '''Play the game of Tic-Tac-Toe.'''
    # Put game play code here. Return False when the user has indicated they are done.
    gameover = False
    turn = int(game_data['turn'][0])
    while gameover == False:
        display_board(game_data)
        player_turn = is_x_turn(turn)
        
        if player_turn == True:
            print("Player X's turn:")
            user_input = get_input()
            turn += 1
            if user_input == 'Q':
                save_game(filename, game_data)
                quit()
            else:
                game_data['board'][int(user_input) - 1] = X
        
        if player_turn == False:
            print("Player O's turn:")
            user_input = get_input()
            turn += 1
            if user_input == 'Q':
                save_game(filename, game_data)
                quit()
            else:
                game_data['board'][int(user_input) - 1] = O
                
        save_game(filename, game_data)
        gameover = game_done(game_data)

    return False

def game_done(board, message=False):
    '''Determine if the game is finished.
       Note that this function is provided as-is.
       You do not need to edit it in any way.
       If message == True, then we display a message to the user.
       Otherwise, no message is displayed. '''

    # Game is finished if someone has completed a row.
    for row in range(3):
        if board['board'][row * 3] != BLANK and board['board'][row * 3] == board['board'][row * 3 + 1] == board['board'][row * 3 + 2]:
            print("The game was won by", board['board'][row * 3])
            return True

    # Game is finished if someone has completed a column.
    for col in range(3):
        if board['board'][col] != BLANK and board['board'][col] == board['board'][3 + col] == board['board'][6 + col]:
            print("The game was won by", board['board'][col])
            return True

    # Game is finished if someone has a diagonal.
    if board['board'][4] != BLANK and (board['board'][0] == board['board'][4] == board['board'][8] or
        board['board'][2] == board['board'][4] == board['board'][6]):
        print("The game was won by", board['board'][4])
        return True

    # Game is finished if all the squares are filled.
    tie = True
    for square in board['board']:
        if square == BLANK:
            tie = False
    if tie:
        if message:
            print("The game is a tie!")
        return True


    return False

# These user-instructions are provided and do not need to be changed.
print("Enter 'q' to suspend your game. Otherwise, enter a number from 1 to 9")
print("where the following numbers correspond to the locations on the grid:")
print(" 1 | 2 | 3 ")
print("---+---+---")
print(" 4 | 5 | 6 ")
print("---+---+---")
print(" 7 | 8 | 9 \n")
print("The current board is:")

# The file read code, game loop code, and file close code goes here.
def main():
    filename = 'game_save.json'
    game_data = get_game_data(filename)
    play_game(filename, game_data)

main()