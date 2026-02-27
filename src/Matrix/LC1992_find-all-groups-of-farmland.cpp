/**
 * LeetCode 1992: find-all-groups-of-farmland
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        auto findBottomRight = [&] (int x, int y) -> vector<int> {
            int bottom = x;
            int right = y;
            for (int i = x; i < land.size(); ++i) {
                if (!land[i][y]) {
                    break;
                }
                bottom = i;
            }
            for (int i = y; i < land[x].size(); ++i) {
                if (!land[x][i]) {
                    break;
                }
                right = i;
                for (int j = x; j <= bottom; ++j) {
                    land[j][i] = 0;
                }
            }
            return {bottom, right};
        };
        vector<vector<int>> res;
        for (int i = 0; i < land.size(); ++i) {
            for (int j = 0; j < land[i].size(); ++j) {
                if (land[i][j]) {
                    vector<int> temp{i, j, i, j};
                    vector<int> bottomRight = findBottomRight(i, j);
                    temp[2] = bottomRight[0];
                    temp[3] = bottomRight[1];
                    res.push_back(temp);
                }
            }
        }

        return res;
    }
};

int main() {
    vector<vector<int>> case1{{1, 0, 0},
                              {0, 1, 1},
                              {0, 1, 1}};
    Solution solution;
    vector<vector<int>> res = solution.findFarmland(case1);
    for (const vector<int>& single: res) {
        for (int i: single) {
            cout << i << " ";
        }
        cout << endl;
    }
}