# 1. Name:
#      Dallin Olson
# 2. Assignment Name:
#      Lab 03 : Calendar Program
# 3. Assignment Description:
#      This program returns the calendar of any Gregorian year.
# 4. What was the hardest part? Be as specific as possible.
#      One difficulty was getting the calendar to start on the right week day.
#      I also had a hard time catching invalid inputs that were our of range. I
#      Started with using 'try' and 'except' but it kept ending the program so
#      I switched to using while loops.
# 5. How long did it take for you to complete the assignment?
#      It took about two hours.

def display_table(dow, num_days):
    '''Display a calendar table'''
    assert(type(num_days) == type(dow) == type(0))
    assert(0 <= dow <= 6)
    assert(28 <= num_days <= 31)

    # Display a nice table header
    print("  Su  Mo  Tu  We  Th  Fr  Sa")

    # Indent for the first day of the week
    for indent in range(dow):
        print("    ", end='')

    # Display the days of the month
    for dom in range(1, num_days + 1):
        print(repr(dom).rjust(4), end='')
        dow += 1
        # Newline after Saturdays
        if dow % 7 == 0:
            print("") # newline

    # We must end with a newline
    if dow % 7 != 0:
        print("") # newline
        

def is_leap_year(user_year):

    is_leap = False
    if user_year % 400 == 0:
        is_leap =  True
    elif user_year % 100 == 0 and user_year % 400 != 0:
        is_leap = False
    elif user_year % 4 == 0 and user_year % 100 != 0:
        is_leap = True
    else:
        is_leap = False

    return is_leap


def get_year():
    valid = False
    while valid == False:

        print("Enter the year")
        while True:
            try:
                year = int(input(">>> "))
                break
            except:
                print('Input must be type int')

        if year < 1753 or type(year) != int:
            print("Error: Year must be 1753 or later")
        else:
            valid = True
    
    return year


def get_month():
    valid = False
    while valid == False:

        print("Enter the month number")
        while True:
            try:
                month = int(input(">>> "))
                break
            except:
                print('Input must be type int')

        if (month < 1 or month > 12):
            print("Error: Month must be an integer between 1 and 12")
        else:
            valid = True
    
    return month


def find_num_days(user_month, user_year):
    total_num_days = 365
    for month in range(1,user_month):
        total_num_days += find_number_days_in_month(month, user_year)
    
    for year in range(1753,user_year):
        if is_leap_year(year):
            total_num_days += 366
        else:
            total_num_days +=365
    return total_num_days


def find_number_days_in_month(user_month, user_year):
    dom = 0
    long_month = [1,3,5,7,8,10,12]
    short_month = [4,6,9,11]
    if user_month in long_month:
        dom = 31
    elif user_month in short_month:
        dom = 30
    elif user_month == 2:
        if is_leap_year(user_year):
            dom = 29
        else:
            dom = 28
    return dom


def find_dow(num_days):
    dow = num_days % 7
    return dow


def main():
    
    while True:
        user_month = get_month()
        user_year = get_year()
        num_days = find_num_days(user_month, user_year)
        dow = find_dow(num_days)
        num_days_in_month = find_number_days_in_month(user_month,user_year)
        display_table(dow, num_days_in_month)
        while True: 
            print('Print new calendar?')
            query = input('>>> ')
            if query == '' or not query[0].lower() in ['y','n']: 
                print('Please answer with yes or no!') 
            else: 
                break 
        if query[0].lower() == 'y': 
            continue 
        if query[0].lower() == 'n': 
            quit() 


if __name__ == "__main__":
    main()