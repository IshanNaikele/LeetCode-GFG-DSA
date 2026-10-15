#include<iostream>
using namespace std;

void printTable1(int start,int n){
    if(start==11) return ;
    cout<<n<<"*"<<start<<"="<<n*start<<endl;
    printTable1(start+1,n);
}

// def printTable1(num,start=1):
//   if start==11:
//     return
//   print(f"{num}*{start}={num*start}")
//   printTable1(num,start+1)

 
  
// printTable1(3,1)
// printTable1(3)

int main(){
    printTable1(1,3);
    cout<<endl;
     
    return 0;
}