"""
Dallin Olson
April 24, 2021
CSE 111
01 Prove Milestone
"""

import math

print("Welcome to Tire Volume Calculator")
print("*********************************")

def main():
    width = int(input("Enter the width of the tire in mm: "))
    aspect_ratio = int(input("Enter the aspect ratio of the tire: "))
    diameter = int(input("Enter the diameter of the wheel in inches: "))

    volume = round(((math.pi * width ** 2 * aspect_ratio * (width * aspect_ratio + 2540 * diameter)) / 10000000), 1)

    print(f"The approximate volume is {volume} milliliters.")
    repeat()

def repeat():
    answer = input("Would you like to calculate another volume (Y/N)? ")
    if answer.upper() == "Y":
        main()
    if answer.upper() == "N":
        print("The program will now close")
        exit()
    else:
        print("Error: Invalid input")
        repeat()

main()