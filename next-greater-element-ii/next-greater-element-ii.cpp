class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        vector<int> res (nums.size(), -1);
        for (int i = 0; i < nums.size()*2; i++) {
            while(!s.empty() && nums[i%nums.size()] > nums[s.top()%nums.size()]) {
                res[s.top()%nums.size()] = nums[i%nums.size()];
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};