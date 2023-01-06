# 1. Name:
#      Dallin Olson
# 2. Assignment Name:
#      Lab 05 : Sudoku Draft
# 3. Assignment Description:
#      This program simulates the game of sudoku. Currently the program will
#      load in a sudoku board and the user can add a value to a given coordinate.
#      It does not currently protect against overwriting existing data.
# 4. What was the hardest part? Be as specific as possible.
#      The most difficut part was validating and converting the coordinate input
#      and finding a simple way to display the board. I ended up speaking with a
#      tutor who showed me the ord() and chr() functions in order to help with
#      passing the coordinate data. He also showed me end= parameter in print to
#      help simplify printing the board.
# 5. How long did it take for you to complete the assignment?
#      It took about three hours including the hour I spent with my tutor.

import json

# An empty board variable to load in if validating the file fails.
default_board = [
    [0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0]
]


# Load the board data from a given file.
def load_board(filename):
    
    try:
        file = open(filename, "r")
        text_data = file.read()
        json_data = json.loads(text_data)
        return(json_data['board'])


    # Will return an empty board if the file does not exist.
    except:
        return(default_board)


# Saves the board data.
def save_board(filename, board):

    with open(filename, "w") as file:

        json_data = {}
        json_data['board'] = board
        text_data = json.dumps(json_data)
        file.write(text_data)


# Displays the board.
def display_board(board):

    print('  A B C D E F G H I')

    for row in range(0, 9):
        if row == 3 or row == 6:
            print('  -----+-----+-----')
        print(row + 1, '', end='')

        for column in range(0, 9):
            boarder = [' ', ' ', '|', ' ', ' ', '|', ' ', ' ', '\n']
            if board[row][column] != 0:
                print(board[row][column], end= boarder[column])
            else:
                print(' ', end= boarder[column])


# Utilizes the ord() function to convert to unicode for easier data transfer.
def get_coordinate(coordinate):

    column = ord(coordinate[0]) - ord('A')
    row = int(coordinate[1]) - 1
    return(row, column)


# The director directs the flow of a game.
def director(board):

    coordinate = input("Enter a coordinate: ")
    if coordinate == 'Q':
        return False

    (row, column) = get_coordinate(coordinate)
    number = int(input('Enter the value for the coordinate: '))

    board[row][column] = number
    return True


# The main function that starts and ends the game.
def main():

    filename = input('Enter the filename: ')
    board = load_board(filename)
    display_board(board)

    while director(board):
        display_board(board)

    save_board(filename, board)

main()