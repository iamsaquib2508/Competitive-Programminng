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
        ll a, b, ans=0, div, rem;
        cin >> a >> b;
        if(b==a) ans=0;
        else if(b>a)
        {
            if(b%a==0)
            {
                div=b/a;
                while(div%2==0) {div/=2; ans++;}
                if(div==1)
                {
                    rem=ans-ans/3*3;
                    ans=ans/3+(rem>0);
                }
                else ans=-1;
            }
            else ans=-1;
        }
        else
        {
            if(a%b==0)
            {
                div=a/b;
                while(div%2==0) {div/=2; ans++;}
                if(div==1)
                {
                    rem=ans-ans/3*3;
                    ans=ans/3+(rem>0);
                }
                else ans=-1;
            }
            else ans=-1;
        }
        cout << ans << endl;
    }
}
