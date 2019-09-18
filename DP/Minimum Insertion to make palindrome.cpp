#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sync ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD  1000000007 
int powm(int base,int exp,int mod=MOD) {int ans=1;while(exp){if(exp&1) ans=(ans*base)%mod;exp>>=1,base=(base*base)%mod;}return ans;}
int solve(vector<vector<int>>&dp,string &s,int n,int m)
{
	if(dp[n][m]!=-1)
		return dp[n][m];
	if(n==m)
		return 0;
	if(n>m)
		return INT_MAX;
	if(n==m-1)	return (s[n]==s[m]?0:1);
	if(s[n]==s[m])	return dp[n][m]=solve(dp,s,n+1,m-1);
	else 			return dp[n][m]=1+min(solve(dp,s,n,m-1),solve(dp,s,n+1,m));
}
int32_t main()
{
	sync
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int n=s.length();
		vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
		cout<<solve(dp,s,0,n-1)<<endl;
	}

}
