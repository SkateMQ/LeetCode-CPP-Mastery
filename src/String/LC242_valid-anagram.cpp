/**
 * LeetCode 242: valid-anagram
 */
#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // 边界条件：长度不等绝对不是异位词
        if (s.size() != t.size()) {
            return false;
        }

        // 现代 C++ 实践：使用固定大小的 std::array 在栈上分配，避免堆内存开销与碎片化
        // 零初始化数组
        std::array<int, 26> char_counts{};

        // 利用 range-based for 或者普通下标，这里演示最高效的做法
        for (size_t i = 0; i < s.size(); ++i) {
            char_counts[s[i] - 'a']++;
            char_counts[t[i] - 'a']--;
        }

        // 现代 C++：使用 STL 算法和 Lambda 表达式来表达意图，而非手写底层循环
        return std::all_of(char_counts.begin(), char_counts.end(),
                           [](const int count) { return count == 0; });
    }
};

int main() {
    string s = "anagram";
    string t = "nagaram";
    Solution solution;
    cout << solution.isAnagram(s, t) << endl;
    return 0;
}