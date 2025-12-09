// Last updated: 12/8/2025, 11:29:13 PM
class TicTacToe {
public:
    vector<int> rows;
    vector<int> cols;
    int diag = 0;
    int adiag = 0;
    int n;
    TicTacToe(int n) {
        rows.resize(n);
        cols.resize(n);
        this->n = n;
    }

    int move(int row, int col, int player) {
        int pl = player == 1 ? 1 : -1;
        rows[row] += pl;
        cols[col] += pl;
        if(row==col){
            diag+=pl;
        }
        if(row == (n-1-col)){
            adiag +=pl;
        }
        if(rows[row]*pl == n || cols[col]*pl == n || diag*pl == n || adiag*pl ==n){
            return player;
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */