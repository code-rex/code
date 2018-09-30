//Segment tree
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sync ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD  1000000007 
#define lld long long
lld powm(lld base,lld exp,lld mod=MOD) {lld ans=1;while(exp){if(exp&1) ans=(ans*base)%mod;exp>>=1,base=(base*base)%mod;}return ans;}
int n;
int arr[500001],tree[500001];
void build_tree(int node,int a,int b)
{
	if(a>b) return;
	if(a==b)
	{
		tree[node]=arr[a];
		return ;
	}
	build_tree(node*2,a,(a+b)/2);
	build_tree(node*2+1,1+(a+b)/2,b);
	tree[node]=min(tree[node*2],tree[node*2+1]);
}
int query_tree(int node,int a,int b,int i,int j)
{
	if(a>b||a>j||b<i)    return 1000000001;
	if(a>=i&&b<=j)    return tree[node];
	int q1=query_tree(node*2,a,(a+b)/2,i,j);
	int q2=query_tree(node*2+1,1+(a+b)/2,b,i,j);
	return min(q1,q2);
}
void update_tree(int node,int a,int b,int i,int j,int value)
{
     if(a>b||a>j||b<i)    return;
     if(a==b) 
     {
     	tree[node]+=value;
     	return ;
     }
     update_tree(node*2,a,(a+b)/2,i,j,value);
     update_tree(node*2+1,(a+b)/2,b,i,j,value);
     tree[node]=min(tree[node*2],tree[node*2+1]);
}
int32_t main()
{
	 sync
     int t;
     cin>>t;
     int z=1;
     while(t--)
     {
     	int q;
     	cin>>n>>q;
     	for(int i=0;i<n;i++)
     		cin>>arr[i];
     	build_tree(1,0,n-1);
     	cout<<"Scenario #"<<z<<":"<<endl;
        while(q--)
        {
        	int l,r;
        	cin>>l>>r;
        	cout<<query_tree(1,0,n-1,l-1,r-1)<<endl;
        }
        z++;
     }
}
