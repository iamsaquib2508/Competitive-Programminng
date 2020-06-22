#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define pb push_back
#define pf printf
#define ll long long int
#define ff first
#define ss second
#define sf(a) scanf("%d", &a)
#define CMAX 30002

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

int arr[400005], pos[1000006];

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n, g, s, b, i, x;

        cin >> n;
        //cout << n << endl;
        ffr(i,0,n)
        {
            //cout << "H\n";
            cin >> x;
            arr[i+1]=x;
            pos[x]=i+1;
        }
        s=0; b=0;
        bool cant=0;
        if(n<5) cant=1;
        //cout << i << endl;
        for(i=n/2;i>0;i--)
        {
            if(arr[i]!=arr[i+1]) break;
        }
        //cout << n << endl;

        int lim=i;
        if(lim==0) cant=1;
        else
        {
            g=pos[arr[1]];
            if(3*g+2>lim) cant=1;
            else
            {
                s=pos[arr[g+g+1]]-g;
                if(lim-(g+s)<=g) cant=1;
                else b=lim-(g+s);
            }
        }

        if(!cant && 2*(g+s+b)<=n) cout << g << ' ' << s << ' ' << b << endl;
        else cout << "0 0 0\n";
    }
}
