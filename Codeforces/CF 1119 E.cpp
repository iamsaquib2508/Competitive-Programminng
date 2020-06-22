#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define mmxx 1e18

using namespace std;

int main()
{
    ll n;
    while(cin >> n)
    {
        ll ans=0;
        ll i, x, j;
        ll arr[300005];
        ffr(i,0,n)
        {
            cin >> x;
            ans+=(x/3);
            arr[i]=x%3;
        }
        i=0; j=n-1;
        while(i<j)
        {
            while(i<j && arr[j]<=1) j--;
            while(i<j && arr[i]==0) i++;
            if(i==j)
            {
                break;
            }
            else
            {ans++; j--; arr[i]--;}
        }
        cout << ans << endl;
    }
}
