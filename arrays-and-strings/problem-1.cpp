#include <vector>
#include <set>
#include <map>
#include<iostream>
#include <unordered_set>    


// APPROACH-1: Create a set from the vector and compare sizes
// Time Complexity: O(n), where n is the number of elements in the vector
// Space Complexity: O(n), for storing unique elements in the set
class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::set<int> uniqueNums(nums.begin(), nums.end());
        return uniqueNums.size() != nums.size();
    }
};

// APPROACH-2: Use a map to track the frequency of each element
// Time Complexity: O(n), where n is the number of elements in the vector
// Space Complexity: O(n), for storing the frequency of each element in the map
// Note: This approach is not recommeded for this problem since we only need to check for duplicates, not their frequencies.
class Solution2 {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::map<int, int> freqMap;

        
        for(int i = 0; i<nums.size();i++){
            if(freqMap.contains(nums[i])){
                return true;
            } 
            freqMap.insert({nums[i], 1});
        }

        return false;
    }
};


// APPROACH-3: Use an unordered_set for O(1) average time complexity for insertions and lookups
// Time Complexity: O(n), where n is the number of elements in the vector
// Space Complexity: O(n), for storing unique elements in the unordered_set
class Solution3 {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> visited; // O(1) avg insert & lookup
        
        for (int num : nums) {
            if (!visited.insert(num).second) { 
                return true;
            }
        }
        
        return false;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {1, 2, 3, 1};
    bool result = solution.containsDuplicate(nums);
    
    if (result) {
        std::cout << "Contains duplicate elements." << std::endl;
    } else {
        std::cout << "No duplicate elements found." << std::endl;
    }

    return 0;
}