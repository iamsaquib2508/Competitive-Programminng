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
    int n;
    while(cin >> n)
    {
        ll k, j, c, sum, i, ext, ans;
        ffr(j,0,n)
        {
            ans=0;
            cin >> c >> sum;
            k=sum/c;
            ext=sum%c;
            //acout << k << " k ext " << ext << endl;
            ffr(i,0,ext)
            {
                ans+=(k+1)*(k+1);
            }
            ffr(i,i,c)
            {
                ans+=k*k;
            }
            cout << ans << endl;
        }
    }
}
