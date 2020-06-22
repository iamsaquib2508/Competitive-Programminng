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

int i, n, x, a[200005], cnt, ans, temp;

int main()
{

    while(cin >> n)
    {
        map<int,int> mpp; mpp.clear();
        ffr(i,0,n)
        {
            cin >> x;
            a[x]=i;
        }
        ffr(i,0,n)
        {
            cin >> x;
            temp = i-a[x];
            if(temp<0) temp+=n;
            mpp[temp]++;
        }

        ans=0;
        for(auto aa:mpp)
        {
            ans=maxx(ans,aa.second);
        }
        cout << ans << endl;
    }
}
