class Solution {
public:
    int findMinCost(string &s1, string &s2, int costS1, int costS2) {
        int n = s1.size(), m = s2.size();
        vector<int> dp(m + 1);

        for (int j = 1; j <= m; j++)
            dp[j] = dp[j - 1] + costS2;

        for (int i = 1; i <= n; i++) {
            int prev = dp[0];
            dp[0] += costS1;

            for (int j = 1; j <= m; j++) {
                int temp = dp[j];

                if (s1[i - 1] == s2[j - 1])
                    dp[j] = prev;
                else
                    dp[j] = min(dp[j] + costS1,
                                dp[j - 1] + costS2);

                prev = temp;
            }
        }

        return dp[m];
    }
};