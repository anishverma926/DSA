class NumArray {
public:
    vector<int> segTree;
    int n;

    void buildSegTree(int i, int l, int r, vector<int>& nums){
        if(l == r){
            segTree[i] = nums[r];
            return;
        }

        int mid = (l + r) / 2;

        buildSegTree(2 * i + 1, l, mid, nums);
        buildSegTree(2 * i + 2, mid + 1, r, nums);

        segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
    }

    // Query the segment tree for sum in range [l, r]
    int query(int start, int end, int i, int l, int r){
        if(l > end || r < start)
        return 0;

        if(l >= start && r <= end)
        return segTree[i];

        int mid = (l + r) / 2;

        int left = query(start, end, 2 * i + 1, l, mid);
        int right = query(start, end, 2 * i + 2, mid + 1, r);

        return left  + right;
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        segTree.resize(4 * n);

        buildSegTree(0, 0, n-1, nums);
    }
    
    int sumRange(int left, int right) {
        return query(left, right, 0, 0, n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */