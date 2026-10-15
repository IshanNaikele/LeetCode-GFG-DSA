#include<iostream>
#include<vector>
using namespace std;

int prod(vector<int>&nums,int index){
    int n=nums.size();
    if(index==n) return 1;
    return nums[index]*prod(nums,index+1);
}

// def prod(nums,index):
//   if len(nums)==index:
//     return 1
//   return nums[index]*prod(nums,index+1)

// nums=[1,4,5,3,2]
// print(prod(nums,0))

int main(){
    vector<int>nums={1,2,3,5};
    cout<<prod(nums,0);
    return 0;
}