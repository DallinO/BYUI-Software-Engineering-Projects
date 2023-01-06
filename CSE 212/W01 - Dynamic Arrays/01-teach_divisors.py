"""
CSE212 
(c) BYU-Idaho
01-Teach - Problem 1

It is a violation of BYU-Idaho Honor Code to post or share this code with others or 
to post it online.  Storage into a personal and private repository (e.g. private
GitHub repository, unshared Google Drive folder) is acceptable.
"""

def find_divisors_1(number):
    
    divisors = []
    for i in range(1, number + 1):
        if number % i == 0:
            divisors.append(i)

    return(divisors)

def find_divisors_2(number):
    
    divisors = [i for i in range(1, number + 1) if number % i == 0]
    return(divisors)

print(find_divisors_1(80)) # [1, 2, 4, 5, 8, 10, 16, 20, 40]
print(find_divisors_2(80)) # [1, 2, 4, 5, 8, 10, 16, 20, 40]
print(find_divisors_1(79)) # [1] ... This is prime
print(find_divisors_2(79)) # [1]
