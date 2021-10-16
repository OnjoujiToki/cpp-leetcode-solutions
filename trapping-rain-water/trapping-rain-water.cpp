class Solution {
public:
    int trap(vector<int>& height) {
        // find first element higher than it
        vector<int>left(height.size(),0), right(height.size(),0);
        for (int i = 1; i < height.size() -1; i++) {
            left[i] = max(left[i-1], height[i-1]);
        }
        for(int i = height.size() -2; i > 0; i--) {
            right[i] = max(right[i+1], height[i+1]);
        } 
        int maxAns = -1;
        int water = 0;
        for(int i =0; i < height.size(); i++) {
            int cur = min(left[i],right[i]);
            water += max(0, cur - height[i]);
        }
        return water;
    
        
    }

    
};