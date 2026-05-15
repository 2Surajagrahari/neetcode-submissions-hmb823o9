class Solution {
public:
    bool isSafe(vector<string> &board,int row, int col, int n){
        //horizontal
        for(int j=0;j<n;j++){
            if(board[row][j] == 'Q'){
                return false;
            }
        }

        //vertical
        for(int i=0;i<n;i++){
            if(board[i][col] == 'Q'){
                return false;
            }
        }

        //leftdai
        for(int i=row,j=col;j>=0&&i>=0;i--,j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        //rightdiag
          for(int i=row,j=col;j<n&&i>=0;i--,j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }

        return true;
    }
    void nQueens(vector<string> &board, vector<vector<string>> &ans, int n, int row){
        if(row == n){
            ans.push_back(board);
            return;
        }
        for(int j=0;j<n;j++){
            if(isSafe(board,row,j,n)){
                board[row][j] = 'Q';
                nQueens(board,ans,n,row+1);
                board[row][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        vector<vector<string>> ans;
        nQueens(board,ans,n,0);
        return ans;
    }
};