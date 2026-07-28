class Solution {
    // bool check(int x, int y, vector<vector<char>> & board, char n) {
    //     for(int i = 0; i < 9; i++) {
    //         if(i != x && board[i][y] == n) return false; 
    //     }
    //     for(int i = 0; i < 9; i++) {
    //         if(i != y && board[x][i] == n) return false; 
    //     }
        
    //     for(int i = (x/3) * 3; i < (x/3+1) * 3; i++) 
    //         for(int j = (y/3) * 3; j < (y/3 + 1) * 3; j++) 
    //             if(i != x && j != y && board[i][j] == n) return false;
    
    //     return true;
    // }
    
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // for(int i = 0; i < 9; i++) {
        //     for(int j= 0; j < 9; j++) {
        //         if(board[i][j] != '.') {
        //             cout<<i<<" "<<j<<endl;
        //             if(!check(i, j, board, board[i][j])) return false;
        //         }
        //     }
        // }
        // return true;

        vector<int> r(9, 0), c(9, 0), b(9, 0);

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;
                int v = 1 << (board[i][j] - '1');
                if((r[i] & v) != 0 || (c[j] & v) != 0 || (b[i/3*3 + j/3] & v) != 0) return false;
                r[i] |= v;
                c[j] |= v;
                b[i/3*3 + j/3] |= v;
            }
        }
        return true;
    }
};
