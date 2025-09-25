class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // step 1: create adjacency list & find InDegree
        int n = prerequisites.size();
        vector<vector<int>> adj(numCourses);
        vector<int> InDegree(numCourses, 0);

        for(auto& p : prerequisites){
            int a = p[0];
            int b = p[1];
            // b -> a
            adj[b].push_back(a);
            InDegree[a]++;
        }

        // step 2: whose InDegree = 0, push in queue;
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(!InDegree[i])
            q.push(i);
        }

        int count = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;

            for(int i = 0; i < adj[node].size(); i++){
                int neighbor = adj[node][i];
                InDegree[neighbor]--;
                
                if(!InDegree[neighbor]){
                    q.push(neighbor);
                }
            }
        }

        return count == numCourses;
    }
};