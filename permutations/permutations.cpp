class Solution {
public:
    vector<bool> visited;
    vector<int> path;
    vector<vector<int>>res;
    vector<vector<int>> permute(vector<int>& nums) {
        visited = vector<bool>(nums.size(),false);
        dfs(nums);
        return res;
    }
    void dfs(vector<int>& nums) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i =0; i < nums.size(); i++) {
            if (visited[i] == false) {
                visited[i] = true;
                path.push_back(nums[i]);
                dfs(nums);
                visited[i] = false;
                path.pop_back();
            }
        }
    }
};