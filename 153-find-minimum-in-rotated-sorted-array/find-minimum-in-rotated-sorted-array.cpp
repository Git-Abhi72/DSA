class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int min1=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]<min1){
                min1=nums[i];
            }
        }
        sort(nums.begin(),nums.end());
          int lo = 0;
        int hi = n - 1;
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (nums[mid] == min1) {
                // Adjust the index according to the number of rotations
                return min1; //v.imp step
            } 
            else if (nums[mid] < min1) {
                lo = mid + 1;
            } 
            else {
                hi = mid - 1;
            }
        }
        
        
        return min1;


        

        
    }
};