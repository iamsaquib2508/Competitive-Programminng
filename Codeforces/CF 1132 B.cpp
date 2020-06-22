#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int

using namespace std;

bool cmp(ll a, ll b)
{
    return a>b;
}

int main()
{
    int i, n, m, in;
    while(cin >> n)
    {
        ll a[300005];
        ll sum=0;
        ffr(i,0,n)
        {
            cin >> a[i];
            sum+=a[i];
        }
        sort(a,a+n,cmp);
        //cout << sum << " sum\n";
        cin >> m;
        ffr(i,0,m)
        {
            cin >> in;
            in--;
            cout << sum-a[in] << endl;
        }
    }
    return  0;
}
