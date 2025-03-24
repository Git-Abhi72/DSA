class Solution {
public:
    int first(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0;
        int hi = n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                // Check if this is the first occurrence or the last element
                if (mid == 0 || nums[mid - 1] != target) {
                    return mid;  // This is the first occurrence of the element
                } else {
                    hi = mid - 1;  // Continue searching on the left side
                }
            } else if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return -1;  // Target not found
    }
   
    int second(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0;
        int hi = n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                // Check if this is the second occurrence or the first element
                if (mid == n - 1 || nums[mid + 1] != target) {
                    return mid;  // This is the last occurrence of the element
                } else {
                    lo = mid + 1;  // Continue searching on the right side
                }
            } else if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return -1;  // Target not found
    }

    int singleNonDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int firstoccur = first(nums, nums[i]);
            int lastoccur = second(nums, nums[i]);
            // If the first and last occurrences are the same, it's the unique element
            if (firstoccur == lastoccur) {
                return nums[i];
            }
        }
        return -1;  // If no unique element is found, return -1 (shouldn't happen in the problem constraints)
    }
};
