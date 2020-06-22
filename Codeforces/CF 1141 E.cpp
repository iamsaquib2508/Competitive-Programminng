#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int

using namespace std;

int main()
{
    ll i, n, x, H;
    ll arr[200005];
    while(cin >> H >> n)
    {
        ll prev=0;
        bool got=0;
        ffr(i,0,n)
        {
            cin >> x;
            prev+=x;
            if(!got && prev<=-H)
            {
                cout << i+1 << endl;
                got=1;
            }
            arr[i]=prev;
        }
        if(got)
        {
            continue;
        }
        ll sum=prev;
        //cout << sum << endl;
        if(sum>=0)
        {
            cout << "-1\n"; continue;
        }
        ll ans=1e18;
        ffr(i,0,n)
        {
            if(arr[i]<0)
            {
                ll temp=H+arr[i];
                temp=(ceil(-1.0*temp/sum));
                ans=min(ans,i+1+temp*n);
            }
        }
        cout << ans << endl;
    }
}
