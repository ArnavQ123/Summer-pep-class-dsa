class Solution {
public:
    long long maxProfit(int x, int y, vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<int> d(n);
        long long ans = 0;

        for(int i = 0; i < n; i++) {
            ans += b[i];
            d[i] = a[i] - b[i];
        }

        sort(d.rbegin(), d.rend());

        int need = n - y;

        for(int i = 0; i < x; i++) {
            if(i < need || d[i] > 0)
                ans += d[i];
            else
                break;
        }

        return ans;
    }
};