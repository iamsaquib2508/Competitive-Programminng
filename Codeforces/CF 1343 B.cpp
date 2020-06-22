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
    int ttt; cin >> ttt;
    while(ttt--)
    {
        ll n, t, i;
        cin >> n;
        n/=2;
        if(n&1) {cout << "NO\n"; continue;}
        t=2;
        cout << "YES\n";
        ffr(i,0,n)
        {
            cout << t << ' '; t+=2;
        }
        t=1;
        ffr(i,1,n)
        {
            cout << t << ' '; t+=2;
        }
        cout << t+n << endl;
//        cout << n/t << endl;
    }
}
