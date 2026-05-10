class Solution {
public:

    void solve(string digits,vector<string>&ans,string &temp,unordered_map<int,string>mpp,int index)
    {
        if(index==digits.size()) 
        {
            ans.push_back(temp);
            return;
        }
        int num=digits[index]-'0';
        string letters=mpp[num];
        for(char ch:letters)
        {
            temp+=ch;
            solve(digits,ans,temp,mpp,index+1);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) 
    {
        if(digits.empty()) return {};
        vector<string>ans;
        unordered_map<int,string>mpp;
        mpp[2]="abc";
        mpp[3]="def";
        mpp[4]="ghi";
        mpp[5]="jkl";
        mpp[6]="mno";
        mpp[7]="pqrs";
        mpp[8]="tuv";
        mpp[9]="wxyz";
        string temp="";
        solve(digits,ans,temp,mpp,0);
        return ans;
    }
};