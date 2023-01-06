import random

def main():

    quantity = quantityFunction()
    tense = tenseFunction()
    determiner = getDeterminer(quantity)
    noun = getNoun(quantity)
    verb = getVerb(tense, quantity)
    display(determiner, noun, verb)

    return 0

def display(determiner, noun, verb):
    print(f'\033[0;33;40m{determiner} {noun} {verb}\033[0;37;40m')
    repeatFunction()

def repeatFunction():
    repeat = input('\033[0;37;40mWould you like to try again (y/n)?\033[0;32;40m ')
    if repeat.lower() == 'y':
        main()
    elif repeat.lower() == 'n':
        exit()
    else:
        print('\033[0;31;40mERROR: INVALID INPUT\033[0;37;40m')
        repeatFunction()


def getVerb(tense, quantity):
    if tense.lower() == 'past':
        pastVerbList = ['drank', 'ate', 'grew', 'laughed', 'thought',
        'ran', 'slept', 'talked', 'walked', 'wrote']
        return random.choice(pastVerbList)
    
    elif tense.lower() == 'present':
        if quantity == 1:
            pluralVerbList = ['drink', 'eat', 'grow', 'laugh', 'think',
            'run', 'sleep', 'talk', 'walk', 'write']
            return random.choice(pluralVerbList)

        elif quantity == 0:
            singularVerbList = ['drinks', 'eats', 'grows', 'laughs', 'thinks',
            'runs', 'sleeps', 'talks', 'walks', 'writes']
            return random.choice(singularVerbList)

    elif tense.lower() == 'future':
        futureVerblist = ['will drink', 'will eat', 'will grow', 'will laugh',
        'will think', 'will run', 'will sleep', 'will talk',
        'will walk', 'will write']
        return random.choice(futureVerblist)
    
    else:
        print('\033[0;31;40mVERB FUNCTION ERROR\033[0;37;40m')
        return 'ERROR\033[0;31;40m'
    
def getNoun(quantity):
    if quantity == 1:
        pluralNounList = ['adults', 'birds', 'boys', 'cars', 'cats',
        'children', 'dogs', 'girls', 'men', 'women']
        return random.choice(pluralNounList)

    elif quantity == 0:
        singularNounList = ['adult', 'bird', 'boy', 'car', 'cat',
        'child', 'dog', 'girl', 'man', 'woman']
        return random.choice(singularNounList)

    else:
        print('\033[0;31;40mNOUN FUNCTION ERROR\033[0;37;40m')
        return 'ERROR\033[0;31;40m'

def quantityFunction():
    quantity = input('\033[0;37;40mWhat is the quantity of the subject.\n'
    'Is the subject singular or plural? \033[0;32;40m')
    if quantity.lower() == 'singular':
        return 0
    if quantity.lower() == 'plural':
        return 1
    else:
        print('\033[0;31;40mQUANTITY FUNCTION ERROR: INVALID INPUT\033[0;37;40m')
        quantityFunction()

def tenseFunction():
    tense = input('\033[0;37;40mDoes this occur in the past, present, or future?'
    '\033[0;32;40m ')
    if tense.lower() == 'past' or 'present' or 'future':
        return tense
    else:
        print('\033[0;31;40mTENSE FUNCTION ERROR: INVALID INPUT\033[0;37;40m')
        tenseFunction()

def getDeterminer(quantity):
    if quantity == 0:
        singularDeterminerList = ['The', 'A', 'An', 'This', 'Two']
        return random.choice(singularDeterminerList)    
    if quantity == 1:
        pluralDeterminerList = ['The','Those', 'Few', 'Many', 'Three']
        return random.choice(pluralDeterminerList)
    else:
        print('\033[0;31;40m DETERMINER FUNCTION ERROR')
        return '\033[0;31;40m ERROR'
    

main()



    