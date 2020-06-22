#include <bits/stdc++.h>
#define ll int64_t
#define uint uint32_t
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define plolo pair<ull,ull>
#define xx first
#define yy second
#define mp make_pair

using namespace std;

ll maxx(ll a, ll b)
{
    if(a>b) return a; return b;
}

ll minn(ll a, ll b)
{
    if(a<b) return a; return b;
}

int main()
{
    int tt; cin >> tt;
    while(tt--)
    {
        ll n, x, m, ml, mr, l, r, j;
        cin >> n >> x >> m;
        ml=x; mr=x;
        ffr(j,0,m)
        {
            cin >> l >> r;
            if(ml<=l && l<=mr)
            {
                mr=maxx(mr,r);
            }
            else if(ml<=r && r<=mr)
            {
                ml=minn(ml,l);
            }
            else if(l<=ml && mr<=r)
            {
                ml=l; mr=r;
            }
        }
        cout << mr-ml+1 << endl;
    }
}
