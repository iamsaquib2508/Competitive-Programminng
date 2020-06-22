#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int

using namespace std;

int main()
{
    ll n;
    while(cin >> n)
    {
        ll prev, l2, ans=0, i, x;
        ll arr[200005];
        ll done[200005];
        vector<ll> v;
        v.clear();
        mm(done,0);
        prev=0;
        ffr(i,1,n)
        {
            cin >> x;
            arr[i]=x;
            l2=prev+x;
            //cout << l2 << " l2\n";
            ans+=l2;
            prev=l2;
        }
        //cout << ans << "sum\n";
        ans=(n*(n+1)/2-ans);
        //cout << ans << "sum-ans\n";
        if(abs(ans)%n>0)
        {
            cout << "-1\n";
            continue;
        }
        ans/=n;
        if(ans<1 || ans>n)
        {
            cout << "-1\n";
            continue;
        }

        done[ans]=1;
        v.pb(ans);
        ffr(i,1,n)
        {
            ans+=arr[i];
            if(ans<1 || ans>n || done[ans]==1)
            {
                break;
            }
            done[ans]=1;
            v.pb(ans);
        }
        if(v.size()==n)
        {
            cout << v[0];
            ffr(i,1,n)
            {
                cout << ' ' << v[i];
            }
            cout << endl;
        }
        else cout << "-1\n";
    }
    return 0;
}
