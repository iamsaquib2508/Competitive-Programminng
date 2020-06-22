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
        int n, i, s, k, ans, a[1024]={}, inp[1024];
        cin >> n;

        ffr(i,0,n)
        {
            cin >> s;
            //S.insert(s);
            inp[i]=s;
            a[s]=1;
        }
        if(n&1) ans=-1;
        else
        {
            ffr(k,1,1024)
            {
                ffr(i,0,n)
                {
                    if(a[inp[i]^k]==0) break;
                }
                if(i==n) break;
            }
            if(k==1024) ans=-1;
            else ans=k;
        }
        cout << ans << endl;
    }
}
