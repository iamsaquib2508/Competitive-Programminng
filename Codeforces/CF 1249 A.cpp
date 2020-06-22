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

int main()
{
    int q, n, i, a[1100];
    cin >> q;
    while(q--)
    {
        cin >> n;
        ffr(i,0,n)
        {
            cin >> a[i];
        }
        sort(a,a+n);
        ffr(i,1,n)
        {
            if(a[i]==a[i-1]+1) break;
        }
        if(i==n) cout << "1\n";
        else cout << "2\n";
    }
}
