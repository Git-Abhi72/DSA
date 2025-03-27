class Solution {
public:
    bool check(long long mid, vector<int>& piles, int h) {
        int n = piles.size();
        long long count = 0;  // Change count to long long to avoid overflow
        for (int i = 0; i < n; i++) {
            if (mid >= piles[i]) count++;
            else if (piles[i] % mid == 0) count += piles[i] / mid;
            else count += piles[i] / mid + 1;
        }
       if(count>h) return false;
       else return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        long long lo = 1;  // Start with speed 1
        long long max = INT_MIN;
        
        // Find the maximum pile size (max is now long long)
        for (int i = 0; i < n; i++) {
            if (piles[i] > max) {
                max = piles[i];
            }
        }
        
        long long hi = max;  // Set hi to the max pile size
        long long minspeed = 1;  // Initialize minspeed to 1
        
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            if (check(mid, piles, h)) {
                minspeed = mid;  // Found a possible valid speed
                hi = mid - 1;    // Try to find a smaller valid speed
            } else {
                lo = mid + 1;    // Increase speed
            }
        }
        
        return (int)minspeed;  // Cast minspeed back to int for return
    }
};
