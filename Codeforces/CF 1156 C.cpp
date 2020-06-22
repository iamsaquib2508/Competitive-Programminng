#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pii pair<int,int>
#define plolo pair<ll,ll>
#define mp(a,b) make_pair(a,b)
#define mmxx 1000000

using namespace std;

int main()
{
    ll n, d, i, j, ans, l;
    ll a[200005];
    bool taken[200005];
    while(cin >> n >> d)
    {
        ans=0;

        ffr(i,0,n) cin >> a[i];
        mm(taken,0);
        sort(a,a+n);
        i=0; j=1;
        while(1)
        {
            while(i<n && taken[i]) i++;
            if(i==n) break;
            if(i==j) j++;
            l=a[i];
            while(j<n && a[j]<l+d)
            {
                j++;
            }
            if(j>=n) break;
            taken[i]=1; taken[j]=1;
            ans++; i++; j++;
        }
        cout << ans << endl;
    }
}
