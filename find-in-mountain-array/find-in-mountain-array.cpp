/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int pos = findPeakPos(mountainArr, n);
        int leftMountain = binarySearchIncreasing(mountainArr, 0, pos,target);
        int rightMountain = binarySearchDecreasing(mountainArr, pos +1 ,n-1,target);
        if (leftMountain != -1) return leftMountain;
        if (rightMountain != -1) return rightMountain; 
        return -1;
    }
    int binarySearchIncreasing (MountainArray &mountainArr, int start, int end,int target ) {
        int l = start;
        int r = end;
        while(l + 1 < r) {
            int mid = l + (r - l)/2;
            if ( target <= mountainArr.get(mid)) {
                r = mid;
            } else {
                l = mid;
            }    
        }
        if (mountainArr.get(l) == target){
                return l;
            } else if (mountainArr.get(r) == target) {
                return r;
            }
            return -1; 
    }

    int binarySearchDecreasing(MountainArray &mountainArr, int start, int end,int target ) {
        int l = start;
        int r = end;
        while(l + 1 < r) {
            int mid = l + (r - l)/2;
            if ( target>= mountainArr.get(mid)) {
                r = mid;
            } else {
                l = mid;
            }    
        }
         if (mountainArr.get(l) == target){
                return l;
            } else if (mountainArr.get(r) == target) {
                return r;
            }
            return -1; 
    }
    int findPeakPos(MountainArray &mountainArr, int n ) {
        int l = 0;
        int r = n -1;
        while(l + 1 < r) {
            int mid = l + (r -l )/2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return mountainArr.get(l) > mountainArr.get(r) ? l:r;
    }
};