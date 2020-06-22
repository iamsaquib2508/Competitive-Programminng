#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)

using namespace std;

int main()
{
    ll n, k, lim, limc;
    vector<pii> a, b;
    while(cin >> n >> k)
    {
        lim=k*k-k;
        if(n>lim)
        {
            cout << "NO\n"; continue;
        }
        lim=n/2;
        limc=lim;
        int i, j;
        i=1; j=2;
        while(limc>0)
        {
            while(limc>0 && i<j)
            {
                a.pb(mp(i,j));
                i++;
                limc--;
            }
            j++; i=1;
        }
        limc=n-lim;
        i=2; j=1;
        while(limc>0)
        {
            while(limc>0 && i>j)
            {
                b.pb(mp(i,j));
                j++;
                limc--;
            }
            i++; j=1;
        }
        pii cur;
        cout << "YES\n";
        ffr(i,0,lim)
        {
            cur=b[i];
            cout << cur.first << ' ' << cur.second << endl;
            cur=a[i];
            cout << cur.first << ' ' << cur.second << endl;
        }
        if(n&1)
        {
            cur=b[i];
            cout << cur.first << ' ' << cur.second << endl;
        }
        a.clear(); b.clear();
    }
    return 0;
}
