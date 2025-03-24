class Solution {
public:
    bool search(vector<int>& nums, int target) {  
        int n =nums.size();      
        sort(nums.begin(),nums.end());
        
        // Use binary search to find the target in the sorted array
        int lo = 0;
        int hi = n - 1;
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (nums[mid] == target) {
                // Adjust the index according to the number of rotations
                return true; //v.imp step
            } 
            else if (nums[mid] < target) {
                lo = mid + 1;
            } 
            else {
                hi = mid - 1;
            }
        }
        
        
        return false;
        
    }
};