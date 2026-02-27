/**
 * LeetCode 1992: find-all-groups-of-farmland
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>> &land) {
        if (land.empty() || land[0].empty()) {
            return {};
        }
        const size_t rows = land.size();
        const size_t cols = land[0].size();
        auto findBottomRightAndTagLand = [&land, rows, cols](size_t startX, size_t startY) -> pair<int, int> {
            size_t bottom = startX;
            size_t right = startY;
            while (bottom < rows && land[bottom][startY] == 1) {
                bottom++;
            }
            while (right < cols && land[startX][right] == 1) {
                right++;
            }
            for (size_t i = startX; i < bottom; ++i) {
                for (size_t j = startY; j < right; ++j) {
                    land[i][j] = 0;
                }
            }
            return {static_cast<int>(bottom - 1), static_cast<int>(right - 1)};
        };
        vector<vector<int>> res;
        for (size_t i = 0; i < land.size(); ++i) {
            for (size_t j = 0; j < land[i].size(); ++j) {
                if (land[i][j]) {
                    auto[bottom, right] = findBottomRightAndTagLand(i, j);
                    res.emplace_back(vector<int>{static_cast<int>(i), static_cast<int>(j), bottom, right});
                }
            }
        }

        return res;
    }
};

int main() {
    vector<vector<int>> case1{{0, 1},
                              {1, 0}};
    Solution solution;
    vector<vector<int>> res = solution.findFarmland(case1);
    for (const vector<int>& single: res) {
        for (int i: single) {
            cout << i << " ";
        }
        cout << endl;
    }
}