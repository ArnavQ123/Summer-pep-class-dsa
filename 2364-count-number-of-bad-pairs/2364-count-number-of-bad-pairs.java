class Solution {
    public long countBadPairs(int[] nums) {
        long bp=0;
        Map<Integer,Integer> dc=new HashMap<>();
        for(int pos=0;pos<nums.length;pos++){
            int diff=pos-nums[pos];
            int gp=dc.getOrDefault(diff,0);
            bp+=pos-gp;
            dc.put(diff,gp+1);
        }
        return bp;
    }
}