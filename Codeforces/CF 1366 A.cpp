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

ll minn(ll a, ll b)
{
    if(a<b) return a; return b;
}

int main()
{
    int tt; cin >> tt;
    while(tt--)
    {
        ll a, b, ans, diff, got, t, minnn;
        cin >> a >> b;
        if(b>a)
        {
            t=a; a=b; b=t;
        }
        diff=a-b;
        minnn=minn(b,diff);
        a-=(minnn+minnn);
        b-=minnn;
        ans=minnn;
        got=b/3;
        ans+=(got+got);
        b-=(got*3);
        if(b==2) ans++;
        cout << ans << endl;
    }
}
