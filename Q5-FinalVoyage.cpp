// link - https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/final-voyage-1/description/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int W;
        cin>>W;
        int weights[n];
        int val[n];
        for(int i = 0 ; i < n ; i++)
        {
            cin>>weights[i];
        }
        for(int i = 0 ; i < n ; i++)
        {
            cin>>val[i];
        }
        int dp[n+1][W+1];
        for(int i = 0 ; i <=n ; i++)
        {
            dp[i][0] =0;
        }
        for(int j = 0 ; j <=W ; j++)
        {
            dp[0][j] =0;
        }
    
        
        for(int i=1;i<=n;i++)
        for(int j=1;j<=W;j++)
        {
            if(j-weights[i-1]>=0)
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-weights[i-1]]+val[i-1]);
            else
                dp[i][j] = dp[i-1][j];
        }
         cout<<dp[n][W]<<endl;
  
       
        }
       
}
