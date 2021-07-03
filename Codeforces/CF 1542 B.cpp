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
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int cc=1, tt = 1;
    cin >> tt;
    while(tt--){
        ll n, a, b;
        cin >> n >> a >> b;
        ll poww = 1;
        if(a > 1)
        while(poww <= n){
            ll rem = n - poww;
            if(rem % b == 0) break;
            poww *= a;
        }
        else{
            ll rem = n - 1;
            if(rem % b != 0) poww = n + 1;
        }
        if(poww <= n) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}