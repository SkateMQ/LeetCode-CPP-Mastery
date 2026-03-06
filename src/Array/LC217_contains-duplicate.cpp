/**
 * LeetCode 217: contains-duplicate
 */
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> numSet;
        for (int num: nums) {
            numSet.insert(num);
        }
        if (numSet.size() < nums.size()) {
            return true;
        }
        return false;
    }
};

int main() {
    vector<int> nums{1, 2, 3, 4};
    Solution solution;
    cout << solution.containsDuplicate(nums) << endl;
    return 0;
}