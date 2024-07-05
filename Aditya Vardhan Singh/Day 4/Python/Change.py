def check_change(bills):
    ''' Check if we can provide change to every customer '''
    desk = [0] * 3
    for i in bills:
        # submit change in our desk
        match i:
            case 5: desk[0] += 1
            case 10: desk[1] += 1
            case 20: desk[2] += 1
            case _: pass
        # check change
        change = i - 5
        # check and return change
        if change == 15: 
            if desk[1] > 0 and desk[0] > 0: 
                desk[1] -= 1
                desk[0] -= 1
            elif desk[0] > 3:
                desk[0] -= 3
            else:
                return False
        elif change == 5:
            if desk[0] > 0:
                desk[0] -= 1
            else: 
                return False
    return True

bills = [5, 5, 5, 10, 20, 10, 10]
print( check_change(bills) )