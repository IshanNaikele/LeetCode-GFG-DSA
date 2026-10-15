#include<iostream>
#include<vector>
using namespace std;

int sumOfArray(vector<int>&nums){
    int sum=0;
    int n=nums.size();
    for(int i=0;i<n;i++){
        sum+=nums[i];
    }
    return sum ;
}

int avgOfArray(vector<int>&nums){
    int sum=sumOfArray(nums);
    int n=nums.size();
    return (sum/n);
}

// def sumOfArray(nums):
//   sum=0
//   n=len(nums)

//   for i in range(0,n):
//     sum+=nums[i] 

//   return sum

// def avgOfArray(nums):
//   sum=sumOfArray(nums)
//   n=len(nums)

//   return sum/n


// nums=[3,5,3,2,6]
// print(sumOfArray(nums))
// print(avgOfArray(nums))

int main(){
    vector<int>nums={4,5,3,2,6};
    cout<<sumOfArray(nums)<<endl;
    cout<<avgOfArray(nums)<<endl;
    return 0;
}
