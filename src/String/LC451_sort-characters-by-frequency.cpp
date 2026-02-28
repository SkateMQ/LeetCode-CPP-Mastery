/**
 * LeetCode 451: sort-characters-by-frequency
 */
#include <iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        map<char, int> charNumMap;
        for (char chara: s) {
            if (charNumMap.find(chara) == charNumMap.end()) {
                charNumMap.insert({chara, 1});
                continue;
            }
            charNumMap.find(chara)->second++;
        }
        list<char> freqOrder; // not sure if it's the best structure
        auto constructList = [&charNumMap, &freqOrder](char chara, int val) {
            if (freqOrder.empty()) {
                freqOrder.emplace_back(chara);
                return;
            }
            auto item = freqOrder.begin();
            while (item != freqOrder.end()) {
                if (val > charNumMap.find(*item)->second) { // don't know how to get value form the iterator of the list, I google it
                    freqOrder.insert(item, chara);
                    break;
                }
                item.operator++();
            }
            if (item == freqOrder.end()) {
                freqOrder.push_back(chara);
            }
        };

        for (auto it: charNumMap) {
            constructList(it.first, it.second);
        }
        string res;
        for (char chara: freqOrder) {
            for (int i = 0; i < charNumMap.find(chara)->second; ++i) {
                res.push_back(chara);
            }
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