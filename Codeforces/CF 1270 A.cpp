#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define MMAX 200005
#define so(x) cerr << #x << " = " << x << endl

using namespace std;

int maxx(int a, int b)
{
    if(a>b) return a; return b;
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n, k1, k2, a, i;
        bool ans=0;
        cin >> n >> k1 >> k2;
        ffr(i,0,k1)
        {
            cin >> a;
            if(a==n) ans=1;
        }
        ffr(i,0,k2)
        {
            cin >> a;
        }
        if(ans==1) cout << "YES\n";
        else cout << "NO\n";
    }
}
