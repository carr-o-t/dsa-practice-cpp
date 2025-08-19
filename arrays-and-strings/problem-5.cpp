/*
Problem: Group Anagrams

Given an array of strings strs, group the anagrams together.
You can return the answer in any order.

Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Explanation:
- "bat" has no other anagram.
- "nat" and "tan" are anagrams of each other.
- "ate", "eat", and "tea" are anagrams of each other.

Example 2:
Input: strs = [""]
Output: [[""]]

Example 3:
Input: strs = ["a"]
Output: [["a"]]

Constraints:
- 1 <= strs.length <= 10^4
- 0 <= strs[i].length <= 100
- strs[i] consists of lowercase English letters.
*/


#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:

/*
    APPROACH 1: Brute Force
    ---------------------------------------------
    1. For each string, sort the characters and use the sorted string as a key.
    2. Store the original strings in a map where the key is the sorted string.
    3. Return the values of the map as groups of anagrams.
    4. works for only lowercase English letters.

    Time Complexity: O(n * k log k), where n = number of strings, k = average length of strings
    Space Complexity: O(n * k) for storing the grouped anagrams
*/

    std::vector<std::vector<string>> groupAnagramsBruteForce(std::vector<string>& strs) {
        std::unordered_map<string, std::vector<string>> mp;
        std::vector<vector<string>> res;

        for (string word : strs) {
            string sortedStr = word;
            sort(sortedStr.begin(), sortedStr.end());  
            mp[sortedStr].push_back(word);             
        }

        for (const auto& pair : mp) {
            res.push_back(pair.second);
        }

        return res;
    }

    /*
    APPROACH 2: Frequency Map
    ---------------------------------------------
    1. For each string, count the frequency of each character.
    2. Use the frequency count as a key in a map.
    3. Store the original strings in a vector corresponding to each frequency key.
    4. Return the values of the map as groups of anagrams.
    5. This works for all characters, not just lowercase English letters.

    Time Complexity: O(n * k), where n = number of strings, k = average length of strings
    Space Complexity: O(n * k) for storing the grouped anagrams
    */

    std::vector<std::vector<string>> groupAnagrams(std::vector<string>& strs) {
        std::unordered_map<string, vector<string>> mp;

        for (string word : strs) {
            vector<int> freq(26, 0);
            for (char c : word) {
                freq[c - 'a']++;
            }

            string key;
            for (int count : freq) {
                key += to_string(count) + "#"; 
            }

            mp[key].push_back(word);
        }

        std::vector<vector<string>> res;
        for (auto& pair : mp) {
            res.push_back(pair.second);
        }

        return res;
    }
};
