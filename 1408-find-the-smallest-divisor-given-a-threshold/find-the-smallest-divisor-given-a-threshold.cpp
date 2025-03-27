#include <cmath> 
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
         int max = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (nums[i] > max) {
                max = nums[i];
            }
        }
        int lo=1;  //smallest
        int hi=max; //largest
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=ceil((double)nums[i]/mid); //to find ceil            
            }
            if(sum<=threshold) hi=mid-1;
            else lo=mid+1;
          
    }
    return lo;
    }

};