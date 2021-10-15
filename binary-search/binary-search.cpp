class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size()-1, target);
    }
    int binarySearch(vector<int>& nums, int start, int end, int target) {
        if (start > end) return -1;
        int mid = start + end >> 1;
        if (nums[mid] == target) {
            return mid;
        }  
        if (nums[mid] > target) {
            return binarySearch( nums, start, mid-1, target);
        } 
        return binarySearch(nums, mid+1, end, target);
    }
};