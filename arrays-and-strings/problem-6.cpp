#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> freqMap;

        for (int num : nums) {
            freqMap[num]++;
        }

        std::priority_queue<pair<int, int>> maxHeap;
        for (auto& pair : freqMap) {
            maxHeap.push({pair.second, pair.first});
        }

        std::vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return res;
    }
};



















