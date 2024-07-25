
def find_empty(sudoku, l):
    for i in range(9):
        for j in range(9):
            if sudoku[i][j] == 0:
                l[0] = i
                l[1] = j
                return True
    return False



def is_safe(sudoku, row, col, num):

    # check in row and col
    for i in range(9):
        if sudoku[row][i] == num:
            return False
        if sudoku[i][col] == num:
            return False

        
    # check in box
    start_row = row - row % 3
    start_col = col - col % 3

    for i in range(3):
        for j in range(3):
            if sudoku[start_row + i][start_col + j] == num:
                return False

    # found nowhere, therefore true
    return True



def sudoku_solve(sudoku):
    l = [0, 0]

    # find empty cell x, y coordinates
    # if not found, means sudoku is solved
    # return from function
    if not find_empty(sudoku, l):
        return True

    # coordinates of empty cell
    row = l[0]
    col = l[1]

    # solve using backtracking
    for num in range(1, 10):
        if is_safe(sudoku, row, col, num):
            sudoku[row][col] = num
            if sudoku_solve(sudoku):
                return True
            sudoku[row][col] = 0

    return False



# Example usage
sudoku = [[3,0,6,5,0,8,4,0,0],
[5,2,0,0,0,0,0,0,0],
[0,8,7,0,0,0,0,3,1],
[0,0,3,0,1,0,0,8,0],
[9,0,0,8,6,3,0,0,5],
[0,5,0,0,9,0,6,0,0],
[1,3,0,0,0,0,2,5,0],
[0,0,0,0,0,0,0,7,4],
[0,0,5,2,0,6,3,0,0]]

# sudoku can be solved, then print
# else don't
if sudoku_solve(sudoku):
    for i in sudoku:
        print(i)
