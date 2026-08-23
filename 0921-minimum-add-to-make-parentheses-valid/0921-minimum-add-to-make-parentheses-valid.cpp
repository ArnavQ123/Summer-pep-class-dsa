class Solution {
public:
    int minAddToMakeValid(string s) {
        int sp=0;
        int o=0;
        for(char &ch:s){
            if(ch=='('){
                sp++;
            }else if(sp>0){
                sp--;
            }else{
                o++;
            }
        }
        return o+sp;
    }
};