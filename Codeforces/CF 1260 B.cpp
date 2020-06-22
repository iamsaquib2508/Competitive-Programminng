#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int
#define pf printf
#define PI acos(-1.0)

using namespace std;

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

ll minn(ll a, ll b)
{
    if(a<b) return a; return b;
}

int maxx(int a, int b)
{
    if(a>b) return a; return b;
}

int main()
{
    ll t, a, b;
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        if(a==b)
        {
            if(a%3==0) cout << "YES\n";
            else cout << "NO\n";
        }
        else
        {
            if(a>b){int temp=a; a=b; b=temp;}
            if(b<=a+a)
            {
                if((a+b)%3==0) cout << "YES\n";
                else cout << "NO\n";
            }
            else cout << "NO\n";
        }

    }
}
