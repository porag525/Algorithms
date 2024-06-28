#include<bits/stdc++.h>
using namespace std;
string s1,s2;
const int N=1000;
int dp[N][N];
int LCS(int i,int j)
{
    if(s1.size()==i || s2.size()==j)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if(s1[i]==s2[j])
    {
        int ans= (1+LCS(i+1,j+1));
        dp[i][j]=ans;
        return ans;
    }

    int ans=max(LCS(i+1,j),LCS(i,j+1));
    dp[i][j]=ans;
    return ans;
   
}
int main()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            dp[i][j]=-1;
        }
    }
    cin>>s1>>s2;
    int ans = LCS(0,0);
    cout<<"Length of LCS is : ";
    cout<<ans<<endl;
}