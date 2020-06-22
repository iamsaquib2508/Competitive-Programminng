#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define mmxx 1e18

using namespace std;

int gcd(int a, int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int minn(int a, int b)
{
    if(a<b) return a; return b;
}

int cel(int a, int b)
{
    return a/b+(a%b>0);
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n, d, sq, x=1;
        cin >> n >> d;
        sq=sqrt(d)+3;
        while(x<sq)
        {
            if(x+cel(d,x+1)<=n) break;
            x++;
        }
        if(x<sq || d<=n)
        {
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
}
