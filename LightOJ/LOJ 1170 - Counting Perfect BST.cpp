#include <bits/stdc++.h>
#define ll uint64_t
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back

using namespace std;

set<ll> ans;
vector<ll> v;

ll MOD=100000007, fac[204462];

ll bm(ll x, ll n)
{
    ll res=1ll;
    while(n)
    {
        if(n&1) {res*=x; if(res>=MOD) res%=MOD;}
        x*=x; if(x>=MOD) x%=MOD;
        n>>=1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    //seive(100001);
    ll MAXX=10000000000, a, p;
    ans.clear();
    for(p=2;p<100002;p++) {
        a=p*p;
        while(a<=MAXX){
            ans.insert(a);
            a*=p;
        }
    }
    //cout << ans.size() << endl;
    for(ll p:ans) v.pb(p);
    ll fact=1;
    fac[1]=1;
    for(p=2;p<204462;p++){
        fact*=p; if(fact>=MOD) fact%=MOD;
        fac[p]=fact;
    }

    int tt, cc=1; cin >> tt;
    while(tt--)
    {
        ll a, b, lo, hi, n;
        cin >> a >> b;
        vector<ll>::iterator it;
        it=lower_bound(v.begin(),v.end(),a);
        lo=it-v.begin();
        hi=upper_bound(it,v.end(),b)-v.begin();
        //cout << hi-lo << endl;
        n=hi-lo;
        ll prin;
        if(n<3) prin=n;
        else prin=fac[n+n]*bm(fac[n],MOD-2)%MOD*bm(fac[n+1],MOD-2)%MOD;
        cout << "Case " << cc++ << ": " << prin << endl;
    }
}
