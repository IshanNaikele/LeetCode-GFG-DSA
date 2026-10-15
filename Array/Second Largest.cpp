#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) 
    {
        int first=INT_MIN,second=INT_MIN;
        int n=arr.size();
        
        for(int i=0;i<n;i++){
            if (first<arr[i]){
                second=first;
                first=arr[i];
            }
            else if(first>arr[i] && second < arr[i]){
                second=arr[i];
            }
        }
        
        if (second==INT_MIN) return -1 ;
        return second ;
    }
};

// class Solution:
//     def getSecondLargest(self, arr):
//         first=float('-inf')
//         second=float('-inf')
        
//         n=len(arr)
        
//         for i in range(0,n):
//             if first<arr[i] :
//                 second=first
//                 first=arr[i] 
                
//             elif first>arr[i] and second<arr[i] :
//                 second=arr[i]
        
//         if second==float('-inf'):
//             return -1 
//         return second
int main(){

    return 0;
}