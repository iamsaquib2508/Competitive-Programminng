#include <bits/stdc++.h>
#define ll long long int
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
using namespace std;

ll mod = 1000000007;

ll bm(ll x, ll y)
{
    ll res = 1;
    if(x==1) return 1ll;
    while (y > 0)
    {
        if (y & 1)
            {res*=x; if(res>=mod) res%=mod;}

        y>>=1;
        x = (x*x)%mod;
    }
    return res;
}

ll maxx(ll a, ll b)
{
    if(a>b) return a; return b;
}

ll  a[1000006];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt; cin >> tt;
    ll n, p, i, k, ans, need, temp, lim, limp;
    ll curi, previ, pp[25];
    while(tt--)
    {
        cin >> n >> p;
        map<ll,ll> mp; mp.clear();
        ffr(i,0,n)
        {
            cin >> k;

            mp[-k]++;
        }
        if(p==1)
        {
            cout << n%2 << endl; continue;
        }
        need=0;
        for(lim=0,limp=1;limp<n;lim++,limp*=p)
        {
            pp[lim]=limp;
        }

        //for(i=maxxx;i>=0;i--)
        map<ll,ll>::iterator jt;
        for(jt=mp.begin();jt!=mp.end();jt++)
        {

            curi=-jt->first;
            temp=jt->second;
            //if(temp==0) continue;
            //cout << curi << endl;
            if(need==0)
            {
                need=temp&1;
            }
            else
            {
                if(previ-curi>=lim)
                    {jt--; break;}

                need*=pp[previ-curi];
                if(temp>=need)
                {
                    temp-=need;
                    need=temp&1;
                }
                else
                    need-=temp;
            }
            previ=curi;
            if(need>n) break;
        }
        //if(need>n)
        ans= (bm(p,previ)*(need)%mod)%mod;
        if(jt!=mp.end())
        {
            //cout << ans << endl;
            for(jt++;jt!=mp.end();jt++)
            {
                curi=-jt->first;
                temp=jt->second;
                if(temp>0)
                {
                    ans -= (bm(p,curi)*temp)%mod;
                    if(ans<0) ans+=mod;
                    //cout << ans << endl;
                }
            }
        }
        cout << ans << endl;
    }
}
