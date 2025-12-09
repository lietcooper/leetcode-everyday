# Last updated: 12/8/2025, 11:29:14 PM
class TicTacToe:

    def __init__(self, n: int):
        self.board = [[0] * n for _ in range(n)]
        self.isEnd = False

    def move(self, row: int, col: int, user: int) -> int:
        if self.isEnd:
            return 0
        self.board[row][col] = user
        n = len(self.board)

        # check if is end, DFS
        # row: left, right
        # col: up, down
        # diagonal: left-up - right-down, left-down - right-up
        def dfs(x, y, user, dir):
            if (x < 0 or x >= n or y < 0 or y >= n or self.board[x][y] != user):
                return 0

            cur = 1
            nx = x + dir[0]
            ny = y + dir[1]
            cur += dfs(nx, ny, user, dir)
            return cur


        r = dfs(row, col, user, [0, -1]) + dfs(row, col, user, [0, 1]) - 1
        c = dfs(row, col, user, [-1, 0]) + dfs(row, col, user, [1, 0]) - 1
        left_up = dfs(row, col, user, [-1, -1]) + dfs(row, col, user, [1, 1]) - 1
        left_down = dfs(row, col, user, [1, -1]) + dfs(row, col, user, [-1, 1]) - 1
        if (r == n or c == n or left_up == n or left_down == n):
            self.isEnd = True
            return user
        else:
            return 0



# Your TicTacToe object will be instantiated and called as such:
# obj = TicTacToe(n)
# param_1 = obj.move(row,col,player)