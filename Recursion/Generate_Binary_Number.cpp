Problem :Generate Binary Number (Given no of bits)
Approach 1 :Using library Function
Code :-
#include<iostream>
#include<vector>
#include<string>
#include<bitset>
using namespace std;

vector<string>generateBinary(int n)
{
    vector<string>ans;
    for(int i=0;i<(1<<n);i++)
    {
        bitset<32>b(i);
        string s=b.to_string();
        ans.push_back(s);
    }
    return ans;
}
int main()
{
    vector<string>ans=generateBinary(4);
    for(auto s:ans) cout<<s<<endl;
    return 0;
}

Approach 2 :Using Bit Manipulation 
Code :- 
#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string>generateBinary(int n)
{
    vector<string>ans;
    
    for(int i=0;i<(1<<n);i++)
    {
        string s="";
        for(int j=n-1;j>=0;j--)
        {
            if(i & (1<<j))
            s+="1";
            else
            s+="0";
        }
        ans.push_back(s);
    }
    return ans;
}
int main()
{
    vector<string>ans=generateBinary(3);
    for(auto s:ans) cout<<s<<endl;
    return 0;
}
Approach 3 :-Using Recursion (Easy to Understand)
Code :-  
#include<iostream>
#include<string>
#include<vector>
using namespace std;

void solve(int n,string s,vector<string>&ans)
{
    if(s.size()==n)
    {
        ans.push_back(s);
        return;
    }
    
    solve(n,s+"0",ans);
    solve(n,s+"1",ans);
}

vector<string>generateBinary(int n)
{
    vector<string>ans;
    solve(n,"",ans);
    return ans;
}

int main()
{
    vector<string>ans=generateBinary(3);
    for(auto s:ans) cout<<s<<endl;
    return 0;
}

