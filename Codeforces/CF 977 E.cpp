#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define MX 200005

using namespace std;

bool vis[MX], hap[MX];
vector<int> v[MX];
int deg[MX];

int main()
{
    int n, m, i, j, sz, cur, cnt, u, uu, st, tt;

    mm(deg,0);
    cin >> n >> m;
    ffr(i,0,m)
    {
        cin >> u >> uu;
        v[u].pb(uu);
        v[uu].pb(u);
        deg[u]++;
        deg[uu]++;
    }
    ffrr(i,1,n)
    {
        if(deg[i]==0) vis[i]=1;
        else if(deg[i]==1)
        {
            vis[i]=1;
            //deg[v[i][0]]--;
            //if(deg[v[i][0]]<2)
            vis[v[i][0]]=1;
        }
        else if(deg[i]>2)
        {
            sz=v[i].size();
            ffr(j,0,sz)
            {

                //deg[v[i][j]]--;
                //if(deg[v[i][j]]<2)
                vis[v[i][j]]=1;
            }
            vis[i]=1;
        }
    }

    cnt=0;
    ffrr(i,1,n)
    {
        if(vis[i]) continue;
        cur=i;
        st=i;
        vis[cur]=1;
        while(1)
        {
            sz=v[cur].size();
            ffr(j,0,sz)
            {
                if(!vis[v[cur][j]])
                {
                    if(st==cur) tt=v[cur][j];
                    cur=v[cur][j];
                    vis[cur]=1;

                    //hap[cur]=1;
                    break;
                }
            }
            if(j==sz)
            {
                if(cur!=st && cur!=tt)// && hap[cur])
                {
                    //cout << cur << endl;
                    sz=v[cur].size();
                    ffr(j,0,sz)
                    {
                        if(v[cur][j]==st) break;
                    }
                    if(j<sz)
                    cnt++;
                }
                break;
            }
        }
    }

    cout << cnt << endl;
}
