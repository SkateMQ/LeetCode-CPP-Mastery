/**
 * LeetCode 205: isomorphic-strings
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char, int> sDiffMap;
        unordered_map<char, int> tDiffMap;
        for (size_t i = 0; i < s.size(); ++i) {
            if (sDiffMap.find(s[i]) == sDiffMap.end() && tDiffMap.find(t[i]) == tDiffMap.end()) {
                sDiffMap[s[i]] = t[i] - s[i];
                tDiffMap[t[i]] = t[i] - s[i];
                continue;
            }
            if (sDiffMap.find(s[i]) == sDiffMap.end() || tDiffMap.find(t[i]) == tDiffMap.end()) {
                return false;
            }
            if (sDiffMap[s[i]] != t[i] - s[i]) {
                return false;
            }
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