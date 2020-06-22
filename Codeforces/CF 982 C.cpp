




/*  ***************************           DONATE BLOOD, SAVE LIFE!               ********************************  */




#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define ld long double
#define pb push_back
#define pii pair<int,int>
#define plolo pair<ll,ll>
#define mm(a,b) memset(a,b,sizeof(a))
#define pf printf
#define xx first
#define yy second
#define PI acos(-1.0)
#define mp make_pair

using namespace std;



/*  ***************************           DONATE BLOOD, SAVE LIFE!               ********************************  */
#define NN 100005

bool vis[NN];
vector<int> sorted;
vector<int> v[NN];

void dfs(int s)
{
    int i, sz=v[s].size(), u;
    vis[s]=true;

    ffr(i,0,sz)
    {
        u=v[s][i];
        if(!vis[u])
        dfs(u);
    }
    sorted.pb(s);
    return;
}

int deg[NN];

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    int i, n, sz, u, uu, cnt, next, xxx, j;
    cin >> n;
    ffr(i,1,n)
    {
        cin >> u >> uu;
        v[u].pb(uu);
        v[uu].pb(u);
        deg[i]=1;
    }
    deg[n]=1;

    mm(vis,0);
    sorted.clear();
    dfs(1);
    xxx=n-1;
    cnt=0;
    mm(vis,0);

    ffr(i,0,xxx)
    {
        u=sorted[i];
        //cout << u << "u show" <<endl;
        vis[u]=true;
        sz=v[u].size();
        ffr(j,0,sz)
        {
            uu=v[u][j];
            if(!vis[uu]) { next=uu; break;}
        }
        if(deg[u]&1)
        {
            deg[next]++;
        }
        else
        {
            cnt++;
        }
    }
    //ffrr(i,1,n) cout << i << " has deg " << deg[i] << "\n";
    if(deg[sorted[xxx]]&1)
    {
        cnt=-1;
    }

    cout << cnt << '\n';


    return 0;
}
