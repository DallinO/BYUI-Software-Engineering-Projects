###############################################################################
# 15.1: Euro to Dollar Conversion                                                             
###############################################################################

def dollars_from_euro_test():
    test_cases = [1, 0.88, 0.50, 0.89, -1, -0.50, 0, 0.01, 0.00000001, -0.01,
    -0.00000001, 19004280.06, 21474836.47, 81622761388095350]

    for test in test_cases:
        dollar = dollars_from_euro(test)
        print(dollar)

def dollars_from_euro(euro):
    return round(euro * 1.13, 2)

#dollars_from_euro_test()

###############################################################################
# 15.2: Leap Year                                                             
###############################################################################

def is_leap_year(year):

    assert type(year) == int , 'Error: type must be int'
    assert year >= 1753 , 'Error: Must be gregorian calander year'

    if year % 4 != 0:
        return False
    if year % 100 != 0:
        return True
    return (year % 400 == 0)

def is_leap_year_test():
    test_cases = [2001, 2004, 2100, 2000, 1753, 1752, 0, -1]

    for test in test_cases:
        leap_year = is_leap_year(test)
        print(leap_year)

#is_leap_year_test()

###############################################################################
# 15.3: Tax Conversion                                                           
###############################################################################

# Compute federal income tax based on income.

def compute_tax(income):
    # incomes under $61,300 first
    if income < 61300.00:

        # 15% tax bracket.
        if income >= 15100.00:
            return round(1510.00 + 0.15 * (income - 15100.00), 2)
        # 0% tax bracket.
        elif income <= 0.00:
            return 0.00
        # 10% tax bracket.
        else:
            return round(income * 0.10, 2)

    # incomes over $61,300 next
    else:
        # 25% tax bracket.
        if income < 123700.00:
            return round(8440.00 + 0.25 * (income - 61300.00), 2)
        # 28% tax bracket.
        elif income < 188450.00:
            return round(24040.00 + 0.28 * (income - 123700.00), 2)
        # 33% tax bracket.
        elif income < 336550.00:
            return round(42170.00 + 0.33 * (income - 188450.00), 2)
        # 35% tax bracket.
        else:
            return round(91043.00 + 0.35 * (income - 336550.00), 2)
    assert(False)

def compute_tax_test():
    # Test cases.
    test_cases = {'Input': [0, 0.10, 10000, 15099.99, 15100, 15100.01,
        50000.00, 61299.99, -0.01, -10000],
        'Expected Output': [0, 0.01, 1000, 1510, 1510, 1510, 6745, 10478.50, 0, 0]}

    for x in range(len(test_cases['Input'])):
        # Compute tax.
        tax = compute_tax(test_cases['Input'][x])
        # Print tax with expected output.
        print('Tax: %9.2f Expected: %9.2f' %
        (tax, test_cases['Expected Output'][x]))

#compute_tax_test()

###############################################################################
# 15.4: Search                                                          
###############################################################################

def search(array, element):
    ''' Determine if value is in array. '''
    # Initialize the indices for the search.
    i_first = 0
    i_last = len(array) - 1
    found = False

    # Loop until the value is found
    while i_first <= i_last and not found:
        i_middle = int((i_first + i_last) / 2)

        # Found!
        if array[i_middle] == element:
            found = True

        # Too high or too low.
        elif array[i_middle] < element:
            i_first = i_middle + 1
        else:
            i_last = i_middle - 1
    return found

def search_test():
    # Test cases:
    test_cases = {'Input': [([], 0), ([0], 1), ([0], 0), ([0, 2], 4),
        ([0, 2], 1), ([0, 2], -1), ([0, 2], 0), ([0, 2], 2), ([0, 2, 4], 6),
        ([0, 2, 4], 3), ([0, 2, 4], -1), ([0, 2, 4], 0), ([0, 2, 4], 2),
        ([0, 2, 4], 4), ([4, 2, 0], 5)],
        'Expected Output': [False, False, True, False, False, False, True,
        True, False, False, False, True, True, True, False]}
    
    # Compare output with expected result.
    for x in range(len(test_cases['Input'])):
        found = search(test_cases['Input'][x][0], test_cases['Input'][x][1])
        print('Found:', found, 'Expected: ', test_cases['Expected Output'][x])

#search_test()