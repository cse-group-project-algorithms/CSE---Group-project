#include<map>
#include<iostream>
#include<vector>
#include<deque>
#define ll long long int
using namespace std;
ll x[1000006],h[1000006],c[1000006];
int reach[1000006];
deque<int> d;
int f(ll len,int n,int tid)
{
    ll tlen,c2;
    int i,k,i2;
    reach[0]=tid;
        for(i=1;i<n;i++)
        {
            while(!(d.empty()))
            {
                k=d.front();
                tlen=x[i]-x[k];
                tlen*=tlen;
                tlen+=((h[i]-h[k])*(h[i]-h[k]));
                if(tlen>len)
                {
                    d.pop_front();
                }
                else
                    break;
            }
            k=i-1;
            tlen=x[i]-x[k];
            tlen*=tlen;
            tlen+=((h[i]-h[k])*(h[i]-h[k]));
            if(reach[k]==tid && tlen<=len)
            {
                c2=c[k];
                while(!(d.empty()))
                {
                    i2=d.back();
                    if(c[i2]<=c2)
                        d.pop_back();
                    else
                        break;
                }
                d.push_back(k);
            }
            if(!(d.empty()))
            {
                k=d.front();
                if(h[i]-h[k]<x[i]-x[k])
                    reach[i]=tid;
            }
        }
        while(!(d.empty()))
            d.pop_back();
        if(reach[n-1]==tid)
        return 1;
        else
        return 0;
}
int main()
{
    pair<ll,ll> pr;
    int i,j,n,i2,k,tid;
    ll x2;
    x2=10000001;
    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>x[i]>>h[i];
        c[i]=x2-x[i];
        c[i]+=h[i];
    }

    tid=1;
    ll l,r,len,mid,tlen;
    l=0;
    r=h[n-1]-h[0];
    r*=r;
    r+=((x[n-1]-x[0])*(x[n-1]-x[0]));
    r++;
    while(l+1<r)
    {
        mid=(l+r)/2;
        mid=(l+r)/2;
        len=mid;

        if(f(len,n,tid)==1)
        {
            r=mid;
        }
        else
        {
            l=mid;
        }
        tid++;
    }
    ll ans;
    ans=-1;
    if(f(r,n,tid)==1)
        ans=r;
    tid++;
    if(f(l,n,tid)==1)
        ans=l;
    cout<<ans;
    return 0;
}
