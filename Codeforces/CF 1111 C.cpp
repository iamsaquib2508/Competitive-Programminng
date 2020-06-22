#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int
#define mp make_pair

using namespace std;

map< pair<int,int> , int> mmp;

bool vis[100005];

vector<int> vec[100005];

int bfs(int s)
{
    int ans=1;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        vis[cur]=1;
        int i, sz=vec[cur].size();
        ffr(i,0,sz)
        {
            int next=vec[cur][i];
            if(vis[next]) continue;
            if(mmp[ mp( min(cur,next),max(cur,next) ) ]==1)
            {
                //bad edge
                continue;
            }
            else
            {
                q.push(next);
                ans++;
            }
        }
    }
    return ans;
}

ll mod=1000000007;

ll bm(ll a, ll p)
{
    if(p==0) return 1ll;
    ll x=bm(a,p/2);
    x=(x*x)%mod;
    if(p&1) x=(x*a)%mod;
    return x;
}

int main()
{
    int n, k;
    while(cin >> n >> k)
    {
        mm(vis,0);
        ll ans=0;
        mmp.clear();
        int i, u, v, x;
        ffr(i,0,100005)
        {
            vec[i].clear();
        }
        ffr(i,1,n)
        {
            cin >> u >> v >> x;
            vec[u].pb(v);
            vec[v].pb(u);
            if(v<u)
            {
                int ttt=v;
                v=u; u=ttt;
            }
            mmp[mp(u,v)]=x;
        }
        ffrr(i,1,n)
        {
            if(vis[i]) continue;
            int m=bfs(i);
            ans+=bm(m,k);
            ans%=mod;
        }
        ans=bm(n,k)-ans;
        while(ans>=mod) ans-=mod;
        while(ans<0)
        {
            ans+=mod;
        }
        cout << ans << endl;
    }
}
