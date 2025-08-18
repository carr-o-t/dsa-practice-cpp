#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:

// APPROACH 1: Brute Force
// Time Complexity: O(n^2)
// Space Complexity: O(1)
    std::vector<int> twoSumBruteForce(std::vector<int>& nums, int target) {
        int n = nums.size();
        std::vector<int> result;
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1;  j < n; j++) {
                if (nums[i] + nums[j] == target) {
                   result.push_back(i);
                   result.push_back(j);

                   return result;
                }
            }
        }
        return result;
    }

    // APPROACH 2: UNORDERED MAP
    // Time Complexity: O(n)
    // Space Complexity: O(n)
     std::vector<int> twoSumMap(vector<int>& nums, int target) {
        unordered_map<int,int> mp;  
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i};  
            }
            mp[nums[i]] = i;  
        }
        return {};
    }
};