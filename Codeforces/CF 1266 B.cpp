#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define MMAX 200005

using namespace std;

int minn(int a, int b)
{
    if(a<b) return a; return b;
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
        ll i, x;
        cin >> x;
        ffr(i,1,7)
        {
            if((x-7+i)%14==0) { break;}
        }

        if(i==7 || x<15) cout << "NO\n";
        else
        {
            cout << "YES\n";
        }
    }
}
