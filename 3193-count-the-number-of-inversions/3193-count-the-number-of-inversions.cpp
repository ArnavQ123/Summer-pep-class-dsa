class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        const int MOD = 1e9 + 7;
        vector<int> req(n, -1);

        for (auto &v : requirements)
            req[v[0]] = v[1];

        if (req[0] > 0) return 0;
        req[0] = 0;

        int m = *max_element(req.begin(), req.end());

        vector<vector<int>> dp(n, vector<int>(m + 1));
        dp[0][0] = 1;

        for (int i = 1; i < n; i++) {
            vector<int> pre(m + 1);
            pre[0] = dp[i - 1][0];
            for (int j = 1; j <= m; j++)
                pre[j] = (pre[j - 1] + dp[i - 1][j]) % MOD;

            for (int j = 0; j <= m; j++) {
                if (req[i] != -1 && j != req[i]) continue;

                dp[i][j] = pre[j];
                if (j > i) {
                    dp[i][j] = (dp[i][j] - pre[j - i - 1] + MOD) % MOD;
                }
            }
        }

        return dp[n - 1][req[n - 1]];
    }
};