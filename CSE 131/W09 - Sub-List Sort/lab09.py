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


# Colors class to add text colors to help with viewing the terminal output
# while also maintaining code readability.
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


# Get the filename from the user.
def get_filename():
    return input('Enter filename:\n' + colors.WARNING + '>>> ' + colors.ENDC)


# Read json data from file and store it in a list.
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


# Disply the array after sorting it.
def display(array, sorted_array):
    print(colors.HEADER + 'Original Array:' + colors.ENDC)
    print(array)
    print(colors.HEADER + 'Sorted Array:' + colors.ENDC)
    print(f'{sorted_array}\n\n\n')
    return


# The primary sorting algorithm. Divides the array up into sub lists and then
# merges the lists together.
def sort(array):
    try:
        size = len(array)
        source = array[:]
        destination = [None] * size
        iteration = 2

        # Begin iteration.
        while iteration > 1:
            iteration = 0
            begin1 = 0
            # Goes through each sublist.
            while begin1 < size:
                end1 = begin1 + 1
                while end1 < size and source[end1 - 1] <= source[end1]:
                    end1 += 1

                begin2 = end1

                if begin2 < size:
                    end2 = begin2 + 1
                else:
                    end2 = begin2
                while end2 < size and source[end2 - 1] <= source[end2]:
                    end2 += 1

                iteration += 1
                combine(source, destination, begin1, begin2, end2)
                begin1 = end2
            source, destination = destination, source

        return(source)

    except:
        print(colors.FAIL + 'ERROR: File Format or Data Invalid' + colors.ENDC)
        return


# Combines the sublists.
def combine(source, destination, begin1, begin2, end2):
    end1 = begin2

    for i in range(begin1, end2):
        if (begin1 < end1) and (begin2 == end2 or source[begin1] < source[begin2]):
            destination[i] = source[begin1]
            begin1 += 1
        else:
            destination[i] = source[begin2]
            begin2 += 1
    return


# Buils custom array.
def build_array():
    array = []
    size = int(input('How many items in the array?\n' +
    colors.WARNING + '>>> ' + colors.ENDC))
    print('Enter item:')
    for x in range(size):
        item = input(colors.WARNING + '>>> ' + colors.ENDC)
        array.append(item)

    return array


# Allows the user to enter a custom file name or build thier own array.
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


# Load and run test cases from json files.
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

    for file in files:
        print(colors.HEADER + 'File: ' + colors.ENDC + file)
        array = read_file(file)
        sorted_array = sort(array)
        display(array, sorted_array)

    return


# Select whether to enter a file or array manually or run the test cases.
def mode_select():
    mode = 0
    while mode != 1 or 2:
        mode = int(input('Select mode:\n1) Manual Entry\n2) Run Test Cases\n'
        + colors.WARNING + '>>> ' + colors.ENDC))
        if mode == 1:
            manual()
        elif mode == 2:
            test_cases()


# The main function that initiates the program.
def main():
    mode_select()


main()