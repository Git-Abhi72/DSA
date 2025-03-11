class Solution {
public:
    int findfirst(vector<int>& arr, int x) {
        int n = arr.size();
        int lo = 0;
        int hi = n - 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (arr[mid] == x) {
                if (mid == 0 || arr[mid - 1] != x) {
                    return mid;  // Found first occurrence
                }
                hi = mid - 1; // Continue search on the left
            } 
            else if (arr[mid] < x) {
                lo = mid + 1;
            } 
            else {
                hi = mid - 1;
            }
        }

        return -1; // Not found
    }

    int findlast(vector<int>& arr, int x) {
        int n = arr.size();
        int lo = 0;
        int hi = n - 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (arr[mid] == x) {
                if (mid == n - 1 || arr[mid + 1] != x) {
                    return mid;  // Found last occurrence
                }
                lo = mid + 1; // Continue search on the right
            } 
            else if (arr[mid] < x) {
                lo = mid + 1;
            } 
            else {
                hi = mid - 1;
            }
        }

        return -1; // Not found
    }

    vector<int> searchRange(vector<int>& arr, int x) {
        int n = arr.size();
        int first = findfirst(arr, x);
        int last = findlast(arr, x);
        return {first, last};
    }
};
