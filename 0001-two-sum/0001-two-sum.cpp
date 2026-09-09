class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>fp;
        for(int i=0;i<nums.size();i++){
            int need=target-nums[i];
            if(fp.count(need))
                return{fp[need],i};
            fp[nums[i]]=i;
        }
        return {};
    }
};