"""
CSE212 
(c) BYU-Idaho
01-Teach - Problem 2

It is a violation of BYU-Idaho Honor Code to post or share this code with others or 
to post it online.  Storage into a personal and private repository (e.g. private
GitHub repository, unshared Google Drive folder) is acceptable.
"""

def list_selector(list1, list2, selector):
    
    list1_index = 0
    list2_index = 0
    combined_list = []

    for x in selector:
        if x == 1:
            combined_list.append(list1[list1_index])
            list1_index += 1
        
        if x == 2:
            combined_list.append(list2[list2_index])
            list2_index += 1

    return(combined_list)

l1 = [1, 2, 3, 4, 5]
l2 = [2, 4, 6, 8, 10]
select = [1, 1, 1, 2, 2, 1, 2, 2, 2, 1]
print(list_selector(l1, l2, select))  # [1, 2, 3, 2, 4, 4, 6, 8, 10, 5]

l1 = ['A', 'A', 'A', 'A', 'A']
l2 = ['B', 'B', 'B', 'B', 'B']
select = [1, 2, 1, 2, 1, 2, 1, 2, 1, 2]
print(list_selector(l1, l2, select))  # ['A', 'B', 'A', 'B', 'A', 'B', 'A', 'B', 'A', 'B', ]