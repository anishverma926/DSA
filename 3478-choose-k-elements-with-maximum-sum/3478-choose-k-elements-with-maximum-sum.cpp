class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();   

        //T.C : O(n + nlogn + nlogk)
        //S.C : O(n + k)
        vector<vector<int>> vec(n); //vec[i] = {nums1[i], i, nums2[i]}
        for(int i = 0; i < n; i++) { //O(n)
            vec[i] = {nums1[i], i, nums2[i]};
        }

        sort(begin(vec), end(vec)); //O(nlogn)

        vector<long long> ans(n, 0);
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0;

        for(int i = 0; i < n; i++) { //O(nlogk)
            if(i > 0 && vec[i-1][0] == vec[i][0]) {
                long long res = ans[vec[i-1][1]]; 
                ans[vec[i][1]] = res;
            } else {
                ans[vec[i][1]] = sum;
            }

            pq.push(vec[i][2]);
            sum += vec[i][2];
            if(pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
        }

        return ans;

    }
};