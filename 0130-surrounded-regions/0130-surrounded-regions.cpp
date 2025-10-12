class Solution {
public:
    int row[4] = {-1, 0, 0, 1};
    int col[4] = {0, -1, 1, 0};
    
    bool valid(int i, int j, int m, int n){
        return (i >= 0 && i < m) && (j >= 0 && j < n);
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        queue<pair<int, int>> q;

        // 1st row
        for(int j = 0; j < n; j++){
            if(board[0][j] == 'O'){
                q.push({0, j});
                board[0][j] = 'T';
            }
        }

        // 1st col
        for(int i = 1; i < m; i++){
            if(board[i][0] == 'O'){
                q.push({i, 0});
                board[i][0] = 'T';
            }
        }

        // last row
        for(int j = 1; j < n; j++){
            if(board[m-1][j] == 'O'){
                q.push({m-1, j});
                board[m-1][j] = 'T';
            }
        }

        // last col
        for(int i = 1; i < m-1; i++){
            if(board[i][n-1] == 'O'){
                q.push({i, n-1});
                board[i][n-1] = 'T';
            }
        }

        // check connected 'O' with boundaries 'O'
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            for(int k = 0; k < 4; k++){
                int ni = i + row[k];
                int nj = j + col[k];
                
                if(valid(ni, nj, m, n) && board[ni][nj] == 'O'){
                    board[ni][nj] = 'T';
                    q.push({ni, nj});
                }
            }
        }

        // convert all remaining 'O' to 'X'
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O')
                board[i][j] = 'X';
                else if(board[i][j] == 'T')
                board[i][j] = 'O';
            }
        }
    }
};