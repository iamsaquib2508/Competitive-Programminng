#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int

using namespace std;

ll maxx(ll a, ll b)
{
    if(a>b) return a;
    return b;
}

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int main()
{
    ll n, i, z, x, y, sum, mx, t;
    ll a[200005];
    while(cin >> n)
    {
        if(0)
        {

        }
        else{

            mx=0;
            sum=0;

            ffr(i,0,n)
            {
                cin >> t;
                a[i]=t;
                mx=maxx(mx,t);
                sum+=t;

            }
            z=0;
            ffr(i,0,n)
            {
                z=gcd(abs(mx-a[i]),z);
            }
            y=(n*mx-sum)/z;
            //cout << mx << " x\n";
            cout << y << " " << z << endl;
        }
    }
}
