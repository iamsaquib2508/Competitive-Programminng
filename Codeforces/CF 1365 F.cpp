#include <bits/stdc++.h>
#define ll long long int
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define mp make_pair
using namespace std;

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int minn(int a, int b)
{
    if(a<b) return a; return b;
}


int maxx(int a, int b)
{
    if(a>b) return a; return b;
}

int main()
{
    int tt; cin >> tt;
    while(tt--)
    {
        int n, fl, i, a[600], b[600];
        map< pii , int> mpp; mpp.clear();
        pii p;
        cin >> n;
        fl=n/2;
        ffr(i,0,n)
        {
            cin >> a[i];
        }
        ffr(i,0,n)
        {
            cin >> b[i];
            p=mp(maxx(a[i],a[n-1-i]),minn(a[i],a[n-1-i]));
            if(i<fl) mpp[p]++;
        }
        if(n&1)
        {
            if(a[fl]!=b[fl])
            {
                cout << "No\n"; continue;
            }
        }
        ffr(i,0,fl)
        {
            p=mp(maxx(b[i],b[n-1-i]),minn(b[i],b[n-1-i]));
            if(mpp.find(p)==mpp.end() || mpp[p]==0 )
                break;
            else mpp[p]--;
        }
        if(i==fl)
            cout << "Yes\n";
        else cout << "No\n";
    }
}
