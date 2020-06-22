#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pii pair<int,int>
#define plolo pair<ll,ll>
#define mp(a,b) make_pair(a,b)
#define mmxx 1000000

using namespace std;

int main()
{
    int n, m, r, x, mn, cur, i;
    vector<int> a, b;
    while(cin >> n >> m >> r)
    {
        a.clear(); b.clear();
        ffr(i,0,n) {cin >> x; a.pb(x);}
        ffr(i,0,m) {cin >> x; b.pb(x);}

        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        reverse(b.begin(),b.end());

        mn=(m<n)? m:n;
        ffr(i,0,mn)
        {
            cur=b[i]-a[i];
            if(cur<0) break;
            int doo=r/a[i];
            r+= doo*cur;
            break;
        }
        cout << r << endl;
    }
}
