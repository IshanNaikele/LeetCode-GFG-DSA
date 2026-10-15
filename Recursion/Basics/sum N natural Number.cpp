#include<iostream>
using namespace std;

int sumNN(int n){
    if(n==0) return 0;
    return n+sumNN(n-1);
}

// def sumNN( n):
//   if n==0:
//     return 0
//   return n+sumNN(n-1)

// print(sumNN(10))

int main(){
    cout<<sumNN(5);
    return 0;
}