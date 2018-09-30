#include<bits/stdc++.h>
using namespace std;
#define int int 
#define sync ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD  1000000007 
#define lld long long
#define take(a) scanf("%d",&a);
lld powm(lld base,lld exp,lld mod=MOD) {lld ans=1;while(exp){if(exp&1) ans=(ans*base)%mod;exp>>=1,base=(base*base)%mod;}return ans;}
int sparse[100005][20],a[100025],n,q,l,r;
int32_t main()
{
   int t;  take(t) 
   for(int z=0;z<t;z++)
   {
   	   take(n) take(q)
   	   for(int i=0;i<n;i++) take(a[i])
   	   for(int i=0;i<n;i++)  sparse[i][0]=a[i];
   	   for(int j=1;(1<<j)<=n;j++)  //pow(2,j)=1<<j
   	   		for(int i=0;i+(1<<j)-1<=n;i++) 
   	   		  sparse[i][j]=min(sparse[i][j-1],sparse[i+(1<<(j-1))][j-1]);
        printf("Scenario #%d:\n", z+1);
        while(q--)
        {
            take(l) take(r) l--; r--;
            int k=31 - __builtin_clz(r - l + 1);;
            printf("%d\n", min(sparse[l][k],sparse[r+1-(1<<k)][k]));
        }
   }
}
