class Solution {
public:
    int row[4] = {-1, 0, 0, 1};
    int col[4] = {0, -1, 1, 0};
    
    bool valid(int i, int j, int m, int n){
        return (i >= 0 && i < m) && (j >= 0 && j < n);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2)
                q.push({i, j});
            }
        }

        int timer = 0;

        while(!q.empty()){
            bool unfresh = false;
            int size = q.size();

            while(size--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                for(int k = 0; k < 4; k++){
                    int ni = i + row[k];
                    int nj = j + col[k];

                    if(valid(ni, nj, m, n) && (grid[ni][nj] == 1)){
                        q.push({ni, nj});
                        grid[ni][nj] = 2;
                        unfresh = true;
                    }
                }
            }
            
            if(unfresh)
            timer++;
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1)
                return -1;
            }
        }

        return timer;
    }
};