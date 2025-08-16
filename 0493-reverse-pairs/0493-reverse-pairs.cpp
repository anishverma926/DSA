class Solution {
public:
    void merge(vector<int> &arr, int start, int mid, int end) {
        vector<int> temp;
        int left = start;      // starting index of left half of arr
        int right = mid + 1;   // starting index of right half of arr

        while(left <= mid && right <= end) {
            if(arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                right++;
            }
        }

        // if elements on the left half are still left
        while(left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        // if elements on the right half are still left
        while(right <= end) {
            temp.push_back(arr[right]);
            right++;
        }

        // add element for temp to original array

        int index = 0;
        while(start <= end){
            arr[start] = temp[index];
            start++;
            index++;
        }

    }

    int countPairs(vector<int>& arr, int start, int mid, int end) {
        int left = start;
        int right = mid + 1;
        int count = 0;

        while(left <= mid){
            while(right <= end && (long long)arr[left] > 2ll * arr[right]){
                right++;
            }

            count += right - (mid + 1);  
            // [25, 40] & [12, 19] => 25 > 2*12, right++; arr[right] = 19
            // 25 < 2 * 19, left++
            // 40 < 2 * 19, so it will be also greater that 2 * 12
            // so count += right - (mid + 1) instead of (mid - left + 1)
            
            left++;
        }
        return count;
    }

    int mergeSort(vector<int> &arr, int start, int end) {
        int count = 0;

        if(start == end) 
        return 0;

        int mid = (start + end) / 2 ;

        count += mergeSort(arr, start, mid);  // left half
        count += mergeSort(arr, mid + 1, end); // right half
        count += countPairs(arr, start, mid, end);

        merge(arr, start, mid, end);
        return count;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n-1);
    }
};