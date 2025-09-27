class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int>color(V, -1);
        queue<int> q;

        int col = 0;
        
        for(int i = 0; i < V; i++){
            if(color[i] == -1){
                q.push(i);
                color[i] = 0;
                
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    
                    for(int j = 0; j < graph[node].size(); j++){
                        int neigh = graph[node][j];

                        if(color[neigh] == -1){
                           color[neigh] = 1 - color[node];
                           q.push(neigh);
                        }
                        else if(color[neigh] == color[node])
                        return false;
                    }
                }
            }
        }

        return true;
    }
};