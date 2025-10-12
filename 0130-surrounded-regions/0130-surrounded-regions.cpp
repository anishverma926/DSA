class Solution {
public:

    int row[4] = {-1,1,0,0};
    int col[4] = {0,0,1,-1};
    
    bool valid(int i, int j, int n, int m){
        return (i>=0 && i<n) && (j>=0 && j<m);
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        queue<pair<int, int>>q;
        // 1st row
        for(int j=0;j<m;j++){
            if(board[0][j] == 'O'){
               q.push({0,j});
               board[0][j] = 'T';
            }
        }
        // 1st col
        for(int i=0;i<n;i++){
            if(board[i][0] == 'O'){
               q.push({i,0});
               board[i][0] = 'T';
            }
        }
        // last row
        for(int j=1;j<m;j++){
            if(board[n-1][j] == 'O'){
               q.push({n-1,j});
               board[n-1][j] = 'T';
            }
        }
        // last col
        for(int i=1;i<n-1;i++){
            if(board[i][m-1] == 'O'){
               q.push({i,m-1});
               board[i][m-1] = 'T';
            }
        }

        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            for(int k=0;k<4;k++){
                int new_i = i+row[k];
                int new_j = j+col[k];
                
                if(valid(new_i, new_j, n,m) && board[new_i][new_j] == 'O'){
                    board[new_i][new_j] = 'T';
                    q.push({new_i, new_j});
                }
            }
        }
        
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(board[i][j] == 'O')
            board[i][j] = 'X';
            else if(board[i][j] == 'T')
            board[i][j] = 'O';
        }

    }
};