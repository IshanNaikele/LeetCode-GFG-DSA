// Approach 1:By using Stack
class Solution {
public:
    void reverseString(vector<char>& s) 
    {
        stack<char>st;
        for(char ch:s)
        st.push(ch);

        for(int i=0;i<s.size();i++)
        {
            s[i]=st.top();
            st.pop();
        }
    }
};
//Approach 2 :Two Pointer 
class Solution {
public:
    void reverseString(vector<char>& s) 
    {
        int start=0,end=s.size()-1;
        while(start<end)
        swap(s[start++],s[end--]);
    }
};
