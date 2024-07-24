def solve_n_queen(n):

    def is_safe(board, row, col):

        for i in range(col):
            if board[row][i] == 1:
                return False

        for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
            if board[i][j] == 1:
                return False

        for i, j in zip(range(row, n, 1), range(col, -1, -1)):
            if board[i][j] == 1:
                return False

        return True

    def solve_nq_util(board, col):
        # If all queens are placed, return True
        if col >= n:
            return True

        for i in range(n):
            if is_safe(board, i, col):
                # Place this queen in board[i][col]
                board[i][col] = 1

                if solve_nq_util(board, col + 1):
                    return True

                board[i][col] = 0

        return False

    def solve_nq():
        board = [[0 for _ in range(n)] for _ in range(n)]

        if not solve_nq_util(board, 0):
            return []

        return board

    return solve_nq()

# Example usage
N = 4
result = solve_n_queen(N)
print(result)
