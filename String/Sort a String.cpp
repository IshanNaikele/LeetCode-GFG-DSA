// Approach 1 :

string sort(string s) 
{
    // complete the function here
    sort(s.begin(),s.end());
    return s;
}

//Approach 2 :
string sort(string s) 
{
    // complete the function here
    vector<int>smallAlpha(26,0);
    for(char ch:s)
    smallAlpha[ch-'a']++;
    int index=0;
    for(int i=0;i<26;i++)
    {
        while(smallAlpha[i]!=0)
        {
            s[index++]='a'+i;
            smallAlpha[i]--;
        }
    }
    return s;
}