#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int

using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        int i;
        ll a[200005];
        ffr(i,0,n)
        {
            cin >> a[i];
        }
        ll lim=a[n-1], cur, ans=0;
        for(i=n-1;i>=0;i--)
        {
            cur=min(lim,a[i]);
            ans+=cur;

            if(cur>0)
            lim=cur-1;
            else lim=0;
        }
        cout << ans << endl;
    }
}
