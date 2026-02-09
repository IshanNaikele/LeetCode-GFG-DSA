class Solution {
  public:
    
    bool rotateClockwise(string s1,string s2)
    {
        int n=s1.size();
        for(int i=0;i<n;i++)
        {
            if(s1[i]!=s2[(i+2)%n]) return false;
        }
        return true;
    }
    
    bool rotateAnticlockwise(string s1,string s2)
    {
        int n=s1.size();
        for(int i=0;i<n;i++)
        {
            if(s1[(i+2)%n]!=s2[i])  return false;
        }
        return true;
    }
    
    bool isRotated(string& s1, string& s2) 
    {
        if(s1.size()!=s2.size()) return false;
        bool clockwise=rotateClockwise(s1,s2);
        bool anticlockwise=rotateAnticlockwise(s1,s2);
        return clockwise || anticlockwise;
    }
};
