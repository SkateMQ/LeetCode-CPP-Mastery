/**
 * LeetCode 3428: maximum-and-minimum-sums-of-at-most-size-k-subsequences
 */
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int minMaxSums(vector<int>& nums, int k) {
        vector<int> sortedNums;
        int sums = 0;
        for (int num : nums) {
            sums += num * 2;
            auto item = sortedNums.begin();
            while (item != sortedNums.end()) {
                if (num <= *item) {
                    sortedNums.insert(item, num);
                    break;
                }
                ++item;
            }
            if (item == sortedNums.end()) {
                sortedNums.push_back(num);
            }
        }
        if (k == 1) {
            return sums;
        }
        for (int i = 1; i < k; ++i) {
            for (int j = 0; j < sortedNums.size() - i; ++j) {
                sums += sortedNums[j] + sortedNums[j + i];
            }
        }
        return sums;
    }
};

int main() {
    vector<int> testCase1{1, 2, 3};
    int k1 = 2;
    Solution solution;
    cout << solution.minMaxSums(testCase1, k1) << endl;
    return 0;
}