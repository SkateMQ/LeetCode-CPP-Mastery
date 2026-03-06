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
        // [Rule ES.2] 边界防御：长度小于 2 绝不可能有重复
        // 使用 C++20 [[unlikely]] 属性优化 CPU 分支预测 (C++14/17 可用 __builtin_expect)
        if (nums.size() < 2) {
            return false;
        }

        std::unordered_set<int> numSet;
        // [Rule PER.14] 预分配内存，避免 Rehashing 带来的开销
        numSet.reserve(nums.size());

        // [Rule ES.71] 现代 C++ 范围 for 循环，使用 const auto& 展现良好工程素养
        for (const auto& num : nums) {
            // [Rule PER.11] std::unordered_set::insert 返回 std::pair<iterator, bool>
            // 借助结构化绑定(C++17)或直接访问 .second 进行 Early Exit
            if (!numSet.insert(num).second) {
                return true; // 发现重复，立即熔断
            }
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