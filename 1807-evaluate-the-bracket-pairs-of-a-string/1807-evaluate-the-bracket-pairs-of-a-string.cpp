class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for (auto &p : knowledge)
            mp[p[0]] = p[1];

        string ans;
        for (int i = 0; i < s.size();) {
            if (s[i] == '(') {
                int j = s.find(')', i);
                string key = s.substr(i + 1, j - i - 1);
                ans += mp.count(key) ? mp[key] : "?";
                i = j + 1;
            } else {
                ans += s[i++];
            }
        }
        return ans;
    }
};