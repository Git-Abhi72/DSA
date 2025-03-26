class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
         if (n == 1) {
            return 0;  // The only element is the peak
        }
        // Check if the first element is a peak
        if (nums[0] > nums[1]) {
            return 0;
        }
        // Check if the last element is a peak
        if (nums[n - 1] > nums[n - 2]) {
            return n - 1;
        }
        int lo = 1; //first ele can't be peak
        int hi = n - 2; //last ele can't be peak
        while (lo<=hi) {
            int mid = lo + (hi - lo) / 2;
            if ((nums[mid]>nums[mid + 1])&&(nums[mid]>nums[mid - 1])){
                return mid;
                
            } 
            else if(nums[mid-1]<nums[mid]){
                lo=mid+1;
            }
            else{
               hi=mid-1;
            }
    }
  return -1;
    } 
};
