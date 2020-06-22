




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

vector<int> v[1003];

void bfs(int s, int *d)
{
    
    d[s]=0;
    int cur, u, sz, i;
    queue<int> q; q.push(s);
    
    while(!q.empty())
    {
        cur=q.front(); q.pop();
        
        sz=v[cur].size();
        ffr(i,0,sz)
        {
            u=v[cur][i];
            if(d[u]==-1 || d[u]>d[cur]+1)
            {
                d[u]=d[cur]+1;
                q.push(u);
            }
            else continue;
        }
    }
    
    return;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, s, t, i, j, u, uu, target, ds[1003], dt[1003], ans=0;
    
    bool arr[1003][1003];
    mm(arr,0);
    
    cin >> n >> m >> s >> t;
    ffr(i, 0, m)
    {
        cin >> u >> uu;
        arr[u][uu]=1;
        arr[uu][u]=1;
        
        v[u].pb(uu);
        v[uu].pb(u);
    }
    
    mm(ds,-1); mm(dt,-1);
    
    bfs(s, ds);
    bfs(t, dt);
    
    //ffr(i,1,6) cout << ds[i] << " "; cout << endl;
    //ffr(i,1,6) cout << dt[i] << " "; cout << endl;
    
    if(ds[t]==-1) target= 1003;
    else target=ds[t];
    
    
    ffrr(i,1,n)
    {
        ffrr(j,i+1,n)
        {
            if(arr[i][j]) continue;
            int tt=min(ds[i]+dt[j]+1, ds[j]+dt[i]+1);
            if(tt>=target) ans++;
        }
    }
    
    cout << ans << endl;
    //fix size
    return 0;
}
