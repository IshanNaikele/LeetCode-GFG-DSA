class Solution {
  public:
   
    int towerOfHanoi(int n, int from, int to, int aux) 
    {
        // code here
        if(n==1) return 1;
        int count1=towerOfHanoi(n-1,from,aux,to);
         
        int count2=towerOfHanoi(n-1,from,to,aux);
        
        return count1+count2+1;
    }
};