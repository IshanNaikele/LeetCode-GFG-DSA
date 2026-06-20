class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        sort(strs.begin(),strs.end());
        int len = min(strs.front().size(),strs.back().size());
        int i = 0;
        while(i < len && strs.front()[i] == strs.back()[i])    i++;
        
        return strs.front().substr(0, i);
    }
};