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

int main()
{
    int n, c, i;
    int a[200005], b[200005];
    while(cin >> n >> c)
    {
        ffr(i,1,n)
        {
            cin >> a[i];
        }
        ffr(i,1,n)
        {
            cin >> b[i];
        }
        cout << "0";

        bool ls=0;
        int lcost=c;
        int ans=0;
        ffr(i,1,n)
        {
            if(ls)
            {
                if(a[i]<b[i])
                {
                    ans+=a[i]; ls=0;
                }
                else
                {
                    ans+=b[i]; ls=1;
                }
                lcost+=b[i];
                if(lcost>ans+c) lcost=ans+c;
            }
            else
            {
                if(ans+a[i]<lcost+b[i])
                {
                    ans+=a[i]; ls=0;
                }
                else
                {
                    ans=lcost+b[i]; ls=1;
                }
                lcost+=b[i];
                if(lcost>ans+c) lcost=ans+c;
            }
            cout << " " << ans;
        }
        cout << endl;
    }

}
