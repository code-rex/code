#include<bits/stdc++.h>
using namespace std;
int main()
{
    while(1)
    {
        string s;
        cin>>s;
        if(s[0]=='0')
            break;
        char c1,c2;
        int dp[s.length()+1];
        dp[0]=dp[1]=1;
        for(int i=2;i<=s.length();i++)
        {
            dp[i]=0;
            c1=s[i-2]-'0';
            c2=s[i-1]-'0';
            if(c1==1||(c1==2&&c2<=6))
                dp[i]+=dp[i-2];
            if(c2!=0)
                dp[i]+=dp[i-1];
        }
        cout<<dp[s.length()]<<endl;
    }
    return 0;
}
