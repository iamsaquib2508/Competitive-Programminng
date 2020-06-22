#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define mmxx 1e18
#define bug(x) ;//cerr << #x << " = " << x << endl

using namespace std;

ll maxx(ll a, ll b)
{
    if(a>b) return a; return b;
}


int main()
{
    int tt; cin >> tt;
    while(tt--)
    {
        ll n, d, mx, i, ans, x;
        map<ll,ll> mp; mp.clear();

        cin >> n >> d;
        mx=0;
        ffr(i,0,n)
        {
            cin >> x;
            mp[x]=1;
            mx=maxx(mx,x);
        }

        if(d<mx)
        {
            if(mp[d]==1) ans=1;
            else ans=2;
        }
        else ans=d/mx+((d%mx)>0);
        cout << ans << endl;

    }
}
