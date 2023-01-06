# 1. Name:
#      Jaxon Hamm
# 2. Assignment Name:
#      Lab 09 : Sub-List Sort Program
# 3. Assignment Description:
#      Sort a list of values by breaking it up into smaller sub lists.
# 4. What was the hardest part? Be as specific as possible.
#      Honestly, after having done all the design, I just went through and
#      it worked the first time with no errors.
# 5. How long did it take for you to complete the assignment?
#      1 hour

import json
import csv

# Get the filename from the user.


def get_filename():
    return input('Enter filename:\n>>> ')


def read_file(filename):
    try:
        json_file = open('integer.json', 'r')
        data = json_file.load('integer.json')
        json_file.close()

    except:
        print('ERROR: Invalid File')
        return

    return data

# Disply the array after sorting it.


def display(array, sorted_array):
    print(f'Original array:\n{array}')
    print(f'Sorted array:\n{sorted_array}')
    return


def sort(array):
    try:
        size = len(array)
        source = array
        destination = [None] * size
        iteration = 2

        while iteration > 1:
            iteration = 0
            begin1 = 0
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
        
        return source

    except:
        print('Error: File format or data invalid')
        return


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


def build_array():
    array = []
    size = int(input('How many items in the array?\n>>> '))
    print('Enter item:')
    for x in range(size):
        item = input('>>> ')
        array.append(item)

    return array


def repeat():
    answer = ''
    while answer.upper() != 'Y' or 'N':
        answer = input('Enter a new array?\n(Y/N)>>>')
    return answer


def manual():
    answer = ''
    while answer.upper() != 'Y' or 'N':
        answer = input('Upload file?\n(Y/N)>>> ')
        if answer.upper() == 'Y':
            file = get_filename()
            array = read_file(file)
            sorted_array = sort(array)
            display(array, sorted_array)
        elif answer.upper() == 'N':
            array = build_array()
            sorted_array = sort(array)
            display(array, sorted_array)
        
        repeat_answer = repeat()
        if repeat_answer.upper() == 'N':
            quit()

    return


def test_cases():
    files = ['empty.json',
             'single.json',
             'non-list_parameter.json',
             'integer.json',
             'float.json',
             'string.json',
             'large.json',
             'mixed.json',
             'sorted.json',
             'reverse_sorted.json',
             'sublist.json',
             'duplicate_entries.json']

    for file in files:
        array = read_file(file)
        sorted_array = sort(array)
        print(f'File: {file}')
        display(array, sorted_array)

    return


def mode_select():
    mode = 0
    while mode != 1 or 2:
        mode = int(input('Select mode:\n1) Manual Entry\n2) Run Test Cases\n>>> '))
        if mode == 1:
            manual()
        elif mode == 2:
            test_cases()


def main():
    mode_select()


filename = 'integer.json'
read_file(filename)
