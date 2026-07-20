// Question 59: 
// There are three piles of stones. The first pile contains a stones, the second pile contains b stones 
// and the third pile contains c stones. You must choose one of the piles and split the stones from it to 
// the other two piles; specifically, if the chosen pile initially contained s stones, you should choose 
// an integer k (0≤k≤s), move k stones from the chosen pile onto one of the remaining two piles and 
// s−k stones onto the other remaining pile. Determine if it is possible for the two remaining piles (in 
// any order) to contain x stones and y stones respectively after performing this action. 
// INPUT FORMAT : 
// • The first line of the input contains a single integer T denoting the number of test cases. The 
// description of T test cases follows. 
// • The first and only line of each test case contains five space-separated integers 
// a,b,c, x and y. 
// OUTPUT FORMAT : 
// For each test case, print a single line containing the string “YES” if it is possible to obtain piles of the 
// given sizes or “NO” if it is impossible. 
// CONSTRAINTS : 
// • 1 <= T <= 100 
// • 1 <= a,b,c,x,y <= 10^9 
// SAMPLE INPUT : 
// 4 
// 1 2 3 2 4 
// 3 2 5 6 5 
// 2 4 2 6 2 
// 6 5 2 12 1 
// SAMPLE OUTPUT : 
// YES 
// NO 
// YES 
// NO 
// Test case 1: You can take the two stones on the second pile, put one of them on the first pile and 
// the other one on the third pile. 
// Test case  2: You do not have enough stones. 
// Test case 3: You can choose the first pile and put all stones from it on the second pile.


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool solve(long long a,long long b,long long c,long long x,long long y)
{
    if(a+b+c!=x+y) return false;
    
    vector<long long>arr1={a,b,c};
    vector<long long>arr2={x,y};
    sort(arr1.rbegin(),arr1.rend());
    sort(arr2.rbegin(),arr2.rend());
    long long remainStones=arr1[0];
    if(arr1[1]+arr1[0]>=arr2[0])
        remainStones=(arr1[0]+arr1[1])-arr2[0];
    else
       return false;
       
    return arr1[2]+remainStones==arr2[1];
}
int main()
{
    long long a = 1000000000, b = 1000000000, c = 1000000000, x = 1500000000, y = 1500000000;
    cout<<solve(a,b,c,x,y);
    return 0;
}