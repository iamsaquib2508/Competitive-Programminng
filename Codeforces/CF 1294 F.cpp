



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

vector<int> path, v[200005];
int a, b, c;
int ans, bestdepth;
bool vis[200005];

void dfs(int s, int par=-1, int depth=0){
    int sz=v[s].size();
    vis[s]=1;
    if(sz==1 && par==v[s][0]){
        if(depth > bestdepth){
            bestdepth = depth;
            a = s;
        }
    }
    else{
        for(int u: v[s]){
            if(u!=par && !vis[u]){
                dfs(u,s,depth+1);
            }
        }
    }
}

bool dfspath(int s, int par=-1){
    if(s==b){
        return true;
    }
    int sz=v[s].size();
    vis[s]=1;

    if(sz==1 && par==v[s][0]){
        return false;
    }
    else{
        for(int u: v[s]){
            if(u!=par && !vis[u]){
                bool found = dfspath(u,s);
                if( found ){
                    path.pb(s);
                    return true;
                }
            }
        }
    }
    //never comes here
    return false;
}

void bfs(){
    queue<int> q;
    int dis[200005];
    mm(vis,0);
    for(int aa:path){
        q.push(aa); dis[aa]=0;
        vis[aa]=1;
    }

    int s;
    vis[a]=1; vis[b]=1;
    while(!q.empty()){
        s=q.front(); q.pop();

        for(int u: v[s]){
            if(!vis[u]){
                vis[u]=1;
                dis[u]=dis[s]+1;
                q.push(u);
            }
        }
    }
    c=s;
    //cout << dis[c] << " disc\n";
    ans += dis[c];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    while(cin >> n){
        int i, u, uu, sz;
        ffr(i,0,200005) v[i].clear();

        ffr(i,1,n)
        {
            cin >> u >> uu;
            v[u].pb(uu);
            v[uu].pb(u);
        }
        mm(vis,0); bestdepth = 0; dfs(1); b=a;
        mm(vis,0); bestdepth = 0; dfs(b);

        if(bestdepth==n-1){
           //any c
           ans = n-1;
           ffrr(i,1,n)
               if(i!=a && i!=b) {c=i; break;}
        }
        else{
            path.clear();
            mm(vis,0); dfspath(a);
            path.pop_back();
            ans = bestdepth;
            bfs();
        }
        cout << ans << endl;
        cout << a << ' ' << b << ' ' << c << endl;
    }

    return 0;
}
