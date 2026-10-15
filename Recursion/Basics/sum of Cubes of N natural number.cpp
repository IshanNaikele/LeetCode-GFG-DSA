#include<iostream>
using namespace std;

int sumOfCubes(int n){
    if(n==0) return 0;
    return (n*n*n)+sumOfCubes(n-1);
}

// def sumOfCubes(n):
//   if n==0:
//     return 0
//   return (n*n*n)+sumOfCubes(n-1)

// print(sumOfCubes(5))

int main(){
    cout<<sumOfCubes(5);
    return 0;
}