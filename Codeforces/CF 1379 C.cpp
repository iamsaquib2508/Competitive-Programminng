#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pii pair<ll,ll>
#define mp(a,b) make_pair(a,b)
#define mmxx 1e18
#define bug(x) cerr << #x << " = " << x << endl

using namespace std;

ll maxx(ll a, ll b)
{
    if(a>b) return a; return b;
}

bool cmp1(pii a, pii b){
    return a.first>b.first;
}

int n;

bool cmp2(pii p, pii q){
    return p.first+(n-1)*p.second > q.first+(n-1)*q.second;
}

int main(){
    int tt; cin >> tt;
    while(tt--){
        int m;
        cin >> n >> m;
        vector< pii > v;
        v.clear();
        int i;
        ll aa, bb, bmax=0, bmax2=0, ai;
        ffr(i,0,m){
            cin >> aa >> bb;
            v.pb(mp(aa,bb));
            bmax=maxx(bb,bmax);
        }
        sort(v.begin(),v.end(),cmp1);
        ll ans=0;
        ffr(i,0,m){
            if(!n) break;
            ai = v[i].first;
            if( ai>=bmax ){
                ans += ai;
                n--;
                bmax2 = maxx(bmax2, v[i].second);
            }
            else break;
        }
        if(n>0 && i<m){
            sort(v.begin()+i,v.end(),cmp2);
            ans += (maxx(n*bmax2,v[i].first+(n-1)*v[i].second));
        }
        else ans += n*bmax2;
        cout << ans << endl;
    }
    cin >> tt;
}
