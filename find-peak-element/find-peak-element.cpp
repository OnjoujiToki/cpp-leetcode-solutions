class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // 如果两端一端向右上升，一端向左上升，必定有一个山峰
        if (nums.size() == 1) return 0;
        int l = 1;
        int r = nums.size() - 2;
        while (l + 1 < r) {
            int mid = l + (r - l) /2;
            if (nums[mid] < nums[mid-1]) {
                r = mid;
            } else if (nums[mid] < nums[mid+1]) {
                l = mid;
            } else {
                return mid;
            }
        }
        // 判断没有寻找的部分有没有结论
        int curMax = nums[l] < nums[r]? r:l;
        if (nums[0] > nums[curMax]) {
            curMax = 0;
        } 
        if (nums[nums.size()-1] > nums[curMax]) {
            curMax = nums.size() -1;
        }
        return curMax;
    
    }
};