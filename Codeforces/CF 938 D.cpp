




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
#define MX 200005

void dx(pii src)
{
    priority_queue< pii > q; //xx ans, yy node no
    q.push(src);
    while(!q.empty())
    {
        cur=q.top();
        q.pop();
        if(vis[cur.yy]) continue;
        tempans=cur.xx;
        sz=v[cur.yy].size();
        ffr(i,0,sz)
        {
            next=v[cur.yy][i];
            tt=next.xx*2+cst[next.yy];
            pq.push(mp(next.yy,tt));
        }
        ans[cur.yy]=cur.xx;
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout.tie(NULL);
    
    mm(vis,0);
    cin >> n >> m;
    ffr(i,0,m)
    {
        cin >> u >> uu >> w;
        v[u].pb(mp(w,uu));
        v[uu].pb(mp(w,u));
    }
    ffrr(i,1,n)
    {
        //cin >> cst[i];
        cin >> cst[i];
        rtd.pb(mp(cst[i],i));
    }
    sort(rtd);
    ffrr(i,1,n)
    {
        if(!vis[i])
        {
            start(rtd[i]);
        }
    }


    //fix size
    return 0;
}
