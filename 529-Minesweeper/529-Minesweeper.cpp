// Last updated: 12/8/2025, 11:28:26 PM
class Solution {
private:
    int dir[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
    
    int countMines(const vector<vector<char>>& board, int x, int y) {
        int mines = 0;
        for (int i = 0; i < 8; ++i) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (0 <= nx && nx < board.size() && 0 <= ny && ny < board[0].size()) {
                if (board[nx][ny] == 'M') {
                    mines++;
                }
            }
        }
        return mines;
    }

    void dfs(vector<vector<char>>& board, int x, int y) {
        // every cell check nine directions, count mines, and change
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] == 'B') return;
        if (board[x][y] == 'M') return;

        int mines = countMines(board, x, y);
        if (mines > 0) {
            // if mines near this cell, modify this cell and stop exploring
            board[x][y] = mines + '0';
            return;
        } else {
            // if no mine near, modify this cell and continue exploring
            board[x][y] = 'B';
            for (int i = 0; i < 8; ++i) {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                dfs(board, nx, ny);
            }        
        }
    }

public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        dfs(board, click[0], click[1]);
        return board;
    }
};