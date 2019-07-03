//https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/help-ashwin/
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int k=0;k<t;k++)
    {
        int n,m;
        cin>>n>>m;
        int arr[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                cin>>arr[i][j];
            
             
        }
          int sec=0, lar=0;
          
        int dp[n][m];
        
         for(int j=0;j<m;j++)
            {
                
                    if(arr[0][j]>=lar)
                    { 
                        sec=lar;
                        lar=arr[0][j];
                         
                    }
                    dp[0][j]=arr[0][j];
            }  
        
        
        
        for(int i=1;i<n;i++)
        {
            int temp_lar=0,temp_sec=0;
          
           for(int j=0;j<m;j++)
            {    
                    if(dp[i-1][j]==lar)
                      dp[i][j]=arr[i][j]+sec;
                    else
                       dp[i][j]=arr[i][j]+lar;
                     
                    if(dp[i][j]>=temp_lar)
                    {
                        temp_sec =temp_lar;
                        temp_lar =dp[i][j];
                    }
                    
                    else 
			if(dp[i][j]>temp_sec)
	                       temp_sec=dp[i][j];
            }
        
            lar=temp_lar;
            sec=temp_sec;
            
        }
        cout<<lar<<endl;
    }
      return 0;
}
