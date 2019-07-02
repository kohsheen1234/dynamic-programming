//link to the question - https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/palindrome-count-1/description/
 
 
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;
    
        string str;
        cin>>str;
        int n = str.size();
        //create a table to store the bool values ( if str[i] till str[j] is a palindrone, then dp[i][j] =true)
        bool dp[n][n];
       
       
       
        //initialise table to false
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                dp[i][j] = false;
            }
        }
    
        //initialise palindrone count to length of input string
        int count  = str.size();
        
        //str[i] till str[i] is always a palindrone(size=1)
        for(int i =0;i<n;i++)
        {
            dp[i][i] = true;
            
        }
        
        
        //str[i] till str[i+1] is a palindrone of size 2 only when str[i] == str[i+1]
        for(int i =0;i<n-1;i++)
        {
            if(str[i] == str[i+1])
               {
                   dp[i][i+1] = true;
                   count++;
               }
            else
                dp[i][i+1] = false;
        }
        
        
        //str[i] till str[j] is a palindrone of size greater than 2  only when the start and the end character is same
        //i.e str[i] == str[j] and it was a  palindrone till now. i.e str[i+1][j-1]==true
        
        for(int k = 2; k<n; k++)
        {
            for(int i = 0; i <n-k; i++)
            {
                
                int j =i+k;
                if(str[i]==str[j]  && dp[i+1][j-1]==true)
                {
                    dp[i][j] = true;
                    count++;
                }
                else
                    dp[i][j] = false;
            }
        }
        
       cout<<count;
       
      
   
    return 0;
}

