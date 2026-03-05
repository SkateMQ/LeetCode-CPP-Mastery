/**
 * LeetCode 205: isomorphic-strings
 */
#include <iostream>
#include <array>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        // 优先使用 std::array，栈上分配，内存绝对安全且自动释放
        // 零初始化数组，避免野指针和脏数据
        std::array<int, 256> s_last_seen_idx{};
        std::array<int, 256> t_last_seen_idx{};

        for (size_t i = 0; i < s.size(); ++i) {
            // 边界安全：将 char 转换为 unsigned char，防止负数索引导致越界崩溃
            auto sc = static_cast<unsigned char>(s[i]);
            auto tc = static_cast<unsigned char>(t[i]);

            // 如果两个字符上次出现的索引位置不同，说明映射已被破坏
            if (s_last_seen_idx[sc] != t_last_seen_idx[tc]) {
                return false;
            }

            // 更新字符最后一次出现的索引（+1是为了避开初始化的0）
            s_last_seen_idx[sc] = i + 1;
            t_last_seen_idx[tc] = i + 1;
        }

        return true;
    }
};

int main() {
    string s1 = "badc";
    string t1 = "baba";
    Solution solution;
    cout << solution.isIsomorphic(s1, t1) << endl;
    return 0;
}