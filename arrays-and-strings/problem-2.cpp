/*
PROBLEM:
---------
Given an integer array nums and an integer k, return true if there are two distinct 
indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

Examples:
---------
1. Input: nums = [1,2,3,1], k = 3
   Output: true

2. Input: nums = [1,0,1,1], k = 1
   Output: true

3. Input: nums = [1,2,3,1,2,3], k = 2
   Output: false

Constraints:
------------
1 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
0 <= k <= 10^5
*/


/*
Brute Force Approach:
---------------------
Check every pair (i, j) where j > i and abs(i - j) <= k.
If nums[i] == nums[j], return true.

Time Complexity: O(n * k)  (for each index, check up to k elements ahead)
Space Complexity: O(1)
*/

#include <vector>

class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= i + k && j < n; j++) {
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }
        return false;
    }
};