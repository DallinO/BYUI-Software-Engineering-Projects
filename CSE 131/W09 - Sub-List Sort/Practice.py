def funciton_16_3(x, y):
    if x == 1:
        return y
    else:
        return y + funciton_16_3(x - 1, y)


def funciton_16_4(x, y):
    if x == 0:
        return 1
    else:
        return y * funciton_16_4(x - 1, y)


def funciton_16_5(x, y):
    if x == 0:
        return y
    else:
        return 1 + funciton_16_5(x - 1, y)

test_16_3 = funciton_16_3(3, 3)
test_16_4 = funciton_16_4(3, 3)
test_16_5 = funciton_16_5(3, 3)
print(test_16_3)
print(test_16_4)
print(test_16_5)