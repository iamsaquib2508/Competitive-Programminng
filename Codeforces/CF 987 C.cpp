



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
#define inf 1e17

using namespace std;

class node
{
public:
    int id, v, c;
    node(){}
    node(int ii, int vv, int cc)
    {
        id=ii, v=vv; c=cc;
    }
};

bool cmp(node a , node b)
{
    return a.v<b.v || (a.v==b.v && a.id<b.id);
}

/*  ***************************           DONATE BLOOD, SAVE LIFE!               ********************************  */

int n;
node a[3002];

ll dp[3002][3][3002];

ll call(int pos, int hoi, int lastind)
{


    if(hoi==3) return 0;
    if(pos==n)
    {
        return inf;
    }
    if(lastind>=0 && dp[pos][hoi][lastind]!=-1) return dp[pos][hoi][lastind];
    ll p=call(pos+1,hoi,lastind), p2=inf, ans;
    if(lastind==-1 || (a[pos].id>a[lastind].id && a[pos].v>a[lastind].v))
    p2=a[pos].c+call(pos+1,hoi+1,pos);
    ans=min(p,p2);
    if(lastind!=-1) dp[pos][hoi][lastind]=ans;
    
    return ans;
}


int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    cin >> n;
    int i, val[3002], cost[3002];
    mm(dp,-1);
    ffr(i,0,n)
    {
        cin >> val[i];
    }
    ffr(i,0,n)
    {
        cin >> cost[i];
    }
    ffr(i,0,n)
    {
        a[i]=node(i,val[i],cost[i]);
    }
    sort(a,a+n,cmp);
    ll ans=call(0,0,-1);
    if(ans>=inf) ans=-1;
    cout << ans << endl;

/*
5
5 4 6 8 2
3 4 7 6 5

2 4 5 6 8
5 4 3 7 6

    2 3
*/



    return 0;
}
