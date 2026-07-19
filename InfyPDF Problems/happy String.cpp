#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

bool isVowel(char ch)
{
    ch=tolower(ch);
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') return true;
    return false;
}
bool solve(string &s)
{
    int n=s.size(),count=0;
    for(int i=0;i<n;i++)
    {
        char ch=s[i];
        if(isVowel(ch)) count++;
        else            count=0;
        if(count>2) return true;
    }
    return false;
}
int main()
{
    string s="abcdeeafg";
    cout<<solve(s);
    return 0;
}