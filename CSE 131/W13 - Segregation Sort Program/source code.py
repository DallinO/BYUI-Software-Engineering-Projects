# 1. Name:
#      Dallin Olson
# 2. Assignment Name:
#      Lab 13 : Segregation Sort Program
# 3. Assignment Description:
#      Sorts an array of itemss using recursion to seperate the array into
#      incrementally smaller arrays.
# 4. What was the hardest part? Be as specific as possible.
#      I again had an issue with the algorithm operating on my originaly array
#      instead of the copy I made in order to display both versions. I tried
#      using 'source = array[:]' like I did in the previous lab but I would get
#      errors. I then realized I had been copying the data using 'source = array'.
#      Instead I simply had source equal the outcome of the function call.
# 5. How long did it take for you to complete the assignment?
#      3 hours

import json

###############################################################################
# Colors class to add text colors to help with viewing the terminal output
# while also maintaining code readability.
###############################################################################
class colors:
    HEADER = '\033[95m'
    BLUE = '\033[94m'
    CYAN = '\033[96m'
    GREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'


###############################################################################
# Get the filename from the user.
###############################################################################
def get_filename():
    return input('Enter filename:\n' + colors.WARNING + '>>> ' + colors.ENDC)


###############################################################################
# Read json data from file and store it in a list.
###############################################################################
def read_file(filename):
    try:
        json_file = open(filename, 'r')
        json_data = json_file.read()
        data = json.loads(json_data)
        json_file.close()

    except:
        print(colors.FAIL + 'ERROR: Invalid File' + colors.ENDC + '\n\n\n')
        return

    return data


###############################################################################
# Disply the array after sorting it.
###############################################################################
def display(array, sorted_array):
    print(colors.HEADER + 'Original Array:' + colors.ENDC)
    print(array)
    print(colors.HEADER + 'Sorted Array:' + colors.ENDC)
    print(f'{sorted_array}\n\n\n')
    return


###############################################################################
# Initializes the recursize segregation sorting algorithm while also testing
# for a valid array.
###############################################################################
def sort(array):
    
    # Catches arrays that have improper data or are in an invalid format.
    try:
        # Copy original array to avoid altering the data which will be
        # used to display both the original and sorted array.
        source = array.copy()
        sort_recursive(source, 0, len(source) - 1)
    except:
        print(colors.FAIL + 'ERROR: File Format or Data Invalid' + colors.ENDC)
        return

    return source


###############################################################################
# Controls the recusion aspect of the segregation algorithm.
###############################################################################
def sort_recursive(array, i_begin, i_end):

    if i_end - i_begin < 1 or i_end < 0:
        return

    # Determin i_pivot through segregate() funciton.
    i_pivot = segregate(array, i_begin, i_end)
    # Loop using recursion.
    sort_recursive(array, i_begin, i_pivot - 1)
    sort_recursive(array, i_pivot + 1 , i_end)


###############################################################################
# Sorts the array through swaping elements based on pivot points.
###############################################################################
def segregate(array, i_begin, i_end):

    # Return if the indexes are the same.
    if i_begin == i_end:
        return i_begin
    # Set the pivot to the middle of the array.
    i_pivot = (i_begin + i_end) // 2
    # Set i_up and i_down to the start and end positions.
    i_up = i_begin
    i_down = i_end

    while i_up < i_down:
        # Check if i_up  is greater than i_up and stop incrementing once the
        # value  in the array at i_down is less than the pivot.
        while i_up < i_down and array[i_up] < array[i_pivot]:
            i_up = i_up + 1
        # Check if i_down is greater than i_up and stop incrementing once the
        # value  in the array at i_down is less than the pivot.
        while i_up < i_down and array[i_down] >= array[i_pivot]:
            i_down = i_down - 1
        # Check if indexes are equal to eachother.
        if i_up < i_down:
            # Adjust pivot values.
            if i_down == i_pivot:
                i_pivot = i_up
            elif i_up == i_pivot:
                i_pivot = i_down
            # Swap the elements in the array.
            array[i_up], array[i_down] = array[i_down], array[i_up]
    # Swap the elements in the array.
    array[i_up], array[i_pivot] = array[i_pivot], array[i_up] 
    return i_up



###############################################################################
# Builds a custom array.
###############################################################################
def build_array():
    array = []
    size = int(input('How many items in the array?\n' +
    colors.WARNING + '>>> ' + colors.ENDC))
    print('Enter item:')
    for x in range(size):
        print(colors.WARNING + '>>> ' + colors.ENDC, end='')
        item = input()
        array.append(item)

    return array


###############################################################################
# Allows the user to enter a custom file name or build thier own array.
###############################################################################
def manual():
    answer = ''
    while answer.upper() != 'Y' or 'N':
        answer = input('Upload file?\n' + colors.WARNING +
        '(Y/N)>>> ' + colors.ENDC)
        if answer.upper() == 'Y':
            file = get_filename()
            array = read_file(file)
            sorted_array = sort(array)
            display(array, sorted_array)
        elif answer.upper() == 'N':
            array = build_array()
            sorted_array = sort(array)
            display(array, sorted_array)

        quit()


###############################################################################
# Load and run test cases from json files.                                   
###############################################################################
def test_cases():
    files = [
        'empty.json',
        'single.json',
        'non-list_parameter.json',
        'large.json',
        'integer.json',
        'string.json',
        'float.json',
        'mixed.json',
        'sorted.json',
        'reverse.json',
        'sublist.json',
        'duplicate_entries.json'
        ]

    # Iterates through each test case in the files list.
    for file in files:
        print(colors.HEADER + 'File: ' + colors.ENDC + file)
        array = read_file(file)
        sorted_array = sort(array)
        display(array, sorted_array)

    return


###############################################################################
# Prompts the user to select if they would like to rerun the sorting algorithm.
###############################################################################
def repeat():
    answer = ''
    while answer.upper() != 'Y' or 'N':
        answer = input('Return to mode selection?\n' 
        + colors.WARNING + '(Y/N)>>> ' + colors.ENDC)
        if answer.upper() == 'Y':
            return
        if answer.upper() == 'N':
            exit()


###############################################################################
# Select whether to enter a file or array manually or run the test cases.
###############################################################################
def mode_select():
    mode = 0
    while mode != 1 or 2:
        mode = int(input('Select mode:\n1) Manual Entry\n2) Run Test Cases\n'
        + colors.WARNING + '>>> ' + colors.ENDC))
        if mode == 1:
            manual()
        elif mode == 2:
            test_cases()
        repeat()


###############################################################################
# The main function that initiates the program.
###############################################################################
def main():
    mode_select()


main()