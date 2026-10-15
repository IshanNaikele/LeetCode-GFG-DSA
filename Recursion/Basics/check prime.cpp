#include<iostream>
using namespace std;

bool checkPrime(int start,int num){
    if(num<2) return false;
    if(start==num) return true;
    if(num%start==0) return false;
    return checkPrime(start+1,num);
}

// def checkPrime(start , num):
//   if num<2 :
//     return False
//   if start==num:
//     return True
//   if num%start==0 :
//     return False
//   return checkPrime(start+1,num)

// print(checkPrime(2,2))

int main(){
    cout<<checkPrime(2,2);
    return 0;
}