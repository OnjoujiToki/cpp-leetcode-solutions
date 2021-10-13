class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0;
        int r = arr.size()-1;
        while(l + 1 < r) {
            int mid = l + (r-l>>1);
            if (arr[mid-1] <= arr[mid]) {
                l = mid;
            }
            else r = mid;
        }
        return l;
    }
};