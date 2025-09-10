class Solution {
public:
    void solve(int idx, vector<int>& arr, vector<int> temp, int target, vector<vector<int>>& ans){
        int n = arr.size();

        if(target < 0)
        return;

        if(target == 0){
            ans.push_back(temp);
            return;
        }
        
        for(int i = idx; i < n; i++){
            if(i > idx && arr[i] == arr[i-1])
            continue;

            temp.push_back(arr[i]);
            solve(i+1, arr, temp, target - arr[i], ans);

            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> temp;

        solve(0, candidates, temp, target, ans);

        return ans;
    }
};