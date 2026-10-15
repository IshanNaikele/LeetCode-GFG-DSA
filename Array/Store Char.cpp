#include<iostream>
#include<vector>
using namespace std;

// ASCII Value :A :65 ,a :97
vector<char>storeBigAlpha(){
    vector<char>ans(26);
    for(int i=0;i<26;i++){
        ans[i]=i+'A';
    }
    return ans;
}

vector<char>storeSmallAlpha(){
    vector<char>ans(26);
    for(int i=0;i<26;i++){
        ans[i]=i+'a';
    }
    return ans;
}

// def storeBigAlpha():
//   store=[None]*26
//   for i in range(0,26):
//     store[i]=chr(i+97)
//   return store

// def storeSmallAlpha():
//   store=[None]*26
//   for i in range(0,26):
//     store[i]=chr(i+65)
//   return store

// print(storeSmallAlpha())
// print(storeBigAlpha())

int main(){
    vector<char>smallAlpha=storeSmallAlpha();
    vector<char>bigAlpha=storeBigAlpha();

    for(char ch:smallAlpha) cout<<ch<<" ";
    cout<<endl;
    for(char ch:bigAlpha)   cout<<ch<<" ";
    return 0;
}