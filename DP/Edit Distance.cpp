#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sync ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD  1000000007 
int powm(int base,int exp,int mod=MOD) {int ans=1;while(exp){if(exp&1) ans=(ans*base)%mod;exp>>=1,base=(base*base)%mod;}return ans;}
int solve(vector<vector<int>>&dp,string &s,string &t,int n,int m)
{
	if(n==0)
		return m;
	if(m==0)
		return n;
	if(dp[n][m]!=-1)
		return dp[n][m];
	if(s[n-1]==t[m-1])
		return dp[n][m]=solve(dp,s,t,n-1,m-1);
	else
	{
		return dp[n][m] = 1+min(solve(dp,s,t,n-1,m),min(solve(dp,s,t,n-1,m-1),solve(dp,s,t,n,m-1)));
	}
}
int32_t main()
{
	sync
	int t;
	cin>>t;
	while(t--)
	{
		string a,b;
		cin>>a>>b;
		int n=a.length();
		int m=b.length();
		vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
		cout<<solve(dp,a,b,n,m)<<endl;
	}
}
