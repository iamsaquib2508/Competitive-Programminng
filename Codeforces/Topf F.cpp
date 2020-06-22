#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define mmxx 1e18

using namespace std;

int main()
{
    ll n, x, i, done;
    ll a[10005];
    while(cin >> n >> x)
    {
        ffr(i,0,n) cin >> a[i];
        sort(a,a+n);
        ll ind, cnt=0, lim;
        ind=0; done=0;
        while(ind<n)
        {
            done=max(x+done,a[ind]);
            while(ind<n && a[ind]<=done) ind++;
            cnt++;
            //cout << done << " done ind " << ind << endl;
        }
        cout << cnt << endl;
    }
}
