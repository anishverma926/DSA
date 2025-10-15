class Solution {
public:
    bool dfs(vector<vector<int>>& adj, int node, int dest, vector<bool>& visited){
        visited[node] = true;

        if(node == dest)
        return true;

        bool isReacheable = false;
        for(int neigh : adj[node]){
            if(!visited[neigh]){
                isReacheable = isReacheable || dfs(adj, neigh, dest, visited);
            }
        }

        return isReacheable;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int N = numCourses;

        vector<vector<int>> adj(N);
        // vector<int> Indeg(N, 0);

        for(auto pre : prerequisites){
            int a = pre[0];
            int b = pre[1];

            adj[a].push_back(b);
            // Indeg[a]++;
        }

        int n = queries.size();
        vector<bool> ans(n);

        for(int i = 0; i < n; i++){
            int u = queries[i][0];
            int v = queries[i][1];

            vector<bool> visited(N, false);
            ans[i] = dfs(adj, u, v, visited);
        }

        return ans;
    }
};