#include<iostream>
#include<string>
#include<vector>
using namespace std;

void solve(string str,vector<string>&ans,int index,string &temp)
{
    if(index==str.size()) 
    {
        ans.push_back(temp);
        return;
    }
    solve(str,ans,index+1,temp);
    temp+=str[index];
    solve(str,ans,index+1,temp);
    temp.pop_back();
}
vector<string>generateSubsequence(string str)
{
    vector<string>ans;
    int index=0;
    string temp="";
    solve(str,ans,index,temp);
    return ans;
}
int main()
{
    string str="Isha";
    vector<string>ans=generateSubsequence(str);
    for(string s:ans) cout<<s<<endl;
    return 0;
}