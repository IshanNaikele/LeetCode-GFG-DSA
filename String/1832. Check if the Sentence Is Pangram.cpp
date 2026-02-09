class Solution {
public:
    bool checkIfPangram(string sentence) 
    {
        vector<bool>smallAlpha(26,false);
        for(char ch:sentence)
        smallAlpha[ch-'a']=true;
        
        for(int i=0;i<26;i++) 
        {
            if(smallAlpha[i]==false) return false;
        }
        return true;
    }
};