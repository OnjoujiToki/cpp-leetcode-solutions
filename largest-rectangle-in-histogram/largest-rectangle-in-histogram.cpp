class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        stack<int>s;
        vector<int> left(heights.size(),-1);
        vector<int> right(heights.size(),-1);
        for (int i = 0; i < heights.size(); i++) {
            while(!s.empty()&& heights[i]<heights[s.top()]){
               right[s.top()] = i;
               s.pop();
            }
            if (s.empty()) left[i] == -1;
            else left[i] = s.top();
            s.push(i);
        }
        for(int i = 0; i <heights.size();i++) {
            int rec = 0;
            if (left[i]== -1 && right[i] == -1) rec = heights.size()*heights[i]; 
            else if (left[i] == -1) rec = heights[i]*(right[i]);
            else if (right[i] == -1) rec = heights[i]*(heights.size()-left[i]-1);
            else rec = heights[i]*(right[i]-left[i]-1);
            ans = max(ans,rec);
        }

        return ans;
    }
};