/*appraoch
1. Traverse nums2 from left to right while maintaining a monotonic decreasing stack.
2. Whenever the current element is greater than the stack's top, pop the stack and store the current element as the next greater element in a hash map.
3. After processing nums2, use the hash map to find the next greater element for each value in nums1. If no greater element exists, return -1.
4. This approach processes each element at most twice, giving O(n + m) time complexity with O(n) extra space.
*/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>&nums1,vector<int>&nums2) {
       int n=nums1.size();
       int m=nums2.size();
       stack<int>dt;
       unordered_map<int,int>pp;
       vector<int> ans(n);
       for(int i=m-1;i>=0;i--){
        while(!dt.empty() && dt.top()<=nums2[i]){
            dt.pop();
        }
        if(dt.empty()) pp[nums2[i]]=-1;
        else pp[nums2[i]]=dt.top();
        dt.push(nums2[i]);
       }
       for(int i=0;i<n;i++){
        ans[i]=pp[nums1[i]];
       }
       return ans;
    }
};
