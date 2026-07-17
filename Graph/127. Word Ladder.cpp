class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        unordered_set<string>unique(wordList.begin(),wordList.end());

        while(!q.empty())
        {
            auto p=q.front();
            string word=p.first;
            int steps=p.second;
            if(word==endWord) return steps;
            string orignalWord=word;
            q.pop();
            int n=word.size();
            for(int i=0;i<n;i++)
            {
                for(char ch='a';ch<='z';ch++)
                {
                    word[i]=ch;
                    if(unique.find(word)!=unique.end()) 
                    {
                        q.push({word,steps+1});
                        unique.erase(word);
                    }
                }
                word=orignalWord;
            }
        }
        return 0;
    }
};