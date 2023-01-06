"""
CSE212 
(c) BYU-Idaho
05-Prove - Problem 1 - Solution

It is a violation of BYU-Idaho Honor Code to post or share this code with others or 
to post it online. 

This solution should not be shared with students.
"""

def intersection(set1, set2):
    """
    Perform an intersection between 2 sets.  An intersection will contain
    the items in common between both sets.  Do not use the set 
    operators (+, -, *, &amp;, |) and functions (intersection, union) 
    that are built-in to Python.
    
    Only need to loop through one set because if its not in the 1st set, 
    then it won't be in the intersection of the 2 sets. 
    """
    result = set()
    for item in set1:
        if item in set2:
            result.add(item)
    return result

def union(set1, set2):
    """
    Perform a union between 2 sets.  A union will contain all the items
    from both sets.  Do not use the set operators (+, -, *, &amp;, |) and 
    functions (intersection, union) that are built-in to Python.
    
    Will need to loop through both sets because there are likely values 
    in the 2nd set which are not in the 1st set.
    """
    result = set()
    for item in set1:
        result.add(item)
    for item in set2:  #
        result.add(item)
    return result

s1 = {1,2,3,4,5}
s2 = {4,5,6,7,8}
print(intersection(s1,s2))  # Should show {4, 5}
print(union(s1,s2)) # Should show {1, 2, 3, 4, 5, 6, 7, 8}

s1 = {1,2,3,4,5}
s2 = {6,7,8,9,10}
print(intersection(s1,s2))  # Should show an empty set
print(union(s1,s2)) # Should show {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}

