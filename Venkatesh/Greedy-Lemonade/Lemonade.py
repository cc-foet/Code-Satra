def change(bills):
    fives = 0
    tens = 0
    for bill in bills:
        if bill == 5:
            fives += 1
        elif bill == 10:
            if fives == 0:
                return False
            tens += 1
            fives -= 1
        else:   
            if tens > 0:
                if fives == 0:
                    return False
                tens -= 1
                fives -= 1
            else:
                if fives < 3:
                    return False
                fives -= 3
    return True

n = 5
bills = [10, 5, 5, 20, 5]

bills.sort()
print(change(bills))