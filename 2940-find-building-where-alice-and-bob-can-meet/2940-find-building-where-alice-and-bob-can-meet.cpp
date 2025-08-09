class Solution {
public:
    void buildSegTree(int i, int l, int r, vector<int>& segTree, vector<int>& arr){
        if(l == r){
            segTree[i] = l; // stores index
            return;
        }

        int mid = l + (r - l) / 2;

        buildSegTree(2*i+1, l, mid, segTree, arr);
        buildSegTree(2*i+2, mid + 1, r, segTree, arr);

        // store the index of maximum element
        int leftMaxIdx = segTree[2*i+1];
        int rightMaxIdx = segTree[2*i+2];

        if(arr[leftMaxIdx] >= arr[rightMaxIdx]){
            segTree[i] = leftMaxIdx;
        }
        else{
            segTree[i] = rightMaxIdx;
        }
    }

    int query(int start, int end, int i, int l, int r, vector<int>& segTree, vector<int>& arr){
        if(l > end || r < start){
            return -1;
        }

        if(l >= start && r <= end){
            return segTree[i];
        }

        int mid = l + (r - l) / 2;
        int left = query(start, end, 2*i+1, l , mid, segTree, arr);
        int right = query(start, end, 2*i+2, mid + 1, r, segTree, arr);

        if(left == -1)
        return right;

        if(right == -1)
        return left;

        if(arr[left] >= arr[right]){
            return left;
        }
        else{
            return right;
        }
    }

    // This returns the index of maximum element in the range of [start, end] in that array
    int RMIQ(int start, int end, vector<int>& segTree, vector<int>& arr){
        int n = arr.size();
        return query(start, end, 0, 0, n-1, segTree, arr);
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        
        vector<int> segTree(4 * n);
        buildSegTree(0, 0, n-1, segTree, heights);

        vector<int> ans;

        for(auto query : queries){
            int max_idx = max(query[0], query[1]);
            int min_idx = min(query[0], query[1]);

            if(max_idx == min_idx){
                ans.push_back(max_idx);
                continue;
            }
            else if(heights[max_idx] > heights[min_idx]){
                ans.push_back(max_idx);
                continue;
            }

            int l = max_idx + 1;
            int r = n - 1;
            int ans_idx = INT_MAX;

            while(l <= r){
                int mid = l + (r - l) / 2;
                int idx = RMIQ(l, mid, segTree, heights);

                if(heights[idx] > max(heights[max_idx], heights[min_idx])){
                    ans_idx = min(ans_idx, idx);
                    r = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }

            if(ans_idx == INT_MAX)
            ans.push_back(-1);
            else
            ans.push_back(ans_idx);
        }
        
        return ans;
    }
};