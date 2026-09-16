class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        unordered_map<int,int>lp;
        long long s=0;
        int ans=0;
        lp[0]=-1;
        for(int i=0;i<arr.size();i++){
            s+=arr[i];
            if(lp.find(s)!=lp.end()){
                ans=max(ans,i-lp[s]);
            }
            else{
                lp[s]=i;
            }
        }
        return ans;
    }
};