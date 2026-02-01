#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>>memory;
    bool checkPalindrome(string &s,int start,int end)
    {
        if(start>end) return true;
        
        if(memory[start][end]!=-1)  return memory[start][end];
        if(s[start]==s[end])
            return memory[start][end]=checkPalindrome(s,start+1,end-1);
        
        return memory[start][end]=false;
    }

    string longestPalindrome(string s) 
    {
        int n=s.size(),maxLen=0,start=0;
        memory.assign(n,vector<int>(n,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                bool found=checkPalindrome(s,i,j);
                if(found)
                {
                    int len=j-i+1;
                    if(len>maxLen)
                    {
                        maxLen=j-i+1;
                        start=i;
                    }
                }
            }
        }
        return s.substr(start,maxLen);
    }
};