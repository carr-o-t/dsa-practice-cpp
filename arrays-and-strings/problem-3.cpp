/*
PROBLEM 242: Valid Anagram
--------------------------
Given two strings s and t, return true if t is an anagram of s, 
and false otherwise.

An anagram is a word formed by rearranging the letters of another 
word, using all the original letters exactly once.

Examples:
---------
1. Input: s = "anagram", t = "nagaram"
   Output: true

2. Input: s = "rat", t = "car"
   Output: false

Constraints:
------------
1 <= s.length, t.length <= 5 * 10^4
s and t consist of lowercase English letters.
*/

/*
APPROACH 1: Sorting
-------------------
1. Sort both strings s and t.
2. If they are equal after sorting → return true, else false.

Time Complexity:
    O(n log n)   (due to sorting both strings)
Space Complexity:
    O(1) or O(log n) depending on sorting algorithm implementation
*/

#include<algorithm>
#include<string>
#include <iostream>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());

        return s == t;
    }


    bool isUnicodeAnagram(std::wstring s, std::wstring t) {
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());

        return s == t;
    }


};

int main(){
    // Example usage
    Solution solution;
    std::string s = "anagram";
    std::string t = "nagaram";

    bool result = solution.isAnagram(s, t);
    std::cout << (result ? "true" : "false") << std::endl; // Output: true

    // Testing Unicode strings
    // Note: std::wstring is used for wide characters (Unicode)
    // Ensure your compiler supports wide character literals
    std::wstring s1 = L"😊🙃🙂";
    std::wstring t1 = L"🙂😊🙃";

    std::wstring s2 = L"你好";
    std::wstring t2 = L"您好";

    std::wstring s3 = L"café";
    std::wstring t3 = L"face";

    bool result1 = solution.isUnicodeAnagram(s1, t1);
    bool result2 = solution.isUnicodeAnagram(s2, t2);
    bool result3 = solution.isUnicodeAnagram(s3, t3);
    // std::cout << (result ? L"true" : L"false") << std::endl; // Output: true
    std::cout << (result1 ? "true" : "false") << std::endl; // Output: true
    std::cout << (result2 ? "true" : "false") << std::endl; // Output: true
    std::cout << (result3 ? "true" : "false") << std::endl; // Output: true

    return 0;
}