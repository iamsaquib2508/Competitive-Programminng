#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int
#define mp make_pair

using namespace std;

int main()
{
    ll x, y;
    cin >> x;
    while(cin >> x >> y)
    {
        if(x==y+1) cout << "NO\n";
        else cout << "YES\n";
    }
}
