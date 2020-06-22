#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int
#define mp make_pair

using namespace std;

ll maxx(ll a, ll b)
{
    if(a>b) return a; return b;
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
        ll n, i, x, s=0, tsum=0, tans=0, a[100005];
        cin >> n;
        bool d=1;
        ffr(i,0,n)
        {
            cin >> x; a[i]=x;
            s+=x;
            tsum+=x;
            //if(s==0) d=1;
            if(tsum<=0) {tsum=0; d=0;}
            //mini=minn(x,mini);
            tans=maxx(tans,tsum);
        }
        tsum=0;
        ffr(i,0,n)
        {
            x=a[n-1-i];
            tsum+=x;
            //if(s==0) d=1;
            if(tsum<=0) {tsum=0; d=0; break;}

        }
        //tans-=mini;
        //cout << tans;
        if(tans>s || (tans==s && d==0)) cout << "NO\n";
        else cout << "YES\n";
    }
}
