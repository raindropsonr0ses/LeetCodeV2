#include <unordered_set>
#include <vector>
// The best DS to leverage is Hashset, in C++ unordered set is the closest to it
// both look-ups and insertions run in expected \U0001d442(1) time
class Solution {
public:
    
    bool containsDuplicate(const std::vector<int>& nums) {
        std::unordered_set<int> encountered;        // stores the distinct values we have visited so far
        for (int value : nums) {             // visit each element exactly once
            if (encountered.count(value))   // unordered_set::count is O(1) average-time lookup
                return true;                // a duplicate is found
            encountered.insert(value);      // if we encounter a number for the first time, we insert it in the unordered set
        }
        return false;                        // scanned entire array without repeats
    }
}; 

// Overall time and space complexity is O(n)