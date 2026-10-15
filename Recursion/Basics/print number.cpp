#include<iostream>
using namespace std;

void printNum(int n){
    if(n==9) return ;
    cout<<n<<" ";
    printNum(n-1);
}

// def printNum(num):
//   if num==9:
//     return

//   print(num)
//   printNum(num-1)

// printNum(100)

int main(){
    printNum(100);
    return 0;
}