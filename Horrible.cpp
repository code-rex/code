//Range sum query using lazy popagation
//Horrible Spoj 
#include<bits/stdc++.h>
using namespace std;
#define inf 0xc7844c
#define int long long
#define take(a) scanf("%lld",&a);
#define give(a) printf("%lld\n",a );
int arr[1000005],tree[1000005],lazy[1000005];
void buildtree(int node,int a,int b)
{
	if(a>b) return;
	if(a==b)
	{
		tree[node]=arr[a];
		return ;
	}
	buildtree(node*2,a,(a+b)/2);
	buildtree(1+node*2,1+(a+b)/2,b);
	tree[node]=tree[node*2]+tree[node*2+1];
}
void updatetree(int node,int a,int b,int i,int j,int value)
{
	if(lazy[node]!=0)
	{
		tree[node]+=(b-a+1)*lazy[node];  //For RMQ it is just lazy[node] in all the three Position instead of (b-a+1)*lazy[node]
		if(a!=b)
		{
			lazy[node*2]+=lazy[node];
			lazy[node*2+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(a>b||b<i||a>j)  return ;
	if(a>=i&&b<=j)
	{
		tree[node]+=(b-a+1)*value;
		if(a!=b)
		{
			lazy[node*2]+=value;
			lazy[node*2+1]+=value;
		}
		return ;
	}
	updatetree(node*2,a,(a+b)/2,i,j,value);
	updatetree(1+node*2,1+(a+b)/2,b,i,j,value);
	tree[node]=tree[node*2]+tree[node*2+1];
}
int querytree(int node,int a,int b,int i,int j)
{
	if(a>b||b<i||a>j)   return 0;
	if(lazy[node]!=0)
	{
		tree[node]+=(b-a+1)*lazy[node];
		if(a!=b)
		{
		    lazy[node*2]+=lazy[node];
			lazy[node*2+1]+=lazy[node];
		}
        lazy[node]=0;
	}
	if(a>=i&&b<=j)  return tree[node];
	int q1=querytree(node*2,a,(a+b)/2,i,j);
	int q2=querytree(1+node*2,1+(a+b)/2,b,i,j);
	int ans=q1+q2;
	return ans;
}
int32_t main()
{
    int t;
    take(t)
    while(t--)
    {
    	int n,q;
    	take(n) take(q)
    	memset(tree,0,sizeof tree);
    	memset(lazy,0,sizeof lazy);
    	memset(arr,0,sizeof arr);
    	buildtree(1,0,n-1);
    	while(q--)
    	{
    		int z,l,r,value;
    		take(z)
         	if(z==0)
    	    {
            take(l) take(r) take(value)
            updatetree(1,0,n-1,l-1,r-1,value);
    	   }
    	   if(z==1)
    	   {
    	   	take(l) take(r)
    	   	give(querytree(1,0,n-1,l-1,r-1))
    	   }
        }
    }  
	return 0;
}
