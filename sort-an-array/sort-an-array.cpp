class Solution {
public:
    void qs(vector<int>& nums, int l , int r) {
        if (l>=r ) return;
        int i = l -1, j =r +1;
        int x = nums[l+r>>1];
        while (i < j) {
            do i++; while (nums[i] < x);
            do j--; while(nums[j] > x);
            if (i<j) swap(nums[i], nums[j]);
        }
        
        qs(nums, l ,j);
        qs(nums, j+1,r);
    }
    vector<int> sortArray(vector<int>& nums) {
        qs(nums,0,nums.size()-1);
        return nums;
    }
};