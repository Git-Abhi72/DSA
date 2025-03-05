class Solution {
public:
    int searchInsert(vector<int>& arr, int x) {
        int n=arr.size();
        int lo=0;
        int hi=n-1;
          while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] == x) {
                return mid;
            
            }
            else if (arr[mid] < x) {
                lo = mid + 1;
            } 
            else {
                hi = mid - 1;
            }
        }

       if(arr[0]<x){
        return hi+1;
       }
       else{
        return 0;
       }
        
    }
};