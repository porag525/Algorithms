#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int LCS(int i,int j)
{
    if(s1.size()==i || s2.size()==j)
    {
        return 0;
    }
    if(s1[i]==s2[j])
    {
        return (1+LCS(i+1,j+1));
    }
    else
    {
        return max(LCS(i+1,j),LCS(i,j+1));
    }
}
int main()
{
    
    cin>>s1>>s2;
    int ans = LCS(0,0);
    cout<<"Length of LCS is : ";
    cout<<ans<<endl;
}