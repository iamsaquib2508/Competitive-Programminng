#include<bits/stdc++.h>
#define pb push_back
#define pf push_front
#define mp make_pair
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define ff first
#define ss second
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))

using namespace std;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

char g[23][23];
int cl, r;

int bfs(pii s)
{
    pii t;
    int i;
    int ans=0;
    int d[20][20];
    mm(d,0);
    bool vis[22][22];
    mm(vis,0);
    queue< pii > q;
    q.push(s);
    d[s.ss][s.ff]=0;
    vis[s.ss][s.ff]=1;
    while( !q.empty() )
    {
        t=q.front();
        q.pop();

        ffr(i,0,4)
        {
            pii p;
            p.ss=t.ss+dy[i];
            p.ff=t.ff+dx[i];
            int x=p.ff, y=p.ss;
            if(x<0 || y<0 || x==cl || y==r || g[y][x]=='#' || g[y][x]=='m') continue;
            if(vis[y][x]==0)
            {
                vis[y][x]=1;
                d[y][x]=d[t.ss][t.ff]+1;
                if(g[y][x]=='h') return d[y][x];
                q.push(p);

            }
        }
    }
}

int main()
{
    int cc=1,T;
    int i, j, ans;
    pii sra, srb, src;
    cin >> T;
    while(T--)
    {
        mm(g,0);
        cin >> r >> cl;
        ffr(i,0,r)
        {
            scanf("%s", g[i]);
            ffr(j,0,cl)
            if(g[i][j]=='a') sra.ff=j, sra.ss=i;
            else if(g[i][j]=='b') srb.ff=j, srb.ss=i;
            else if(g[i][j]=='c') src.ff=j, src.ss=i;
        }

        ans=max(max(bfs(sra),bfs(srb)),bfs(src));


        cout << "Case " << cc++ << ": " << ans << endl;
    }
    return 0;
}
