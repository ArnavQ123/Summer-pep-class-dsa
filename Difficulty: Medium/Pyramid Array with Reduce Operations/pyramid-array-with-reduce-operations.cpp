
class Solution {
  public:
    int formPyramid(vector<int>& arr) {
        //write ypur code here
        int n = arr.size();
        vector<int> l(n), r(n);
        l[0] = 1;
        for (int i = 1; i < n; i++)
            l[i] = min(arr[i], l[i - 1] + 1);

        r[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--)
            r[i] = min(arr[i], r[i + 1] + 1);

        long long sum = 0;
        int h = 0;

        for (int i = 0; i < n; i++) {
            sum += arr[i];
            h = max(h, min(l[i], r[i]));
        }

        return sum - 1LL * h * h;
    }
};

