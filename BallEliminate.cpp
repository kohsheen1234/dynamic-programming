// link - https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/ball-elimination/description/

#include<bits/stdc++.h>

using namespace std;

int arr[501];
int dp[501][501];

int Eliminate(int i , int j)
{
    //since we are finding cost for arr[i] till arr[j], we cannot have i>j
    if(i>j)
    {
        return 0;
    }
    // cost for single element is always 1
    if(i==j)
    {
        return 1;
    }
    int res =100000;
    if(dp[i][j]!=-1)
        return dp[i][j];
    res = min(res, Eliminate(i+1, j) + 1);
    for(int k =i+1;k<=j;k++)
    {
        //k is index between i+1 till j(including both)
        if(arr[i]==arr[k])
        {
            //cost from arr[i] till arr[j] is arr[i+1]arr[k-1] + arr[k+1][j], 
            //since cost of (arr[i] and arr[k]) is 0 because they are equal. 
            res = min(res, Eliminate(i+1, k-1) + Eliminate(k+1, j));
        }
    }
    return dp[i][j] =res;
    
}


int main()
{
    int n;
    cin>>n;
    for(int i = 0 ; i<n ;i++)
    {
        cin>>arr[i];
    }
    memset(dp, -1, sizeof(dp));
    int ans = Eliminate(0, n-1);
    cout<<ans;
}
