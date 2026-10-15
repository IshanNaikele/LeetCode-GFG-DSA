#include<iostream>
using namespace std ;

void printOddNum(int start,int n){
    if(start>n) return ;
    if(start%2==1)
    cout<<start<<" ";
    printOddNum(start+1,n);
}

// def printOddNum(start,num):
//   if start==num+1: 
//     return 
//   if start%2==1 :
//     print(start)
//   printOddNum(start+1,num)

// printOddNum(1,11)

int main(){
    printOddNum(1,10);
    return 0;
}