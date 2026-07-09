class Solution {
public:
    string removeOuterParentheses(string s) {
        string hi="";
        stack<char> st;
        for(char ch:s){
            if(ch==')')st.pop();
            if(!st.empty()) hi+=ch;
            if(ch=='(') st.push(ch);
        }
        return hi;
    }
};