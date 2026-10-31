
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<long long>> dpRight(
            m, vector<long long>(n, 0)
        );

        vector<vector<long long>> dpDown(
            m, vector<long long>(n, 0)
        );
        dpRight[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                long long right = dpRight[i][j];
                long long down = dpDown[i][j];

                if (grid[i][j] == 0) {

                    if (j + 1 < n) {
                        dpRight[i][j + 1] =
                            (dpRight[i][j + 1] + right + down) % MOD;
                    }
                    if (i + 1 < m) {
                        dpDown[i + 1][j] =
                            (dpDown[i + 1][j] + right + down) % MOD;
                    }

                } else {
                    if (i + 1 < m) {
                        dpDown[i + 1][j] =
                            (dpDown[i + 1][j] + right) % MOD;
                    }
                    if (j + 1 < n) {
                        dpRight[i][j + 1] =
                            (dpRight[i][j + 1] + down) % MOD;
                    }
                }
            }
        }

        return (dpRight[m - 1][n - 1] +
                dpDown[m - 1][n - 1]) % MOD;
    }
};
