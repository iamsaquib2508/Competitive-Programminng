#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define pb push_back
#define ll long long int
#define pf printf

using namespace std;

class node
{
public:
    ll p, c, iden;
    node(){}
    node(ll pp, ll cc, ll ii)
    {
        p=pp, c=cc, iden=ii;
    }
};

bool cmp(node a, node b)
{
    bool e=a.p>b.p;
    e=(e || (a.p==b.p && a.c>b.c));
    return e;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    ll n, k, i, j, m, st, s, cur, x, id, ans[100005];
    node a[100005];
    cin >> n >> k;
    ffr(i,0,n)
    {
        cin >> a[i].p;
        a[i].iden=i;
    }
    ffr(i,0,n)
    {
        cin >> a[i].c;
    }
    sort(a,a+n,cmp);
    i=0;
    while(1)
    {
        //cout << "i " << i << endl;
        //i=st;
        if(i==n) break;
        cur=a[i].c;
        st=i;
        while(i<n && cur==a[i].c)
        {
            i++;
        }
        s=0;
        ffr(j,0,k)
        {
            id=i+j;
            if(id==n) break;
            s+=a[id].c;
        }
        ffr(m,st,i)
        {
            ans[a[m].iden]=s+cur;
        }
    }
    ffr(i,0,n)
    {
        cout << ans[i] << ' ';
    }
    return 0;
}
