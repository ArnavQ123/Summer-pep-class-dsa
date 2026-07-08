/*approach
Use a Monotonic Stack:
Maintain a stack of indices whose next greater element has not been found yet. The stack stores elements in decreasing order.
Simulate Circular Array:
Traverse the array twice (2 × n iterations) using i % n to handle the circular nature of the array.
Find the Next Greater Element:
While the current element is greater than the element at the index on the top of the stack, pop the index and update its answer with the current element.
Push Indices Only in the First Pass:
During the first n iterations, push indices onto the stack. Initialize the answer array with -1, so elements without a next greater element remain -1.*/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,-1);
        stack<int>p;
        for(int i=2*n-1;i>=0;i--){
            while(p.size()>0 && nums[p.top()]<=nums[i%n]){
                p.pop();
            }
            ans[i%n]=p.empty() ? -1: nums[p.top()];
            p.push(i%n);
        }
        return ans;
    }
};