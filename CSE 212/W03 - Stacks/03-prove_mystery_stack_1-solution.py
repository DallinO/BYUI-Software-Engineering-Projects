def mystery_1(text):
    stack = []

    for letter in text:
        stack.append(letter)

    result = ""
    while len(stack) > 0:
        result += stack.pop()
        print(result)
    
    return result

text = "a nut for a jar of tuna"
result = mystery_1(text)
print(result)