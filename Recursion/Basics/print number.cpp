#include<iostream>
using namespace std;

void printNum(int n){
    if(n==9) return ;
    cout<<n<<" ";
    printNum(n-1);
}

int main(){
    printNum(100);
    return 0;
}