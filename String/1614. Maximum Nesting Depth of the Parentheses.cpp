class Solution {
public:
    int maxDepth(string s) 
    {
        int balance=0,depth=0;
        for(char ch:s)
        {
            if(ch=='(')
            balance++;
            else if(ch==')')
            balance--;

           depth=max(depth,balance);
        }
        return depth;
    }
};