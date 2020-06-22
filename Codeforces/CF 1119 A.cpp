#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)

using namespace std;

int main()
{
    ll n, i, a[300005], x, l, r, ans;
    while(cin >> n)
    {
        ffr(i,0,n)
        {
            cin >> x;
            a[i]=x;
        }
        l=0; r=n-1;

            while(l<r && a[l]==a[r])
            {
                l++;
            }
            ans=r-l;
            l=0; r-n-1;
            while(l<r && a[l]==a[r])
            {
                r--;
            }
            cout << max(r-l,ans) << endl;

    }
}
