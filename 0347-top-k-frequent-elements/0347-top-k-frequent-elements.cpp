class Solution {
public:
    typedef pair<int, int> p;

    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;

        for(int num : nums)
        mp[num]++;

        priority_queue<p, vector<p>, greater<p>> pq;

        for(auto it : mp){
            pq.push({it.second, it.first});

            if(pq.size() > k){
                pq.pop();
            }
        }  

        vector<int> ans; // stroring the answer

        while(!pq.empty()){
            int element = pq.top().second;
            pq.pop();

            ans.push_back(element);
        }

        return ans;
    }
};