#include <bits/stdc++.h>
#define ll long long int
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
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
        int n, x, i, u, v, total, im=0;
        cin >> n >> x;
        ffr(i,1,n)
        {
            cin >> u >> v;
            if(u==x || v==x) im++;
        }
        //cout << im << ' ' << total << endl;
        total=n-2;
        string ans="Ashish\n";
        if( im<=1 ) ans="Ayush\n";
        else if( (total&1) == 0 ) ans= "Ayush\n";
        cout << ans;

    }
}
