//link - https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/vanya-and-gcd-array/
#include<bits/stdc++.h>
#define ll long long
#define lld long double
#define MOD 1000000007
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
int main(){

ll N;
cin>>N;
ll arr[N],dp[N][101]={0};
for(ll i=0;i<N;i++){
cin>>arr[i];
dp[i][arr[i]]++;
}


for(ll i=0;i<N;i++)
{
    for(ll j=i+1;j<N;j++)
    {
        if(arr[i]<arr[j])
        {
            for(ll k=1;k<=100;k++)
            {
                if(dp[i][k])
                {
                    dp[j][__gcd(k,arr[j])]=(dp[i][k]+dp[j][__gcd(k,arr[j])])%MOD;
                    // cout<<"i : "<<i<< " k: "<<k<<endl;
                    // cout<<dp[i][k]<<endl;
                }
                    
            }
        }
    }
}

// for(ll i=0;i<N;i++)
// {
//     for(ll j=0;j<15;j++)
//     {
//         cout<<dp[i][j]<<" ";
//     }
//     cout<<endl;
// }


ll ans=0;
for(ll i=0;i<N;i++)
ans=(ans+dp[i][1])%MOD;
cout<<ans<<endl;
}
