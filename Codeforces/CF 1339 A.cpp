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


ll minn(ll a, ll b)
{
    if(a>b) return b; return a;
}



int main()
{
    int tt; cin >> tt;
    while(tt--)
    {
        int n; cin >> n; cout << n << endl;
    }
}
