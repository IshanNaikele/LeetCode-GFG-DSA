#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    vector<int> getMinMax(vector<int> &arr) 
    {
        int n=arr.size();
        int maxElement=INT_MIN,minElement=INT_MAX;
        
        for(int i=0;i<n;i++){
            if (arr[i] > maxElement) maxElement=arr[i] ;
            if (arr[i] < minElement) minElement=arr[i] ;
        }
        
        return { minElement ,maxElement } ;
    }
};

// class Solution:
//     def getMinMax(self, arr):
//         maxElement=float('-inf')
//         minElement=float('inf')
        
//         n=len(arr)
        
//         for i in range(0,n):
//             if maxElement < arr[i] :
//                 maxElement=arr[i] 
//             if minElement > arr[i] :
//                 minElement =arr[i] 
                
//         return minElement,maxElement


int main(){

    return 0;
}