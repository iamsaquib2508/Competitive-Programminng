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

int n, i, a[200005], nn;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
     while(tt--)
    {

        cin >> n;
        nn=n+n;
        ffr(i,0,nn) cin >> a[i];
        sort(a,a+nn);
        cout << a[n]-a[n-1] << endl;
        //ffr(i,i,n)
    }
}
