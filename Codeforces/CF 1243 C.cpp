#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
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
    ll n, ans, cur;
    while(cin >> n)
    {
        bool got=0;
        if(n&1)
        {
            //odd
            if(n==1) ans=1;
            else
            {
                cur=3;
                while(cur<1000006)
                {
                    if( (n%cur)==0 )
                    {
                        while( (n%cur)==0 )
                        {
                            n/=cur;
                        }
                        if(n==1) ans=cur;
                        else ans=1;
                        got=1;
                        break;

                    }
                    else cur+=2;
                }
                if(!got) ans=n;

            }

        }
        else
        {
            while( (n%2)==0 ) n/=2;
            if(n==1) ans=2;
            else ans=1;
        }
        cout << ans << endl;
    }
}
