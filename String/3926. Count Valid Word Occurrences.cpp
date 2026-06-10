class Solution {
public:
    string formString(vector<string>& chunks)
    {
        string str="";
        for(string s:chunks)  str+=s;
        str+=" ";
        return str;
    }


    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) 
    {
        unordered_map<string,int>mpp;
        string str=formString(chunks);
        int n=str.size();
        string temp="";
        for(int i=0;i<n;i++)
        {
            if(str[i]>='a' && str[i]<='z' )    temp+=str[i];
            else  if(str[i]=='-')    
            {
                if(temp!="" && (i-1)>=0 && (i+1)<n && (str[i+1]>='a' && str[i+1]<='z') && (str[i-1]>='a' && str[i-1]<='z'))
                temp+=str[i];
                else if(temp!=""){
                mpp[temp]++;
                temp="";
                }
            }
            else if(temp!="")                       
            {
                mpp[temp]++;
                temp="";
            }
        }

        int q=queries.size();
        vector<int>ans;
        for(int i=0;i<q;i++)  ans.push_back(mpp[queries[i]]);
        return ans;
    }
};