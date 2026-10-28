class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        const int X = 1024;
        vector<bitset<X>> dp(n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bitset<X> cur;
                int v = grid[i][j];

                if (i == 0 && j == 0) {
                    cur[v] = 1;
                } else {
                  
                    if (i > 0) {
                        for (int x = 0; x < X; x++) {
                            if (dp[j][x]) {
                                cur[x ^ v] = 1;
                            }
                        }
                    }

                    if (j > 0) {
                        for (int x = 0; x < X; x++) {
                            if (dp[j - 1][x]) {
                                cur[x ^ v] = 1;
                            }
                        }
                    }
                }

                dp[j] = cur;
            }
        }

        for (int x = 0; x < X; x++) {
            if (dp[n - 1][x]) {
                return x;
            }
        }

        return -1;
    }
};