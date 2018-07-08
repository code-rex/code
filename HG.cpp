//HUGE GCD SPOJ
#include<bits/stdc++.h>
using namespace std;
int mod=pow(10,9);
vector<int>first;
vector<int>second;
/*long long gcd(long long a,long long b)
{
    if(a==0)
        return b;
    else
        return gcd(b%a,a);
}
bool primechecker(int n)
{
    if(n==1)
        return false;
    if(n<=3)
        return true;
    if(n%2==0||n%3==0)
        return false;
    for(int i=5;i*i<=n;i+=6)
    {
        if(n%i==0||n%(i+2)==0)
            return false;
    }
    return true;
}*/
vector<int> primefactor(int n,vector<int>vector)
{
    while(n%2==0)
    {
        vector.push_back(2);
        n=n/2;
    }
    for(int i=3;i*i<=n;i+=2)
    {
        while(n%i==0)
            {
                vector.push_back(i);
                n=n/i;
            }
    }
    if(n>2)
        vector.push_back(n);
    return vector;
}
int main()
{
    int m;
    scanf("%d",&m);
    int a[m];
    for(int i=0;i<m;i++)
        scanf("%d",&a[i]);
    int n;
    scanf("%d",&n);
    int b[n];
    for(int i=0;i<n;i++)
        scanf("%d",&b[i]);
    long long p=1,q=1;
    for(int i=0;i<m;i++)
    {
        //if(primechecker(a[i])==true)
          //  first.push_back(a[i]);
       // else
           first=primefactor(a[i],first);
    }
    for(int i=0;i<n;i++)
    {
       // if(primechecker(b[i])==true)
         //   second.push_back(b[i]);
       // else
            second=primefactor(b[i],second);
    }
    sort(first.begin(),first.end());
    sort(second.begin(),second.end());
    vector<int>ans;
    set_intersection(first.begin(),first.end(),second.begin(),second.end(),back_inserter(ans));
    unsigned long long int z=1;
    int flag=0;
    for(int i=0;i<ans.size();i++){
        z=(z*ans[i]);
    if(z>pow(10,9)){
          flag=1;
          z=z%mod;
    }
    }
    if(flag==0)
        cout<<z;
    else if(z>100000000&&z<999999999)
        cout<<z;
    else
    {
        unsigned long long ans=z;
        int digit=0;
        while(ans)
        {
            digit++;
            ans=ans/10;
        }
        for(int i=0;i<(9-digit);i++)
            cout<<"0";
        cout<<z;
    }
    return 0;
}
