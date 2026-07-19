// Remove Element

// You are given an array A of N positive integers and an integer K.

// You can perform the following operation any number of times:

// Choose any two distinct elements A[i] and A[j] such that

// A[i] + A[j] ≤ K
// Remove either one of these two elements from the array.

// Determine whether it is possible to reduce the array to exactly one element by performing the above operation repeatedly.

#include<iostream>
#include<algorithm>
using namespace std;

bool solve(vector<int>&arr,int k)
{
    sort(arr.begin(),arr.end());
    int n=arr.size();
    int start=0,end=n-1;
    while(start<end)
    {
        if(arr[start]+arr[end]>k) return false;
        end--;
    }
    return true;
}
int main()
{
    
    return 0;
}