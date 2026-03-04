/**
 * LeetCode 1417: reformat-the-string
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string reformat(string s) {
        if (s.empty()) return "";

        std::string letters, digits;
        // 工业级素养：已知内存上限，必须提前分配，避免堆内存反复分配
        letters.reserve(s.size());
        digits.reserve(s.size());

        // 语义化：使用标准库校验，而非魔术字符比较
        for (const char c : s) {
            if (std::isalpha(c)) {
                letters.push_back(c);
            } else {
                digits.push_back(c);
            }
        }

        // 边界安全：将 size_t 转换为带符号整数计算绝对值，杜绝溢出风险
        if (std::abs(static_cast<int>(letters.size()) - static_cast<int>(digits.size())) > 1) {
            return "";
        }

        // C++14/17 特性：Lambda 表达式，务必使用 const & 杜绝无意义的拷贝
        auto mergeChars = [](const std::string& longStr, const std::string& shortStr) -> std::string {
            std::string res;
            res.reserve(longStr.size() + shortStr.size());

            // 巧用布尔值转换：避免使用 flag 变量，代码更紧凑
            bool hasExtra = longStr.size() > shortStr.size();
            if (hasExtra) {
                res.push_back(longStr[0]);
            }

            for (size_t i = 0; i < shortStr.size(); ++i) {
                res.push_back(shortStr[i]);
                res.push_back(longStr[i + hasExtra]);
            }
            return res; // C++ 编译器会自动触发 NRVO (返回值优化)，无拷贝损耗
        };

        // 运用三元运算符简化逻辑流
        return letters.size() > digits.size() ? mergeChars(letters, digits) : mergeChars(digits, letters);
    }
};

int main() {
    string s1 = "a0b1c2";
    string s2 = "leetcode";
    Solution solution;
    cout << solution.reformat(s1) << endl;
    cout << solution.reformat(s2) << endl;
    return 0;
}