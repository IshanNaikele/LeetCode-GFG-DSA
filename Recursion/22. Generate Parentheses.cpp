class Solution {
public:
    void parenthesis(int left,int right,int n,string &str,vector<string>&ans)
    {
        if(right>=n) 
        {
            ans.push_back(str);
            return; 
        }
        if(left<n) 
        {
            str.push_back('(');
            parenthesis(left+1,right,n,str,ans);
            str.pop_back();
        }
        if(right<left)
        {
            str.push_back(')');
            parenthesis(left,right+1,n,str,ans);
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) 
    {
        int left=0,right=0;
        string str="";
        vector<string>ans;
        parenthesis(left,right,n,str,ans);
        return ans;
    }
};