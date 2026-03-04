/**
 * LeetCode 1417: reformat-the-string
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string reformat(string s) {
        if (s.empty()) {
            return "";
        }
        vector<char> letters;
        vector<char> digits;
        for (char chara: s) {
            if (chara >= 'a' && chara <= 'z') {
                letters.push_back(chara);
                continue;
            }
            digits.push_back(chara);
        }
        if (letters.size() > digits.size() + 1) {
            return "";
        }
        if (digits.size() > letters.size() + 1) {
            return "";
        }
        auto insertChara = [](vector<char> longVec, vector<char> shortVec) ->string {
            string res;
            int flag = 0;
            if (longVec.size() > shortVec.size()) {
                res.push_back(longVec[0]);
                flag = 1;
            }
            for (size_t i = 0; i < shortVec.size(); ++i) {
                res.push_back(shortVec[i]);
                res.push_back(longVec[i + flag]);
            }
            return res;
        };
        if (letters.size() > digits.size()) {
            return insertChara(letters, digits);
        }
        return insertChara(digits, letters);
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