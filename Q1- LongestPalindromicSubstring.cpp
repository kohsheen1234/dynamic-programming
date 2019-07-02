//link to the question -  https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/palindromic-sub-string-length/


#include<bits/stdc++.h>
using namespace std;


bool isPrime(int max)
{
    if(max==1)
        return false;
    if(max==2)
        return true;
     for(int i = 2;i<max;i++)
        {
            
            if(max%i==0)
            {
                return false;
            }
        }
        return true;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
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
        
        //initialise max_length of palindrone as 1
        int max=1;
        
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
                   max =2;
                  
               }
            else
                dp[i][i+1] = false;
        }
        
        
        //str[i] till str[j] is a palindrone of size greater than 2  only when the start and the end character is same
        //i.e str[i] == str[j] and it was a  palindrone till now. i.e str[i+1][j-1]==true
        
        int start, end;
        for(int k = 2; k<n; k++)
        {
            for(int i = 0; i <n-k; i++)
            {
                
                int j =i+k;
                if(str[i]==str[j]  && dp[i+1][j-1]==true)
                {
                    dp[i][j] = true;
                    if(j-i+1>max)
                    {
                        start = i;
                        end = j;
                        max = j-i+1;
                    }
                }
                else
                {
                    dp[i][j] = false;
                    
                }
            }
        }
        
        //max is the final length of the palindromic string
        //substr(start, index) is the palindromic substring
        
        
        
        //check if the max-length is a prime number or not
        
        if(isPrime(max))
        {
            cout<<"PRIME"<<endl;
        }
        else
        {
             cout<<"NOT PRIME"<<endl;
        }
    }
    return 0;
}
