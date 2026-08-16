class Solution {
public:
    string multiply(string a, string b) {
        if (a == "0" || b == "0") return "0";
        int n = a.size(), m = b.size();
        vector<int> r(n + m);
        for (int i = n - 1; i >= 0; i--)
            for (int j = m - 1; j >= 0; j--) {
                int p = (a[i] - '0') * (b[j] - '0') + r[i + j + 1];
                r[i + j + 1] = p % 10;
                r[i + j] += p / 10;
            }
        string ans;
        for (int x : r)
            if (!ans.empty() || x) ans += x + '0';

        return ans;
    }
};