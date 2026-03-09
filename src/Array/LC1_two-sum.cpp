/**
 * LeetCode 1: two-sum
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size() - 1; ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

int main() {
    vector<int> nums{3, 2, 4};
    int target = 6;
    Solution solution;
    auto res = solution.twoSum(nums, target);
    cout << res[0] << ", " << res[1] << endl;
    return 0;
}