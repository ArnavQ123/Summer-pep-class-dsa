class Solution {
    public int numSubarraysWithSum(int[] nums, int goal) {
        int res=0;
        int pp=0;
        Map<Integer,Integer>map=new HashMap();
        map.put(0,1);
        for(int i=0;i<nums.length;i++){
            pp+=nums[i];
            res+=map.getOrDefault(pp-goal,0);
            map.put(pp,map.getOrDefault(pp,0)+1);
        }
        return res;
    }
}