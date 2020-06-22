#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define MMAX 200005

using namespace std;

ll maxx(ll a, ll b)
{
    if(a>b) return a; return b;
}

ll minn(ll a, ll b)
{
    if(a<b) return a; return b;
}

ll n, k;
bool ok(ll x)
{
    ll large, smol, cnt=0, sz;
    if(x&1)
    {
        //odd
        large=x;
        sz=1;
        while(1)
        {
            if(large>n) break;
            cnt+=sz;

            sz+=sz;
            large+=large; large++;
        }
        smol=large-sz+1;
        cnt+=(maxx(0,n-smol+1));
        //cout << x << " x cnt " << cnt << endl;
        return cnt>=k;
    }
    else
    {
        //even
        large=x+1;
        sz=2;
        while(1)
        {
            if(large>n) break;
            cnt+=sz;

            sz+=sz;
            large+=large; large++;
        }
        smol=large-sz+1;
        cnt+=(maxx(0,n-smol+1));
        //cout << x << " x cnt " << cnt << endl;
        return cnt>=k ;
    }
}

int main()
{
    while(cin >> n >> k)
    {
        ll lo, hi, mid, ans;
        if(n==k) cout << "1\n";
        else
        {
            lo=2; hi=n-(n&1);
            while(hi-lo>2)
            {
                mid=(lo+hi)/2;
                mid-=(mid&1);
                if(ok(mid)) lo=mid;
                else hi=mid;
            }
            if(ok(hi)) ans=hi; else ans=lo;
            if(ok(ans+1)) ans++;
            cout << ans << endl;
        }
    }
}
