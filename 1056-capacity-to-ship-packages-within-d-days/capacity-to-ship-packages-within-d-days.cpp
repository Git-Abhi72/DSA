class Solution {
public:
    bool check(int mid, vector<int>& weights, int days) {
        int n = weights.size();
        int m = mid;
        int count = 1;
        for(int i = 0; i < n; i++) {
            if(m >= weights[i]) {  // corrected from 'weight[i]' to 'weights[i]'
                m -= weights[i];
            } else {
                count++; // for days
                m = mid;
                m -= weights[i];
            }
        }
        if(count > days) return false;
        else return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int max = INT_MIN;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            if(weights[i] > max) {
                max = weights[i]; // lo
            }
        }
        for(int i = 0; i < n; i++) {
            sum += weights[i];  // hi
        }
        int hi = sum; // ek din saara ship kr skte hai
        int lo = max;
        int mincap = sum; // abhi k liye rakh diya
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(check(mid, weights, days) == true) {
                mincap = mid;
                hi = mid - 1; 
            } else {
                lo = mid + 1; 
            }
        }
        return mincap;
    }
};
