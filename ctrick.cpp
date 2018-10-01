//counting zero and kth zero
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sync ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD  1000000007 
#define lld long long
lld powm(lld base,lld exp,lld mod=MOD) {lld ans=1;while(exp){if(exp&1) ans=(ans*base)%mod;exp>>=1,base=(base*base)%mod;}return ans;}
int tree[100000],arr[100000];
void build(int root,int a,int b)
{
	if(a>b) return ;
	if(a==b)
	{
		if(arr[a]==0)
			tree[root]=1;
		else
			tree[root]=0;
		return;
	}
	int mid=(a+b)/2;
	build(root*2,a,mid);
	build(root*2+1,mid+1,b);
	tree[root]=tree[root*2]+tree[root*2+1];
}
void update(int node,int a,int b,int pos,int value)
{
	if(a==b)
	{
       if(value==0)
       	tree[node]=1;
       else
       	tree[node]=0;
       return ;
	}
	int mid=(a+b)/2;
	if(pos<=mid)
	update(node*2,a,mid,pos,value);
    else
	update(node*2+1,mid+1,b,pos,value);
	tree[node]=tree[node*2]+tree[node*2+1];
}
int kthindex(int node,int a,int b,int k)
{
	if(k>tree[node])
		return -1;
	if(a==b)
		return a;
	int mid=(a+b)/2;
	if(tree[node*2]>=k)
		return kthindex(node*2,a,mid,k);
	else
		return kthindex(node*2+1,mid+1,b,k-tree[node*2]);
}
int beforezero(int x)
{
	int count=0;
	for(int i=1;i<x;i++)
		if(arr[i]==0)
			count++;
	return count;
}
int32_t main()
{
	sync
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		memset(arr,0,sizeof(arr));
		build(1,1,n);
		int pos=0;
		int zero=n;
        for(int i=1;i<=n;i++)
        {
        	int k=(beforezero(pos)+i+1)%zero;
        	if(k==0)
        		k+=zero;
        	//cout<<k<<" ";
        	int index=kthindex(1,1,n,k);
        	//cout<<index<<endl;
        	arr[index]=i;
        	update(1,1,n,index,i);
        	pos=index;
        	zero--;
        }
        for(int i=1;i<=n;i++)
        	cout<<arr[i]<<" ";
        cout<<endl;
	}
}
