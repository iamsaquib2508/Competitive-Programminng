#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int

using namespace std;

ll a[200005];
ll n;

ll ff(ll x)
{
    ll lo=0, hi=n;
    ll mid;
    while(hi-lo>1)
    {
        mid=(hi+lo)/2;
        if(a[mid]<=x) lo=mid;
        else if(x<a[mid]) hi=mid;
    }
    if(a[hi]==x) return hi;
    return lo;
}

int main()
{
    while(cin >> n)
    {
        ll i, ans=0;
        ffr(i,0,n) cin >> a[i];
        sort(a,a+n);

        ffr(i,0,n)
        {
            ans=max(ff(a[i]+5)-i+1,ans);
        }
        cout << ans << endl;
    }

}
