//link - https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/rhezo-and-prime-problems/
#include<bits/stdc++.h>
#define MAXN 5005
using namespace std;
vector<int> v;
bool vis[5005];
int arr[5005];
int pre[5005] ;
int dp[5005];
int n; 

void visitor() {
	v.push_back(2);
	for(int i=3;i<MAXN;i+=2) if(!vis[i]) {
		v.push_back(i);
		for(int j=i*i;j<MAXN;j+=2*i) vis[j]=true;
	}
}

int main()
{
    cin>>n;
   
    for(int i = 1 ; i<= n;i++)
    {
        cin>>arr[i];
        pre[i] = pre[i-1] + arr[i];
    }
    
    
    
    visitor();
    dp[0] = dp[1]  =0;
    for(int i = 2; i<=n; i++)
    {
        dp[i] = dp[i-1];
        for(int j = 0 ; j<(int)v.size() && v[j]<=i ; j++)
        {
            int p = i-v[j]-1;
            if(p==-1)
            {
                dp[i] = max(dp[i], pre[i]);
            }
            else
                dp[i] = max(dp[i] , pre[i] + dp[p] - pre[p+1] );
        }
    }
    
    cout<<dp[n]<<endl;
    
    return 0;
}
