// As the manager of the hotel, you have N guests to attend to, and each guest has a happiness value 
// (Ci)  
// that depends on when they are served. The unhappiness of a guest is determined by the difference  
// between their happiness value (Ci) and the time (x) they are served, which is calculated as |Ci – x|. 
// Your  
// goal is to find the minimum total unhappiness by serving all guests in any order you choose. 
// Please note that at a given time, only one guest can be served, and each guest takes exactly one 
// unit of  
// time to be served. 
// Here are the constraints: 
// ·1 <= N <= 10^3 
// ·1 <= Ci <= N 
// For example: 
// Input: 4 2 2 3 3 
// Output: 2 
// Input: 4 1 1 1 1 
// Output: 6

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solve(vector<int>&nums)
{
    sort(nums.begin(),nums.end());
    int time=1,unHappiness=0;
    
    for(int num:nums)
    {
        unHappiness+=(abs(num-time));
        time++;
    }
    return unHappiness;
}
int main()
{
    vector<int>arr={1,1,1,1};
    cout<<solve(arr);
    return 0;
}