def find_empty(sudoku, l):
    for i in range(9):
        for j in range(9):
            if sudoku[i][j] == 0:
                l[0] = i
                l[1] = j
                return True
    return False

def is_safe(sudoku, row, col, num):
    for i in range(9):
        if sudoku[row][i] == num:
            return False
        if sudoku[i][col] == num:
            return False

    start_row = row - row % 3
    start_col = col - col % 3

    for i in range(3):
        for j in range(3):
            if sudoku[i + start_row][j + start_col] == num:
                return False

    return True

def sudoku_solve(sudoku):
    l = [0, 0]
    if not find_empty(sudoku, l):
        return True

    row = l[0]
    col = l[1]

    for num in range(1, 10):
        if is_safe(sudoku, row, col, num):
            sudoku[row][col] = num
            if sudoku_solve(sudoku):
                return True
            sudoku[row][col] = 0
    
    return False

sudoku = [[0, 0, 2, 7, 0, 0, 6, 0, 0],
          [5, 0, 8, 6, 0, 0, 0, 3, 0],
          [7, 0, 0, 0, 0, 8, 0, 0, 9],
          [4, 2, 7, 1, 0, 0, 0, 0, 0],
          [0, 0, 5, 8, 6, 0, 0, 4, 0],
          [0, 0, 0, 0, 0, 4, 0, 0, 0],
          [8, 7, 0, 4, 0, 0, 9, 0, 0],
          [0, 0, 0, 2, 0, 6, 0, 5, 0],
          [0, 0, 0, 0, 0, 0, 0, 7, 3]]

if sudoku_solve(sudoku):
    for i in sudoku:
        print(i)