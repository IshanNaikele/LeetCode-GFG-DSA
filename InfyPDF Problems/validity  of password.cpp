#include<iostream>
#include<vector>
#include<climits>
#include<cmath>
#include<stack>
#include <unordered_map>
#include<algorithm>
using namespace std;

bool solve(string &s)
{
    if(s.size()<8)    return false;
    if(isdigit(s[0])) return false;
    bool upperCase=false,lowerCase=false,specialChar=false,digit=false;
    for(int i=0;i<s.size();i++)
    {
        char ch=s[i];
        if(ch>='A' && ch<='Z')      upperCase=true;
        else if(ch>='a' && ch<='z') lowerCase=true;
        else if(isdigit(ch))        digit=true;
        else if(ch=='_' || ch=='@' || ch=='$') specialChar=true;
        
        if(upperCase && lowerCase && specialChar && digit) return true;
    }
    return false;
}
int main()
{
    string password="Abcd!123";
    cout<<solve(password);
    return 0;
}