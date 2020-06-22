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
        int n, prev, i, x;
        cin >> n;
        cin >> prev;
        bool ans=0;
        ffr(i,1,n)
        {
            cin >> x;
            if(!ans && abs(x-prev)>1)
            {
                cout << "YES\n" << i << ' ' << i+1 << endl;
                ans=1;
            }
            prev=x;
        }
        if(!ans) cout << "NO\n";
    }
}
