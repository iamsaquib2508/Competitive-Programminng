#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int

using namespace std;

int main()
{
    int n, k;
    while(cin >> n >> k)
    {
        int a[102], i, ans=0, x;
        mm(a,0);
        ffr(i,0,n)
        {
            cin >> x;
            a[x%k]++;
        }
        if(k==1)
        {

        }
        ffr(i,1,k)
        {
            if(i+i>=k) break;
            ans+=min(a[i],a[k-i]);
        }
        ans+=ans;
        ans+=(a[0]-(a[0]&1));
        if(i+i==k) ans+=(a[i]-(a[i]&1));
        cout << ans << endl;
    }
}
