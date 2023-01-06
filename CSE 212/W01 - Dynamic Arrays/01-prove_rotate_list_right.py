"""
CSE212 
(c) BYU-Idaho
01-Prove - Problem 2

It is a violation of BYU-Idaho Honor Code to post or share this code with others or 
to post it online.  Storage into a personal and private repository (e.g. private
GitHub repository, unshared Google Drive folder) is acceptable.
"""

def rotate_list_right(data, amount):
    """
    Rotate the 'data' to the right by the 
    'amount'.   For example, if the data is 
    [1, 2, 3, 4, 5, 6, 7, 8, 9] and an amount
    is 5 then the list returned should be 
    [5, 6, 7, 8, 9, 1, 2, 3, 4].  The value 
    of amount will be in the range of 1 and 
    len(data).
    """
    new_list = []

    # By defualt the data is appended on the right, allowing us to focus on
    # alter the location of the data that is originally on the right of the
    # amount.
    for index in range(len(data)):

        # The index value of the amount which tells us where to swap the data.
        # This variable was created simply to add readability to the code.
        pivot = len(data) - amount
        # The index where we insert the data from the original list right side
        # to the new list on the left.
        # This variable was created simply to add readability to the code.
        insert_point = (index - len(data)) + amount
        
        # Check to see if the data we wish to alter (that which is on the right
        # of the amount) is greater or equal to the pivot point.
        if index >= pivot:
            new_list.insert(insert_point, data[index])
        
        # Defualt operation to append the data.
        else:
            new_list.append(data[index])

    return(new_list)

print(rotate_list_right([1,2,3,4,5,6,7,8,9],1)) # [9, 1, 2, 3, 4, 5, 6, 7, 8]
print(rotate_list_right([1,2,3,4,5,6,7,8,9],5)) # [5, 6, 7, 8, 9, 1, 2, 3, 4]
print(rotate_list_right([1,2,3,4,5,6,7,8,9],9)) # [1, 2, 3, 4, 5, 6, 7, 8, 9]