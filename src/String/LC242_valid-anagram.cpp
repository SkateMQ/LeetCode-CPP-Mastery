/**
 * LeetCode 242: valid-anagram
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char, int> sCharaMap;
        unordered_map<char, int> tCharaMap;
        for (size_t i = 0; i < s.size(); ++i) {
            ++sCharaMap[s[i]];
            ++tCharaMap[t[i]];
        }
        if (sCharaMap.size() != tCharaMap.size()) {
            return false;
        }
        for (auto [chara, num]: sCharaMap) {
            if (tCharaMap[chara] != num) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    string s = "anagram";
    string t = "nagaram";
    Solution solution;
    cout << solution.isAnagram(s, t) << endl;
    return 0;
}