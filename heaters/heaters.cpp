class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        //对于每个房屋，要么用前面的暖气，要么用后面的，二者取近的，得到距离；
        //对于所有的房屋，选择最大的上述距离。
        int minR = -1;
        sort(heaters.begin(), heaters.end());
        for (int i = 0; i < houses.size(); i ++) {
            minR = max(findMin(heaters,houses[i]),minR);
        }

        return minR;
    }

    int findMin(vector<int>&heaters, int n) {
        int l = 0;
        int r = heaters.size()-1;
        while(l + 1 < r) {
            int mid = l + (r-l>>1);
            if (heaters[mid] <= n ) {
                l = mid;
            } else {
                r = mid;
            }
        }
        int leftRadius = abs(heaters[l] -  n);
        int rightRaidus = abs(heaters[r] - n);
        return min(leftRadius, rightRaidus);
    }
    
};