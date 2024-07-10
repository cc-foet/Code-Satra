def spiral(matrix):
    m = len(matrix)
    n = len(matrix[0])
    
    result = []
    top_row = 0
    bottom_row = m - 1
    left_col = 0
    right_col = n - 1

    while top_row <= bottom_row and left_col <= right_col:
        for i in range(left_col, right_col + 1):
            result.append(matrix[top_row][i])
        top_row += 1

        for i in range(top_row, bottom_row + 1):
            result.append(matrix[i][right_col])
        right_col -= 1

        if top_row <= bottom_row:
            for i in range(right_col, left_col - 1, -1):
                result.append(matrix[bottom_row][i])
            bottom_row -= 1

        if left_col <= right_col:
            for i in range(bottom_row, top_row - 1, -1):
                result.append(matrix[i][left_col])
            left_col += 1

    return result


matrix = [
    [1, 2, 3, 4],
    [5, 6, 7, 8],
    [9, 10, 11, 12],
    [13, 14, 15, 16]
    ]
k = 7

print(spiral(matrix)[k-1])