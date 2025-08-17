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
#include<unordered_map>

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


/*
Optimized Approach (HashMap to track last seen indices):
--------------------------------------------------------
Idea:
- Use an unordered_map to store the last index of each number.
- For every element nums[i]:
    - If nums[i] has been seen before at index j:
        - Check if (i - j) <= k
        - If true → return true (duplicate within range k)
    - Update nums[i]'s latest index to i

Time Complexity:
- O(n), since each lookup and insertion in unordered_map is O(1) on average.

Space Complexity:
- O(n), for storing indices of elements in the map.

Example Walkthrough:
nums = [1, 2, 3, 1], k = 3
- i = 0 → store {1:0}
- i = 1 → store {2:1}
- i = 2 → store {3:2}
- i = 3 → nums[3]=1 already seen at index 0 → diff=3 → valid → return true
*/

class Solution2 {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> mp; 
    for(int i = 0; i < nums.size(); i++) {
        if(mp.count(nums[i]) && i - mp[nums[i]] <= k) return true;
        mp[nums[i]] = i;
    }
    return false;
}
};