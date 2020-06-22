#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int
#define mp make_pair

using namespace std;

ll maxx(ll a, ll b){if(a>b) return a; return b;}

int main()
{
    int ttt; cin >> ttt;
    while(ttt--)
    {
        ll n, i=0, t, a[200005];
        cin >> n;
        ffr(i,0,n)
        {
            cin >> a[i];
        }
        i=0;
        bool pos=(a[0]>0);
        ll ans=0, best;
        while(i<n)
        {
            if(pos)
            {
                best=0;
                while(i<n && a[i]>0) best=maxx(best,a[i++]);
                ans+=best; best=-1000000009;
                while(i<n && a[i]<0) best=maxx(best,a[i++]);
                ans+=best;
            }
            else
            {
                best=-1000000009;
                while(i<n && a[i]<0) best=maxx(best,a[i++]);
                ans+=best; best=0;
                while(i<n && a[i]>0) best=maxx(best,a[i++]);
                ans+=best;
            }
        }
        cout << ans << endl;
    }
}
