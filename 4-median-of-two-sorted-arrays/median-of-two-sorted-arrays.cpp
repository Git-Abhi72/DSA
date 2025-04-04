class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3;
        double n1 = nums1.size();
        double n2 = nums2.size();
        int i = 0, j = 0, k = 0;
        
        // Resize nums3 to hold all elements from nums1 and nums2
        nums3.resize(n1 + n2); 
        
        while (i < n1 && j < n2) {
            if (nums1[i] > nums2[j]) {
                nums3[k] = nums2[j];
                j++; k++;
            } else {
                nums3[k] = nums1[i];
                i++; k++;
            }
        }

        // If there are remaining elements in nums1
        if (i == n1) {
            while (j < n2) {
                nums3[k] = nums2[j];
                k++; j++;
            }
        }

        // If there are remaining elements in nums2
        if (j == n2) {
            while (i < n1) {
                nums3[k] = nums1[i];
                k++; i++;  // Corrected the increment from j to i
            }
        }

        double n = n1 + n2;
        
        // Fix: Cast n to an integer for the modulus operation
        if ((int)n % 2 == 0) {  // Cast n to int
            return (double)(nums3[(int)n / 2] + nums3[(int)n / 2 - 1]) / 2.0;
        } else {
            return nums3[(int)n / 2];  // Cast n to int
        }
    }
};

