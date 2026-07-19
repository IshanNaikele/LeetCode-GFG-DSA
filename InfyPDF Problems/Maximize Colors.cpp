// For the human eye, primary colours are red, green, and blue.

// Combining 1-1 drop each of any two primary colours produces a new type of secondary colour. For example, mixing red and green gives yellow, mixing green and blue gives cyan, and, mixing red and blue gives magenta.

// You have X,Y,X,Y, and Z
// Z drops of red, green, and blue colours respectively. Find the maximum total number of distinct colours (both primary and secondary) you can have at any particular moment.

// Note: You cannot mix a secondary colour with a primary or another secondary colour to get a new type of colour.


#include<iostream>
#include<algorithm>
using namespace std;

int findMaxDistinctColor(int x,int y,int z)
{
    int count=0;
    vector<int>arr;
    if(x>0) 
    {
        count++;
        x--;
    }
    if(y>0)
    {
        count++;
        y--;
    }
    if(z>0) 
    {
        count++;
        z--;
    }
    arr.push_back(x);
    arr.push_back(y);
    arr.push_back(z);
    sort(arr.rbegin(),arr.rend());
    
    if(arr[0]>0 && arr[1]>0)
    {
        arr[0]--;
        arr[1]--;
        count++;
    }
    
    if(arr[0]>0 && arr[2]>0)
    {
        arr[0]--;
        arr[2]--;
        count++;
    }
    
    if(arr[1]>0 && arr[2]>0)
    {
        arr[1]--;
        arr[2]--;
        count++;
    }
    return count;
}
int main()
{
    
    return 0;
}