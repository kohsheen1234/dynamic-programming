//https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/pankaj-and-his-in-laws/
#include<bits/stdc++.h>
 
using namespace std;
 
void Convert(int a)
{
    stack<int> s;
    while(a)
    {
        s.push(a%2);
        a/=2;
    }
    while(!s.empty())
    {
        a=s.top();
        cout<<a;
        s.pop();
    }
}
 
 
int main() {
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0 ; i < n ; i++)
	{
	    cin>>arr[i];
	}
	
	int maxx = -1;
	vector<int> dp(n,1);
	for(int i = 1; i < n ; i++)
	{
	    for(int j = 0 ; j< i ;j++)
	    {
	        if(arr[i]>=arr[j])
	        {
	            dp[i] = max(dp[i],1 + dp[j]);
	        }
	       
	    }
	     maxx=max(maxx,dp[i]);
	}
	Convert(maxx);
    
 
}
 
