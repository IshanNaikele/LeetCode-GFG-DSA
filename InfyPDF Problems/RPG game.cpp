// While playing an RPG game, you were assigned to complete one of the hardest quests in 
// this game. There are n monsters you’ll need to defeat in this quest. Each monster i is 
// described with two integer numbers – poweri and bonusi. To defeat this monster, you’ll need 
// at least poweri experience points. If you try fighting this monster without having enough 
// experience points, you lose immediately. You will also gain bonusi experience points if you 
// defeat this monster. You can defeat monsters in any order.The quest turned out to be very 
// hard – you try to defeat the monsters but keep losing repeatedly. Your friend told you that 
// this quest is impossible to complete. Knowing that, you’re interested, what is the maximum 
// possible number of monsters you can defeat? 
// Input: 
// · The first line contains an integer, n, denoting the number of monsters. The next line contains an 
// integer, e, denoting your initial experience. 
// · Each line i of the n subsequent lines (where 0 ≤ i < n) contains an integer, poweri, which represents 
// power of the corresponding monster. 
// · Each line i of the n subsequent lines (where 0 ≤ i < n) contains an integer, bonusi, which represents 
// bonus for defeating the corresponding monster 


#include<iostream>
#include<vector>
#include<climits>
#include<cmath>
#include<stack>
#include <unordered_map>
#include<algorithm>
using namespace std;

int solve(vector<int>&power,vector<int>&bonus,int initialEnergy)
{
    vector<pair<int,int>>vec;
    for(int i=0;i<power.size();i++)
        vec.push_back({power[i],bonus[i]});
    
    sort(vec.begin(),vec.end());
    int count=0;
    for(int i=0;i<vec.size();i++)
    {
        auto p=vec[i];
        int energy=p.first;
        int bon=p.second;
        if(initialEnergy>=energy){
            initialEnergy+=bon;
            count++;
        }
        else { 
            break;
        }
    }
    return count;
}
int main()
{
    vector<int>power={101,100,304};
    vector<int>bonus={100,1,524};
    int initialEnergy=100;
    cout<<solve(power,bonus,initialEnergy);
    return 0;
}