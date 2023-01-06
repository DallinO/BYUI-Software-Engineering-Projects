"""
Dallin Olson
April 30, 2021
CSE 111
02 Prove Assignment
"""

import math
from datetime import datetime



print("Welcome to Tire Volume Calculator")
print("*********************************")

def main():
    main.width = int(input("Enter the width of the tire in mm: "))
    main.aspect_ratio = int(input("Enter the aspect ratio of the tire: "))
    main.diameter = int(input("Enter the diameter of the wheel in inches: "))

    main.volume = round(((math.pi * main.width ** 2 * main.aspect_ratio * 
    (main.width * main.aspect_ratio + 2540 * main.diameter)) / 10000000), 1)

    print(f"The approximate volume is {main.volume} milliliters.")
    data_upload()

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

def data_upload():
    current_date_and_time = datetime.now()   
    with open("dimensions.txt", "at") as dimens_file:
        print("*********************************\n", file=dimens_file)
        print(f"{current_date_and_time}\n", file=dimens_file)
        print(f"{main.aspect_ratio}, {main.width}, {main.diameter}, {main.volume}\n", file=dimens_file)
        print("*********************************\n", file=dimens_file)
        repeat()



#def data_upload():

    #current_date_and_time = datetime.now()
    #data_file = open("data.txt","w")
    #data_file.write(f"{current_date_and_time}\n")
    #data_file.write(f"{main.aspect_ratio}, {main.width}, {main.diameter}, {main.volume}")
    #data_file.close()
    #repeat()



main()


