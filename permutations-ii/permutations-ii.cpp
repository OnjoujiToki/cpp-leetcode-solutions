class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<bool> visited;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        visited = vector<bool> (nums.size(),false);
        dfs(nums);
        return res;
    }
    void dfs(vector<int>& nums)  {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        
        for (int i = 0;i<nums.size(); i++ ){
            if (i>0 && nums[i-1] == nums[i] && visited[i-1] == false) continue;
            if (visited[i] == false) {
                path.push_back(nums[i]);
                visited[i] = true;
                dfs(nums);
                visited[i] = false;
                path.pop_back();
            }
        }

    }
};