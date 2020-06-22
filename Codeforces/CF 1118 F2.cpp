#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define nmax 300003

using namespace std;

int gcd(int a, int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int minn(int a, int b)
{
    if(a<b) return a; return b;
}

ll mod=998244353;

bool vis[nmax];
vector<ll> v[nmax];
ll col[nmax];
vector<ll> xcold[nmax];
vector<ll> curset;
ll cursum;

bool dfs(int s, int color, int par=-1) //source, color
{
    //cout << s << endl;
    ll sz=v[s].size(), i;
    bool found=0;
    //vis[s]=1;
    for(ll u: v[s])
    {
        if(u==par) continue;

        if(col[u]==color) found=1;
        else if(!col[u]) found|=dfs(u,color,s);
        //else ??
    }
    if(found) col[s]=color;
    return found;

}

void dfs2(ll s)
{
    ll sz=v[s].size(), i, got=0;
    vis[s]=1;
    for(ll u:v[s])
    {
        if(vis[u]) continue;
        if(col[u]) got++;
        else dfs2(u);

    }
    if(got==0) return;
    curset.pb(got);
    cursum+=got;
}

int main()
{
    ll n, k;

    while(cin >> n >> k)
    {
        ll ans;
        ll x, i, u, uu;
        ffrr(i,1,n)
        {
            cin >> x;
            col[i]=x;
            xcold[x].pb(i);
        }
        ffr(i,1,n)
        {
            cin >> u >> uu;
            v[u].pb(uu);
            v[uu].pb(u);
        }
        bool found;
        memset(vis,0,sizeof(vis));
        ffrr(i,1,k)
        {
            while(xcold[i].size()>1)
            {
                found=dfs(xcold[i].back(), i); //lit all that has color i
                xcold[i].pop_back();
                //cout << found;
                if(!found) break;
            }
        }
        if(!found)
        {
            ans=0; //cout << "allare ";
        }
        else
        {
            memset(vis,0,sizeof(vis));
            ans=1;
            ffrr(i,1,n)
            {
                if(col[i]==0 && !vis[i])
                {
                    //cout << i << endl;
                    //make set and compute
                    curset.clear(); cursum=0;
                    dfs2(i);
                    ll thisprod=cursum;
                    for(int a: curset)
                    {
                        //cout << a << ' ';
                        thisprod+=(cursum-a)*a;
                        if(thisprod>mod) thisprod%=mod;
                    }
                    //if(thisprod==0) thisprod=cursum;
                    //cout << endl << thisprod << endl;
                    ans*=thisprod; ans%=mod;
                }
            }
        }
        cout << ans << "\n";
        ffr(i,1,nmax) {v[i].clear(); xcold[i].clear();}
        mm(col,0);
    }
    return 0;
}

/*
16 4
1 0 1 1 0 2 2 0 3 3 0 4 0 4 0 0
1 2
3 2
2 4
4 5
6 8
6 7
9 10
10 11
11 12
12 13
13 14
12 15
15 16
5 16
8 16
*/

// Need help with the following problem.
// https://codeforces.com/contest/1118/problem/F2
// What I've done:
// 1. For every color, tried to build k same-colored subtrees. If not possible (collision occurs), the answer is trivially 0.
// 2. for simplicity, let's call uncolored vertices as black vertices. when an answer exists, there will be many (possibly 0) subtrees induced by black vertices, whose leaves will have many colored components(sub-trees) adjacent to them. let's call the set of these colored component/sub-trees S_T. Instead of cutting k-1 edges, I tried to color the black vertices in a way such that
// a. only the trees in S_T get larger
// b. no new subtrees form.
// c. all the vertices get colored.
// Clearly, doing step 2 for all the black sub-trees will lead us to the result. the answer will be the product of count(coloring one black component).
// All I need is to find a way to count the colorings of one black component. It should be an easy DP but somehow I'm failing to grasp it. Any help is welcome. Thanks.
