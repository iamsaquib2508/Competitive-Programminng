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
        int n, m, k, maxp, maxp2, rem;
        cin >> n >> m >> k;
        maxp=minn(n/k,m);
        rem=m-maxp;
        maxp2=(rem/(k-1));
        if(rem%(k-1)) maxp2++;
        cout << maxp-maxp2 << endl;
    }
}
