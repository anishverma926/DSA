class Solution {
public:
    int row[4] = {-1, 0, 0, 1};
    int col[4] = {0, -1, 1, 0};
    
    bool valid(int i, int j, int m, int n){
        return (i >= 0 && i < m) && (j >= 0 && j < n);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool> (n, false));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    count++;

                    q.push({i, j});
                    visited[i][j] = true;

                    while(!q.empty()){
                        int new_i = q.front().first;
                        int new_j = q.front().second;
                        q.pop();

                        for(int k = 0; k < 4; k++){
                            int ni = new_i + row[k];
                            int nj = new_j + col[k];

                            if(valid(ni, nj, m, n) && (grid[ni][nj] == '1') && !visited[ni][nj]){
                                visited[ni][nj] = true;
                                q.push({ni, nj});
                            }
                        }
                    }
                }
            }
        }

        return count;
    }
};