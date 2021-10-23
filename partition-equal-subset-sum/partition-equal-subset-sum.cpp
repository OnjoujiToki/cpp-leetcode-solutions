class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // 每次加一个数字，看看能不能生成一个新的和，如果是新的和就退出来
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum%2 != 0) return false;
        sum /= 2;
        unordered_set<int> s{{0}};
        for (int i = 0; i < nums.size(); i ++) {
            vector<int> tmp;
            for (auto& x: s) {
                if (x + nums[i] == sum) {
                    return true;
                }
                tmp.push_back(x+nums[i]);
            }
            for (auto& t : tmp) 
                s.insert(t);
        }
        return false;
    }
};