#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back

using namespace std;

vector<int> a;
int n;
ll m;

bool ok(int k)
{
    ll sum=0ll; int i;
    ffr(i,0,n)
    {
        sum+=max(a[i]-i/k,0);
        if(sum>=m) return true;
    }
    return false;
}

int main()
{

    while(cin >> n >> m)
    {
        ll sum=0;
        int x, i;
        a.clear();
        ffr(i,0,n)
        {
            cin >> x;
            sum+=x;
            a.pb(x);
        }
        if(sum<m)
        {cout << "-1\n"; continue;}

        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());

        int mid, lo=1, hi=n;
        int ans;
        while(hi-lo>1)
        {
            mid=(hi+lo)/2;
            if(ok(mid))
            {
                hi=mid;
            }
            else lo=mid;
        }
        //cout << lo << " lo hi " << hi << endl;
        if(ok(lo)) ans=lo;
        else if(ok(lo+1)) ans=lo+1;
        else ans=lo+2;
        cout << ans << endl;
    }
    a.clear();
    return 0;
}
