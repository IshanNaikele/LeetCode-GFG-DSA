//Approach 1 :

class Solution {
public:
    int minAddToMakeValid(string s) 
    {
        stack<char>st;
        for(char ch:s)
        {
            if(st.empty()) st.push(ch);
            else
            {
                if(ch==')' && st.top()=='(') st.pop();
                else                         st.push(ch);
            }
        }
        return st.size();
    }
};

//Approach 2 :
class Solution {
public:
    int minAddToMakeValid(string s) 
    {
        int open=0,close=0;
        for(char ch:s)
        {
            if(ch=='(') open++;
            else
            {
                if(open>0) open--;
                else       close++; 
            }
        }
        return open + close;
    }
};