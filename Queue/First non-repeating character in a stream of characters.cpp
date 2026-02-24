string Solution::solve(string A) 
{
    queue<char>q;
    vector<int>freq(26,0);
    string ans="";
    for(char ch:A)
    {
        freq[ch-'a']++;
        if(freq[ch-'a']<2)  q.push(ch);
        while(!q.empty() && freq[q.front()-'a']>=2)              q.pop();
        if(!q.empty()) ans+=q.front();
        else           ans+='#';
    }
    return ans;
}
