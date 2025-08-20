class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int rowRook = -1;
        int colRook=-1;
        for(int i=0;i<8; i++){
            for(int j=0;j<8; j++){
                if(board[i][j] == 'R'){
                    rowRook = i;
                    colRook = j;
                }
            }
        }
        int cnt=0;
        for(int i = colRook; i<8; i++){
            if(board[rowRook][i] == 'p'){
                cnt++;
                break;
            }
            if(board[rowRook][i]=='B') break;
        }
        for(int i = colRook; i>=0; i--){
            if(board[rowRook][i] == 'p'){
                cnt++;
                break;
            }
            if(board[rowRook][i]=='B') break;
        }
        for(int i = rowRook; i<8; i++){
            if(board[i][colRook] == 'p'){
                cnt++;
                break;
            }
            if(board[i][colRook]=='B') break;
        }
        for(int i = rowRook; i>=0; i--){
            if(board[i][colRook] == 'p'){
                cnt++;
                break;
            }
            if(board[i][colRook]=='B') break;
        }
        return cnt;
    }
};