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
        ll n, m, x, y, ans, i, j;
        string s;
        cin >> n >> m >> x >> y;
        ans=0;
        if(x+x<=y)
        {
            ffr(i,0,n)
            {
                cin >> s;
                ffr(j,0,m)
                {
                    if(s[j]=='.') ans+=x;
                }
            }
        }
        else
        {
            ffr(i,0,n)
            {
                cin >> s;
                m--;
                ffr(j,0,m)
                {
                    if(s[j]=='.')
                    {
                        if(s[j+1]=='.') {ans+=y; j++;}
                        else ans+=x;
                    }
                }
                if(s[j]=='.') ans+=x;
                m++;
            }
        }
        cout << ans << endl;
    }
}
