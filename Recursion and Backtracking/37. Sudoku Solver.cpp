class Solution {
public:
    bool isvalid(vector<vector<char>> &board, int row, int col, char c){
        
        for(int i = 0; i<9; i++){
            
            if(board[i][col] == c){
                return false;
            }
            if(board[row][i] == c){
                return false;
            }
            
            if(board[((row/3)*3) + i/3][((col/3)*3) + i%3] == c){
                return false;
            }
        }
        return true; 
    }
    
    bool solve(vector<vector<char>> &board){
        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[0].size(); j++){
                if(board[i][j] == '.'){
                    for(char ci = '1'; ci<='9'; ci++){
                        
                        if(isvalid(board, i , j, ci)){
                            
                            board[i][j] = ci;
                            
                            if(solve(board) == true)
                                return true;
                            else
                             board[i][j] = '.';
                        }
                    } 
                return false;
                }
            }
        }
        return true;
    }
    
    
    
    void solveSudoku(vector<vector<char>>& board) {
            solve(board);         
    }
};
