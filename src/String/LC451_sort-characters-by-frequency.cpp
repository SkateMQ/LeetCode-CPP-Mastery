/**
 * LeetCode 451: sort-characters-by-frequency
 */
#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        if (s.empty()) {
            return "";
        }
        unordered_map<char, int> charNumMap;
        for (char chara: s) {
            ++charNumMap[chara];
        }
        vector<string> buckets(s.size() + 1, "");
        for (auto [chara, num]: charNumMap) {
            buckets[num].append(num, chara);
        }
        string res;
        res.reserve(s.size());
        for (size_t i = s.size(); i > 0; --i) {
            res.append(buckets[i]);
        }
        return res;
    }
};

int main() {
    string s = "Aabb";
    Solution solution;
    cout << solution.frequencySort(s) << endl;
    return 0;
}