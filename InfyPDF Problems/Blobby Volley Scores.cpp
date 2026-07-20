// Alice and Bob are playing a game of Blobby Volley. In this game, in each turn, one player is the 
// server and the other player is the receiver. Initially, Alice is the server, and Bob is the receiver. 
// If the server wins the point in this turn, their score increases by 1, and they remain as the server for 
// the next turn. 
// But if the receiver wins the point in this turn, their score does not increase. But they become the 
// server in the next turn. 
// In other words, your score increases only when you win a point when you are the server. 
// Please see the Sample Inputs and Explanation for more detailed explanation. 
// They start with a score of 00 each, and play NN turns. The winner of each of those hands is given to 
// you as a string consisting of 'A's and 'B's. 'A' denoting that Alice won that point, and 'B' denoting that 
// Bob won that point. Your job is the find the score of both of them after the NN turns.

#include<iostream>
#include<vector>
#include<cmath>
#include<string>
using namespace std;

pair<int,int>solve(string &s)
{
    int points1=0,points2=0,n=s.size();
    bool server=true;
    for(int i=0;i<n;i++)
    {
        if(server && s[i]=='A') points1++;
        else if(s[i]=='B' && server==false) points2++;
        
        if(s[i]=='B') server=false;
        else          server=true;
    }
    return {points1,points2};
}

int main()
{
    string s="BABAB";
    auto p=solve(s);
    cout<<p.first<<endl;
    cout<<p.second;
    return 0;
}