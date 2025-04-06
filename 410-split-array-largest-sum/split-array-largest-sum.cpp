class Solution {
public:
    int countSplits(vector<int>& arr, int mid, int n, int k) {
        int splits = 1;
        int currentSum = 0;
        for (int i = 0; i < n; ++i) {
            if (currentSum + arr[i] <= mid) {
                currentSum += arr[i];
            } else {
                splits += 1;
                currentSum = arr[i];
            }
        }
        return splits;
    }

    int splitArray(vector<int>& arr, int n, int k) {
        if (k > n) return -1;

        int maxElem = -1;
        int sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (maxElem < arr[i]) {
                maxElem = arr[i];
            }
            sum += arr[i];
        }

        int low = maxElem;
        int high = sum;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int splits = countSplits(arr, mid, n, k);
            if (splits > k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }

    int splitArray(vector<int>& nums, int k) {
        return splitArray(nums, nums.size(), k);
    }
};
