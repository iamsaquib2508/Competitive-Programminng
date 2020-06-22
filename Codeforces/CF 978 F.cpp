#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define mx 200005

using namespace std;

class node
{
public:
    ll ff,ss;
    node(){}
    node(ll f, ll s)
    {
        ff=f, ss=s;
    }
};

bool cmp(node a, node b)
{
    return ((a.ff<b.ff) || ((a.ff==b.ff) && (a.ss<b.ss)) );
}

int main()
{
    ll n, k, i, cur, back, x, y, ans[mx]={};
    node a[mx];

    cin >> n >> k;
    ffr(i,0,n)
    {
        cin >> x;
        a[i]=node(x,i);
    }
    ffr(i,0,k)
    {
        cin >> x >> y;
        x--; y--;
        if((a[x].ff==a[y].ff) ) { continue;}
        if(a[x].ff>a[y].ff){x^=y; y^=x; x^=y;}
        ans[y]--;
    }
    sort(a,a+n,cmp);
    i=0ll;
    while(1)
    {
        if(i==n) break;
        cur=a[i].ff;
        back=i;
        while(i<n && a[i].ff==cur)
        {
            ans[a[i].ss]+=back; i++;
        }
    }
    ffr(i,0,n) cout << ans[i] << " ";
    //cout << "\n";
    //return main();
}
