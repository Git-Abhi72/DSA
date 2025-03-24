class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int count = 0;
        int b_idx = -1;
        int k = 0; // Number of rotations
        
        // Find the number of rotations and the index where the array is rotated
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) {  // Check where the order breaks
                count++;
                b_idx = i;  // Record the index where the break happens
            }
        }
        
        if (count == 1) k = b_idx + 1;  // Number of rotations is b_idx + 1
        
        // Sort the array to simplify binary search
        
        sort(nums.begin(),nums.end());
        
        // Use binary search to find the target in the sorted array
        int lo = 0;
        int hi = n - 1;
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (nums[mid] == target) {
                // Adjust the index according to the number of rotations
                return (mid + k) % n;
            } 
            else if (nums[mid] < target) {
                lo = mid + 1;
            } 
            else {
                hi = mid - 1;
            }
        }
        
        // If not found, return -1
        return -1;
    }
};
