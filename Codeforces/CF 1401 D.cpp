#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mkm make_pair
#define MMAX 200005
#define bug() cout << "hello\n"

using namespace std;

int minn(int a, int b)
{
    if(a<b) return a; return b;
}

vector<ll> edgcnt;
vector<ll> v[100005];
ll n;

ll dfs(ll s, ll par=-1){
    if(v[s].size()==1 && par!=-1){
        edgcnt.pb(n-1);
        return 1;
    }
    int i, sz=v[s].size();
    ll sum=0;
    ffr(i,0,sz){
        if(v[s][i]==par) continue;
        sum+=dfs(v[s][i], s);
    }
    if(par!=-1) edgcnt.pb((sum+1)*(n-sum-1));
    return sum+1;
}

int main(){
    int tt;
    cin >> tt;
    ll m, mod=1000000007;
    while(cin >> n){
        ll i, uu, vv;

        edgcnt.clear();
        ffr(i,0,100005) v[i].clear();


        ffr(i,1,n){
            cin >> uu >> vv;
            v[uu].pb(vv);
            v[vv].pb(uu);
        }
        cin >> m;
        vector<ll> p; p.clear();
        ffr(i,0,m){
            cin >> uu;
            p.pb(uu);
        }
        sort(p.rbegin(),p.rend());
        dfs(1,-1);
        sort(edgcnt.rbegin(),edgcnt.rend());
        while(m<n-1) {p.pb(1); m++;}
        ll extra = m-(n-1);
        ffr(i,0,extra){
            p[i+1]*=p[i];
            p[i+1]%=mod;
        }
        ll ans=0;
        //assert()
        ffr(i,extra,m){
            ans += (p[i]*(edgcnt[i-extra]%mod)%mod);
            if(ans>=mod) ans-=mod;
        }
        cout << ans << endl;
    }
}
