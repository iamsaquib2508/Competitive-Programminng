#include <bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define ll long long int
#define plolo pair<ll,ll>
#define ind first
#define id second
#define mp make_pair
#define pb push_back

using namespace std;

ll maxx(ll a, ll b){
    if(a>b) return a; return b;
}

ll minn(ll a, ll b){
    if(a<b) return a; return b;
}

ll abss(ll a, ll b){
    if(a>b) return a-b;
    else return b-a;
}

ll gcd(ll a, ll b){
    if(b==0) return a; return gcd(b, a%b);
}

ll ans[1000006];
ll lc[100];
ll xtra[100];

ll nmax = 100000000000000000;

void fff(){
    ll cur = 2;
    ll lcpast = 1;
    lc[1] = 1;
    ans[1] = 2;
    while(lcpast <= nmax){
        ll g = gcd(cur, lcpast);
        ll extra = cur / g;
        xtra[cur] = extra - 1;
        lcpast *= extra;
        lc[cur] = lcpast;
        cur++;
    }
    // cout << cur << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    fff();
    int i;
    // ffr(i,1,43) cout << lc[i] << ' '; cout << endl;
    // ffr(i,1,43) cout << xtra[i] << ' '; cout << endl;
    ll mod = 1000000007;
    int cc=1, tt = 1;
    cin >> tt;
    while(tt--){
        int cur = 2;
        ll n, lcpast = 1, ans = 0;
        cin >> n;
        while(lc[cur - 1] <= n){
            ll temp = n / lc[cur] * xtra[cur];
            ll rem = n % lc[cur];
            temp += rem / lc[cur - 1];
            temp %= mod;
            ll tempans = (temp * cur) % mod;
            ans += tempans;
            if(ans >= mod) ans -= mod;
            cur++;
            // cout << tempans << ' ' << cur << endl;
        }
        cout << ans << endl;
    }
    return 0;
}