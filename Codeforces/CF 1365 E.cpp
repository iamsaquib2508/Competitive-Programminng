#include <bits/stdc++.h>
#define ll long long int
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define mp make_pair
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


ll maxx(ll a, ll b)
{
    if(a>b) return a; return b;
}

int main()
{
    int n;
    while(cin >> n)
    {
        ll a[500], ans=0, temp;
        int i, j, k;

        ffr(i,0,n) cin >> a[i];
        if(n<3)
        {
            ffr(i,0,n) ans|=a[i];
        }
        ffr(i,0,n)
        {
            ffr(j,i+1,n)
            {
                ffr(k,j+1,n)
                {
                    temp=a[i]|a[j]|a[k];
                    ans=maxx(temp,ans);
                }
            }
        }

        cout << ans << endl;
    }
}
