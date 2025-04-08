class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
         int m = arr.size();
        int n = arr[0].size();
        for (int i = 0; i < m; i++) {
            int low = 0, high = n - 1;
             while (low <= high) {
                int mid = (low + high) / 2;
                if (arr[i][mid] == target) {
                  return true;
                } else if(arr[i][mid]<target) {
                    low = mid + 1;
                }
                else{
                    high=mid-1;
                }
            }
        }

          return false;
              
    }
};