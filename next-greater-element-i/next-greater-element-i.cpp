class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>m;
        vector<int>res (nums1.size(), -1);
        for (int i = 0; i < nums1.size(); i++) {
            m[nums1[i]] = i;
        }
        stack<int> s;
        for (int i = 0; i < nums2.size(); i++) {
            while(!s.empty() && nums2[i] > nums2[s.top()]) {
                if (m.find(nums2[s.top()]) != m.end()) {
                    res[m[nums2[s.top()]]] = nums2[i];
                }
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};