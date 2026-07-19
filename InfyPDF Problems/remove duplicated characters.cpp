// Chef wants to play the games of word but he hates words containing duplicated characters. 
// Can you help chef in designing an application which will remove duplicated characters from 
// the given word and print the count of duplicated characters. 
// Input : “balloon” 
// Output: balon 
// Count:2

#include<iostream>
#include<vector>
#include<climits>
#include<cmath>
#include<stack>
#include <unordered_map>
#include<algorithm>
using namespace std;

pair<string,int>solve(string &s)
{
    unordered_map<char,int>mpp;
    stack<pair<char,int>>st1;
    stack<pair<char,int>>st2;
    int duplicateCount=0;
    for(int i=0;i<s.size();i++)
    {
        if(mpp.find(s[i])!=mpp.end())
        {        
            while(!st1.empty() )
            {
                auto topPair=st1.top();
                char c=topPair.first;
                int count=topPair.second;
                st1.pop();
                if(c==s[i]){
                    st1.push({c,count+1});
                    break;
                }
                else
                st2.push(topPair);
            }
            
            while(!st2.empty())
            {
                auto p=st2.top();
                st2.pop();
                st1.push(p);
            }
        }
        else
          st1.push({s[i],1});
          
        mpp[s[i]]++;
    }
    string ans="";
    while(!st1.empty())
    {
        auto p=st1.top();
        st1.pop();
        char s=p.first;
        int count=p.second;
        duplicateCount+=(count-1);
        ans+=s;
    }
    reverse(ans.begin(),ans.end());
    return {ans,duplicateCount};
}
int main()
{
    string s="programming";
    auto p=solve(s);
    cout<<p.first<<endl<<p.second;
    return 0;
}



#include<iostream>
#include<vector>
#include<climits>
#include<cmath>
#include<stack>
#include <unordered_map>
#include<algorithm>
using namespace std;

pair<string,int>solve(string &s)
{
    unordered_map<char,int>mpp;
    int duplicateCount=0;
    string ans="";
    for(int i=0;i<s.size();i++){
        mpp[s[i]]++;
        if(mpp[s[i]]==1) ans+=s[i];
        else             duplicateCount++;
    } 
    return {ans,duplicateCount};
}
int main()
{
    string s="programming";
    auto p=solve(s);
    cout<<p.first<<endl<<p.second;
    return 0;
}