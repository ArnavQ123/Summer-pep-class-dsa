class Solution {
  public:
    int dominantPairs(vector<int> &arr) {
        // Code here
        int n = arr.size(); 
        int h = n / 2;
        int ans = 0;
        sort(arr.begin() + h, arr.end());
        for (int i = 0; i < h; i++) {
            int l = h, r = n;
            while (l < r) {
                int m = (l + r) / 2;
                if (5LL * arr[m] <= arr[i])
                    l = m + 1;
                else
                    r = m;
            }
            ans += l - h;
        }
        return ans;
        
    }
};