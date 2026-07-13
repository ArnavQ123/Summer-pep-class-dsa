class Solution {
public:
    bool isFeasible(vector<int>& weights, int capacity, int days) {
        int currentLoad = 0;
        int daysNeeded = 1;
        
        for (int weight : weights) {
            currentLoad += weight;
            
            if (currentLoad > capacity) {
                daysNeeded++;
                currentLoad = weight;
            }
        }
        return daysNeeded <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0;
        int right = 0;
        
        for (int weight : weights) {
            left = max(left, weight);
            right += weight;
        }
        int answer = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isFeasible(weights, mid, days)) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
    
        return answer;
    }
};