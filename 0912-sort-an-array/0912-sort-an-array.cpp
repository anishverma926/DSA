class Solution {
public:
    void merge(vector<int>& arr, int start, int mid, int end){
        vector<int> temp(end - start + 1);

        int left = start;
        int right = mid + 1;
        int index = 0;

        while(left <= mid && right <= end){
            if(arr[left] <= arr[right]){
                temp[index] = arr[left];
                index++;
                left++;
            }
            else{
                temp[index] = arr[right];
                index++;
                right++;
            }
        }

        while(left <= mid){
            temp[index] = arr[left];
            index++;
            left++;
        }

        while(right <= end){
            temp[index] = arr[right];
            index++;
            right++;
        }

        // add element into the arr 

        index = 0;
        while(start <= end){
            arr[start] = temp[index];
            start++;
            index++;
        }
    }

    void mergeSort(vector<int>& arr, int start, int end){
        if(start == end)
        return;

        int mid = start + (end - start) / 2;

        // left side
        mergeSort(arr, start, mid);;
        // right side
        mergeSort(arr, mid + 1, end);

        merge(arr, start, mid, end);
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        mergeSort(nums, 0, n-1);

        return nums;
    }
};