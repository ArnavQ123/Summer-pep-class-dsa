class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize) return false;

        sort(hand.begin(), hand.end());

        unordered_map<int, int> freq;
        freq.reserve(n * 2);

        for (int x : hand) freq[x]++;

        for (int x : hand) {
            if (freq[x] == 0) continue;

            int cnt = freq[x];

            for (int i = 0; i < groupSize; i++) {
                if (freq[x + i] < cnt) return false;
                freq[x + i] -= cnt;
            }
        }

        return true;
    }
};