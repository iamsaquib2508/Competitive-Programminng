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
    int tt=1;
    while(tt--)
    {
        int n, a, b, k, x, apb, temp, rem, i, ans=0;
        vector<int> v; v.clear();

        cin >> n >> a >> b >> k;
        apb=a+b;
        ffr(i,0,n)
        {
            cin >> x;
            rem=x%apb;
            if(rem==0) rem=apb;
            //cout << rem << ' ';
            if(rem<=a) ans++;
            else v.pb(rem-a);
        }
        sort(v.begin(),v.end());
        for(int j: v)
        {
            //cout << j << ' ';
            temp=(j-1)/a+1;
            if(temp<=k){k-=temp; ans++;}
        }
        //cout << endl;
        cout << ans << endl;
    }
}
