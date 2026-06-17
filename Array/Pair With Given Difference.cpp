int Solution::solve(vector<int> &A, int B) 
{
   sort(A.begin(),A.end());
   int n=A.size();
   int right=1,left=0;
   if(B<0) B*=-1;
   while(right<n)
   {
       int diff=A[right]-A[left];
       if(diff==B) return 1;
       else if(diff<B) right++;
       else            left++;
       
       if(left==right) right++;
   }
   return 0;
}
