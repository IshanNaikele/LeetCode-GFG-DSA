class Solution {
public:
    int minAddToMakeValid(string s) 
    {
        int open=0,close=0;
 
        for(char ch:s)
        {
            if(ch=='(')      open++;
            else if(open>0 && ch==')')  open--;
            else if(ch==')') close++;
        }
        return open+close;
    }
};