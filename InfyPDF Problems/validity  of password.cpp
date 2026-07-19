// Chef wants to keep her data secure for which she applied password to her machine. If 
// someone wants to hack the data by entering valid password then the signal will be sent to 
// chef. Your task is to help chef in designing such an application which will check the validity 
// of password. The password is valid if it satisfies following condition. 
// • Minimum 8 characters. 
// • The alphabet must be between [a-z] 
// • At least one alphabet should be of Upper Case [A-Z] 
// • At least 1 number or digit between [0-9]. 
// • At least 1 character from [ _ or @ or $ ]. 
// • Should not start with number 

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