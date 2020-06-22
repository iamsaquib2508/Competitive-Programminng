#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int
#define pf printf

using namespace std;

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

ll minn(ll a, ll b)
{
    if(a<b) return a; return b;
}

vector<int> g[1003];
int done[1003];
bool vis[1003];

void dfs(int ss)
{

    int i, sz=g[ss].size();
    vis[ss]=true;
    ffr(i,0,sz)
    {
        int t=g[ss][i];
        if(!vis[t]) dfs(t);
    }
    done[ss]++;
}

int main()
{
    int t, cc=1; scanf("%d", &t);
    while(t--)
    {
        int i, ans=0, k, m, n, uu, vv;
        int kk[100];
        ffr(i,0,1003) {g[i].clear(); done[i]=0;}

        scanf("%d %d %d", &k, &n, &m);
        ffr(i,0,k) scanf("%d", &kk[i]);
        ffr(i,0,m)
        {
            scanf("%d %d", &uu, &vv);
            g[uu].pb(vv);
        }
        ffr(i,0,k) { mm(vis,0); dfs(kk[i]);}
        ffrr(i,1,n) if(done[i]==k) ans++;
        pf("Case %d: %d\n", cc++, ans);
    }
}
