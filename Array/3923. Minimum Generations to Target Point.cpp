class Solution {
public:
     
    int minGenerations(vector<vector<int>>& points, vector<int>& target) 
    {
        set<vector<int>>curr; 
        for(auto &v:points)
        curr.insert({v[0],v[1],v[2]});
        if(curr.count({target[0],target[1],target[2]})) return 0;

        for(int gen=1;gen<350;gen++)
        {
            set<vector<int>>nxt;
            vector<vector<int>>pts(curr.begin(),curr.end());
            int n=pts.size();
            for(int i=0;i<n;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    int first=(pts[i][0]+pts[j][0])/2; 
                    int second=(pts[i][1]+pts[j][1])/2;
                    int third=(pts[i][2]+pts[j][2])/2;
                    nxt.insert({first,second,third});
                }
            }
            if (nxt.count(target))   return gen;
            bool added = false;

            for (auto &p : nxt)
            {
                auto res = curr.insert(p);
                if (res.second)    
                    added = true;
            }

            if (!added)          
                break;
            }
    
        return -1;
    }
};