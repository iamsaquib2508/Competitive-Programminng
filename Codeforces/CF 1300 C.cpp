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
    int n;
    while(cin >> n)
    {
        int ans, ansx, x, xx, i, cnt;
        vector<int> a; a.clear();

        ans=0;
        ffr(i,0,n)
        {
            cin >> x;
            a.pb(x);
        }
        sort(a.begin(),a.end());
        cout << a[a.size()-1];
        for(int i=0;i<n-1;i++)
        {
            {
                cout << ' ' << a[i];
            }
        }
        cout << endl;
    }
}
