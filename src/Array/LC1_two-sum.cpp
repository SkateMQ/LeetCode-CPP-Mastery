/**
 * LeetCode 1: two-sum
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // [SEC-02] 边界防御：少于两个元素直接返回（或抛出异常）
        if (nums.size() < 2) {
            return {}; // 真实生产环境中可能会 throw std::invalid_argument
        }

        // [MOD-03] 使用哈希表降低时间复杂度至 O(N)
        std::unordered_map<int, int> num_map;

        // [PERF-02] 预分配内存，防止哈希表动态扩容引起的内存重分配开销
        num_map.reserve(nums.size());

        // [SEC-01] 避免有符号与无符号比对，使用 auto 或静态转换
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            int complement = target - nums[i];

            // 现代 C++ 风格：使用 auto 减少冗余类型声明
            auto it = num_map.find(complement);

            if (it != num_map.end()) {
                // 命中目标，立刻返回。避免内存泄漏及越界风险。
                return {it->second, i};
            }

            // 存入当前值及索引
            num_map[nums[i]] = i;
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